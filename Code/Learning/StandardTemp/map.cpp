#include <iostream>
#include <map>
#include <string>

int main() {
    // Store model metrics by name
    std::map<std::string, double> metrics;

    metrics["accuracy"] = 0.94;
    metrics["loss"]      = 0.12;
    metrics["f1_score"]  = 0.91;

    for (auto& pair : metrics) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}