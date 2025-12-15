#include <iostream>
#include "calculator.hpp"

int main() {
    double a, b;
    char op;

    std::cout << "Enter expression (e.g. 3 + 4): ";
    std::cin >> a >> op >> b;

    try {
        double result;
        switch (op) {
            case '+': result = add(a, b); break;
            case '-': result = subtract(a, b); break;
            case '*': result = multiply(a, b); break;
            case '/': result = divide(a, b); break;
            default: throw std::runtime_error("Unknown operator");
        }
        std::cout << "Result: " << result << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}