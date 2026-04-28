#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

// BASE CLASS - defines the interface every layer must have
class Layer {
protected:
    std::string layerName;

public:
    Layer(std::string name) : layerName(name) {
        std::cout << layerName << " layer initialized." << std::endl;
    }

    // Virtual - allows child classes to override this method
    virtual double forward(const std::vector<double>& inputs,
                          const std::vector<double>& weights,
                          double bias) = 0; // = 0 means must be implemented

    virtual ~Layer() {
        std::cout << layerName << " layer destroyed." << std::endl;
    }
};

// CHILD CLASS 1 - ReLU activation layer
class ReLULayer : public Layer {
public:
    ReLULayer() : Layer("ReLU") {}

    double forward(const std::vector<double>& inputs,
                  const std::vector<double>& weights,
                  double bias) override {
        double weightedSum = std::inner_product(
            inputs.begin(), inputs.end(), weights.begin(), 0.0
        );
        double result = weightedSum + bias;
        // ReLU - returns 0 if negative
        return result > 0 ? result : 0;
    }
};

// CHILD CLASS 2 - Sigmoid activation layer
class SigmoidLayer : public Layer {
public:
    SigmoidLayer() : Layer("Sigmoid") {}

    double forward(const std::vector<double>& inputs,
                  const std::vector<double>& weights,
                  double bias) override {
        double weightedSum = std::inner_product(
            inputs.begin(), inputs.end(), weights.begin(), 0.0
        );
        double result = weightedSum + bias;
        // Sigmoid - squashes output between 0 and 1
        return 1.0 / (1.0 + std::exp(-result));
    }
};

int main() {
    std::vector<double> inputs  = {0.5, 0.3, 0.9};
    std::vector<double> weights = {0.4, 0.7, 0.2};
    double bias = 0.1;

    // Both layers share the same interface
    // but behave differently internally
    ReLULayer relu;
    SigmoidLayer sigmoid;

    std::cout << "\nReLU output:    "
              << relu.forward(inputs, weights, bias) << std::endl;
    std::cout << "Sigmoid output: "
              << sigmoid.forward(inputs, weights, bias) << std::endl;

    return 0;
}