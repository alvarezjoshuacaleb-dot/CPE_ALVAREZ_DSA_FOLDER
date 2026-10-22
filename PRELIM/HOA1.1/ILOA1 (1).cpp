// Alvarez, Joshua Caleb P.
#include <iostream>

// Global Declaration
int a, b;

// Function Declaration
int TwoSumNum(int a, int b);

int main() {

    std::cout << "Enter First Number: ";
    std::cin >> a;

    std::cout << "Enter Second Number: ";
    std::cin >> b;

    int total = TwoSumNum(a, b);

    std::cout << "The Sum is: " << total << std::endl;

    return 0;
}

int TwoSumNum(int a, int b) {
    return a + b;
}