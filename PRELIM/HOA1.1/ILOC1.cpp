#include <iostream>

void swapNumbers(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

int main() {

    int num1, num2;

    std::cout << "Enter First Number: ";
    std::cin >> num1;

    std::cout << "Enter Second Number: ";
    std::cin >> num2;

    swapNumbers(num1, num2);

    std::cout << "\nAfter Swapping\n";
    std::cout << "First Number: " << num1 << std::endl;
    std::cout << "Second Number: " << num2 << std::endl;

    return 0;
}