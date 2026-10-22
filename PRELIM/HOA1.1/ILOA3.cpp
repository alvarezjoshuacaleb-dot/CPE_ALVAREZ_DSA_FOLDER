// Alvarez, Joshua Caleb P.
#include <iostream>

// Function Declaration
bool LogicalOperations(bool a, bool b);

int main() {

    bool a, b;

    std::cout << "Enter first Boolean value (0 or 1): ";
    std::cin >> a;

    std::cout << "Enter second Boolean value (0 or 1): ";
    std::cin >> b;

    if (LogicalOperations(a, b)) {
        std::cout << "Logical operations executed successfully." << std::endl;
    }

    return 0;
}

bool LogicalOperations(bool a, bool b) {

    std::cout << "\nAND: " << (a && b) << std::endl;
    std::cout << "OR : " << (a || b) << std::endl;
    std::cout << "NOT A: " << (!a) << std::endl;
    std::cout << "NOT B: " << (!b) << std::endl;

    return true;
}