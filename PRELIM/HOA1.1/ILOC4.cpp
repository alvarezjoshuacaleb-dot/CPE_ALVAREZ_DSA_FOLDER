#include <iostream>
#include <cmath>

bool isValidTriangle(double a, double b, double c) {

    return (a + b > c &&
            a + c > b &&
            b + c > a);
}

double perimeter(double a, double b, double c) {

    return a + b + c;
}

double area(double a, double b, double c) {

    double s = perimeter(a, b, c) / 2;

    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

void triangleType(double a, double b, double c) {

    double largest = a;

    if (b > largest)
        largest = b;

    if (c > largest)
        largest = c;

    double largestSquared = largest * largest;
    double sumSquares;

    if (largest == a)
        sumSquares = b * b + c * c;
    else if (largest == b)
        sumSquares = a * a + c * c;
    else
        sumSquares = a * a + b * b;

    if (largestSquared < sumSquares)
        std::cout << "Acute Triangle";
    else if (largestSquared > sumSquares)
        std::cout << "Obtuse Triangle";
    else
        std::cout << "Others";
}

int main() {

    double a, b, c;

    std::cout << "Enter Side A: ";
    std::cin >> a;

    std::cout << "Enter Side B: ";
    std::cin >> b;

    std::cout << "Enter Side C: ";
    std::cin >> c;

    if (isValidTriangle(a, b, c)) {

        std::cout << "\nValid Triangle" << std::endl;
        std::cout << "Perimeter: " << perimeter(a, b, c) << std::endl;
        std::cout << "Area: " << area(a, b, c) << std::endl;

        std::cout << "Type: ";
        triangleType(a, b, c);
        std::cout << std::endl;

    }
    else {

        std::cout << "\nInvalid Triangle" << std::endl;

    }

    return 0;
}