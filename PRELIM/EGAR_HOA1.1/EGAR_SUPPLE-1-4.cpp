#include <iostream>

// swap the two numbers in different variables.

int num1, num2, temp;

int main() {
    
    std::cout << "Input first number: ";
    std::cin >> num1;
    std::cout << "Input second number: ";
    std::cin >> num2;

    temp = num1;
    num1 = num2;
    num2 = temp;

    std::cout << "After swapping, first number: " << num1 << std::endl;
    std::cout << "After swapping, second number: " << num2 << std::endl;

    return 0;

}