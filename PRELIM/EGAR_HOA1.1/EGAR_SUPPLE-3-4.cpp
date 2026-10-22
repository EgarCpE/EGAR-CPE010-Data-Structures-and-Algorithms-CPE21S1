#include <iostream>
#include <cmath>

double a1, b1, a2, b2;
double distance;

int main() {

    std::cout << "Input coordinates x1: ";
    std::cin >> a1;
    std::cout << "Input coordinates y1: ";
    std::cin >> b1;
    std::cout << "Input coordinates x2: ";
    std::cin >> a2;
    std::cout << "Input coordinates y2: ";
    std::cin >> b2;

    distance = sqrt(pow(a2 - a1, 2) + pow(b2 - b1, 2));
    std::cout << "Distance between the points: " << distance << std::endl;

    return 0;
}