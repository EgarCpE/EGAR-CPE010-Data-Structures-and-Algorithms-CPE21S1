#include <iostream>
#include <cmath>
#include <string> 

class Triangle {
    private:
        double totalAngle, angleA, angleB, angleC, sideA, sideB, sideC; 

    public:
        Triangle(double A, double B, double C, double sdA = 0, double sdB = 0, double sdC = 0);
        void setAngles(double A, double B, double C);
        void setsides(double sA, double sB, double sC);
        bool ValidateTriangle() const;

        // question 4
        double computeTheArea() const;      
        double computeThePerimeter() const; 
        std::string determineTheType() const;
};

Triangle::Triangle(double A, double B, double C, double sdA, double sdB, double sdC) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = angleA + angleB + angleC;

    sideA = sdA;
    sideB = sdB;
    sideC = sdC;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = angleA + angleB + angleC;
}


void Triangle::setsides(double sA, double sB, double sC) {
    sideA = sA;
    sideB = sB;
    sideC = sC;
}

bool Triangle::ValidateTriangle() const {
    return totalAngle == 180;
}

// question 4.a
double Triangle::computeTheArea() const {
    double s = computeThePerimeter() / 2;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

// question 4.b
double Triangle::computeThePerimeter() const {
    return sideA + sideB + sideC;
}

// question 4.c
std::string Triangle::determineTheType() const {
    if (angleA < 90 && angleB < 90 && angleC < 90) {
        return "acute-angled";
    }
    else if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "obtuse-angled";
    }
    else {
        return "others";
    }
}

int main() {
    
    Triangle set1(40, 30, 110, 7.0, 5.5, 10.2);
    
    if (set1.ValidateTriangle()) {
        std::cout << "The triangle is valid." << std::endl;
        
      
        std::cout << "Area: " << set1.computeTheArea() << std::endl;
        std::cout << "Perimeter: " << set1.computeThePerimeter() << std::endl;
        std::cout << "Type: " << set1.determineTheType() << std::endl;
        
    } else {
        std::cout << "The triangle is not valid." << std::endl;
    }
    return 0;
}