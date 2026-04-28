#include <iostream>
#include <vector>
#include <numeric>

class Model {
private:
    std::vector<double> weights;
    double bias;
    double learningRate;
    int epochsRun;

    double relu(double value) {
        return value > 0 ? value : 0;
    }

public:
    // Constructor
    Model(std::vector<double> w, double b, double lr)
        : weights(w), bias(b), learningRate(lr), epochsRun(0) {
        std::cout << "Model initialized." << std::endl;
    }

    // Forward pass
    double forward(const std::vector<double>& inputs) {
        double weightedSum = std::inner_product(
            inputs.begin(), inputs.end(), weights.begin(), 0.0
        );
        return relu(weightedSum + bias);
    }

    // Simulate one training step
    void train(const std::vector<double>& inputs, double target) {
        double prediction = forward(inputs);
        double loss = target - prediction;

        // Nudge weights in the right direction
        for (int i = 0; i < weights.size(); i++) {
            weights[i] += learningRate * loss * inputs[i];
        }
        bias += learningRate * loss;
        epochsRun++;

        std::cout << "Epoch " << epochsRun
                  << " | Loss: " << loss
                  << " | Prediction: " << prediction << std::endl;
    }

    // Public getter - controlled access
    int getEpochsRun() { return epochsRun; }
};

int main() {
    Model model({0.4, 0.7, 0.2}, 0.1, 0.01);

    std::vector<double> inputs = {0.5, 0.3, 0.9};
    double target = 1.0;

    // Run 5 training steps
    for (int i = 0; i < 5; i++) {
        model.train(inputs, target);
    }

    std::cout << "\nTotal epochs run: "
              << model.getEpochsRun() << std::endl;

    return 0;
}