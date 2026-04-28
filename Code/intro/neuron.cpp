// #include <iostream>
// #include <vector>
// #include <numeric>

// double relu(double value){
//     return value>0?value:0;//returns 0 if value equals 0 or negative and value if greater than 0
// }
// //in this case focus is on neuron which consist of input, output and weights
// double neuron(const std::vector<double>& inputs,
// //calculate the weighted sum
// const std:: vector<double>& weights,
// double bias){
//     double weightedSum=std::inner_product(
//         inputs.begin(),inputs.end(),weights.begin(),0.0);
//     //add bias
//     weightedSum+=bias;
//     //Apply RELU to the weighted sum
//     return relu(weightedSum);

// }
// int main(){
//     //examples
//     std::vector<double> inputs={0.5,0.3,0.9};
//     std::vector<double> weights={0.2,0.4,0.6};
//     double bias=0.1;
//     double output=neuron(inputs,weights,bias);
//     std::cout<<"Output of the neuron: "<<output<<std::endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <cmath>



// ReLU: returns 0 for negative values, value otherwise
// Used in hidden layers of most modern neural networks
double relu(double value) {
    return value > 0 ? value : 0;
}

// Sigmoid: squashes output between 0 and 1
// Used in the output layer for binary classification
double sigmoid(double value) {
    return 1.0 / (1.0 + std::exp(-value));
}


// NEURON
// Core building block — computes weighted sum + bias + activation

double neuron(const std::vector<double>& inputs,
              const std::vector<double>& weights,
              double bias,
              std::string activation = "relu") {

    // Step 1: Weighted sum of inputs
    double weightedSum = std::inner_product(
        inputs.begin(), inputs.end(), weights.begin(), 0.0
    );

    // Step 2: Add bias
    weightedSum += bias;

    // Step 3: Apply activation function
    if (activation == "sigmoid") return sigmoid(weightedSum);
    return relu(weightedSum);
}

// NEURAL NETWORK CLASS
// Wraps two neurons: one hidden, one output
// Simulates a minimal forward pass

class NeuralNetwork {
private:
    // Hidden neuron weights & bias
    std::vector<double> hiddenWeights;
    double hiddenBias;

    // Output neuron weights & bias
    std::vector<double> outputWeights;
    double outputBias;

public:
    // Constructor: initialise both layers
    NeuralNetwork(std::vector<double> hw, double hb,
                  std::vector<double> ow, double ob)
        : hiddenWeights(hw), hiddenBias(hb),
          outputWeights(ow), outputBias(ob) {
        std::cout << "Neural network initialised." << std::endl;
    }

    // Forward pass: input -> hidden layer -> output layer
    double forward(const std::vector<double>& inputs) {

        // Hidden layer uses ReLU
        double hiddenOutput = neuron(inputs, hiddenWeights, hiddenBias, "relu");

        std::cout << "Hidden neuron output (ReLU):   " << hiddenOutput << std::endl;

        // Output layer takes hidden output as its input, uses Sigmoid
        double finalOutput = neuron({hiddenOutput}, outputWeights, outputBias, "sigmoid");

        std::cout << "Output neuron output (Sigmoid): " << finalOutput << std::endl;

        return finalOutput;
    }

    // Interprets the final output as a classification decision
    void predict(const std::vector<double>& inputs) {
        std::cout << "\n--- Running Inference ---" << std::endl;
        double result = forward(inputs);

        std::cout << "\nFinal prediction score: " << result << std::endl;

        if (result >= 0.5) {
            std::cout << "Decision: POSITIVE (confidence: "
                      << result * 100 << "%)" << std::endl;
        } else {
            std::cout << "Decision: NEGATIVE (confidence: "
                      << (1.0 - result) * 100 << "%)" << std::endl;
        }
    }

    ~NeuralNetwork() {
        std::cout << "\nNeural network destroyed." << std::endl;
    }
};


int main() {
    // Input: 3 features (e.g. normalised sensor readings or data points)
    std::vector<double> inputs = {0.5, 0.3, 0.9};

    // Hidden neuron: 3 weights (one per input)
    std::vector<double> hiddenWeights = {0.2, 0.4, 0.6};
    double hiddenBias = 0.1;

    // Output neuron: 1 weight (takes hidden output)
    std::vector<double> outputWeights = {0.8};
    double outputBias = -0.2;

    // Build and run the network
    NeuralNetwork nn(hiddenWeights, hiddenBias, outputWeights, outputBias);
    nn.predict(inputs);

    return 0;
}