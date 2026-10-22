#include <iostream>
#include "ILOC.h"

int main() {

    std::string expression;
    char choice;

    do {
        std::cout << "Enter expression: ";
        std::getline(std::cin, expression);

        if (isBalanced(expression))
            std::cout << "\nExpression is Balanced.\n";
        else
            std::cout << "\nExpression is NOT Balanced.\n";

        std::cout << "\nDo you want to check another expression? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore();

    } while (choice == 'Y' || choice == 'y');

    std::cout << "\nProgram Ended.\n";

    return 0;
}