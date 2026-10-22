#include <iostream>
//problem1-Array

int main() {
    int list[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int key = 18;
    int compare = 0;

    for (int num : list) {
        compare++;
        if (num == key) {
            std::cout << std::endl;
            std::cout << "Numbers of Key Found: " << num << std::endl;
            break;
        }
    }

    std::cout << std::endl;

    std::cout << "How many numbers are similar to the key: " << compare << std::endl;

     std::cout << std::endl;
    return 0;
}