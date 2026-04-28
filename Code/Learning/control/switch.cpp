#include <iostream>
#include <string>

int main() {
    int statusCode = 2;

    // Simulating a backend API response handler
    switch (statusCode) {
        case 1:
            std::cout << "Status: Model training in progress..." << std::endl;
            break;
        case 2:
            std::cout << "Status: Model ready for inference." << std::endl;
            break;
        case 3:
            std::cout << "Status: Model failed. Check logs." << std::endl;
            break;
        default:
            std::cout << "Status: Unknown state." << std::endl;
    }

    return 0;
}