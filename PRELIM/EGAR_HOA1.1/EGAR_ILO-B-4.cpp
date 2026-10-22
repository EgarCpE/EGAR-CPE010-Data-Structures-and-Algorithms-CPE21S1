#include <iostream>

class Triangle {
    private:
        double totalAngle, angleA, angleB, angleC;

    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        bool ValidateTriangle() const;
};

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = angleA + angleB + angleC;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = angleA + angleB + angleC;
}

bool Triangle::ValidateTriangle() const {
    return totalAngle == 180;
}

int main() {
    Triangle set1(40, 30, 110);
    if (set1.ValidateTriangle()) {
        std::cout << "The triangle is valid." << std::endl;
    } else {
        std::cout << "The triangle is not valid." << std::endl;
    }
    return 0;
}
