// Alvarez, Joshua Caleb P.
#include <iostream>

// Global Declaration
int a, b;

// Function Declaration
int NumResult(int a, int b);

int main() {

    std::cout << "Enter First Number: ";
    std::cin >> a;

    std::cout << "Enter Second Number: ";
    std::cin >> b;

    NumResult(a, b);

    return 0;
}

int NumResult(int a, int b) {

    if (a > b) {
        std::cout << "The Number " << a << " is greater than " << b << std::endl;
    }
    else if (a < b) {
        std::cout << "The Number " << a << " is less than " << b << std::endl;
    }
    else {
        std::cout << "Both numbers are equal." << std::endl;
    }

    return 0;
}
