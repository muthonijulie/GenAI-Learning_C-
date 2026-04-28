#include <iostream>
#include <vector>

int main() {
    // Simulating a batch of AI model confidence scores
    std::vector<double> confidenceScores = {0.95, 0.42, 0.88, 0.31, 0.76};

    std::cout << "Processing batch predictions..." << std::endl;
// Using a for loop to evaluate each confidence score
    for (int i = 0; i < confidenceScores.size(); i++) {
        if (confidenceScores[i] >= 0.75) {
            std::cout << "Sample " << i + 1 << ": ACCEPTED (score: "
                      << confidenceScores[i] << ")" << std::endl;
        } else {
            std::cout << "Sample " << i + 1 << ": REJECTED (score: "
                      << confidenceScores[i] << ")" << std::endl;
        }
    }

    return 0;
}