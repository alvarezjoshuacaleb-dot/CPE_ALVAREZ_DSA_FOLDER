// Alvarez, Joshua Caleb P.
#include <iostream>

class Triangle {

private:
    double totalAngle;
    double angleA;
    double angleB;
    double angleC;

public:
    // Constructor
    Triangle(double A, double B, double C);

    // Setter Function
    void setAngles(double A, double B, double C);

    // Validation Function
    const bool validateTriangle();
};

// Constructor Definition
Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

// Setter Definition
void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

// Validation Function Definition
const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}

// Driver Code
int main() {

    Triangle set1(40, 30, 110);

    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle." << std::endl;
    }
    else {
        std::cout << "The shape is NOT a valid triangle." << std::endl;
    }

    return 0;
}
