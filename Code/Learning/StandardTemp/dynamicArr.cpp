#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Dynamic array - resizes automatically
    std::vector<double> losses = {0.9, 0.75, 0.6, 0.45, 0.2};

    // Iterate
    for (double loss : losses) {
        std::cout << "Loss: " << loss << std::endl;
    }

    // Add new value
    losses.push_back(0.1);
    std::cout << "Latest loss: " << losses.back() << std::endl;

    // Find minimum loss
    auto minLoss = std::min_element(losses.begin(), losses.end());
    std::cout << "Best loss: " << *minLoss << std::endl;

    return 0;
}