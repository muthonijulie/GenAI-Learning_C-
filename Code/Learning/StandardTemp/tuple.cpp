#include <iostream>
#include <vector>
#include <tuple>

int main() {
    // Store epoch, loss, accuracy together
    std::vector<std::tuple<int, double, double>> trainingLog;

    trainingLog.push_back({1, 0.85, 0.72});
    trainingLog.push_back({2, 0.61, 0.84});
    trainingLog.push_back({3, 0.34, 0.93});

    for (auto& record : trainingLog) {
        std::cout << "Epoch: "    << std::get<0>(record)
                  << " | Loss: "  << std::get<1>(record)
                  << " | Acc: "   << std::get<2>(record) << std::endl;
    }

    return 0;
}