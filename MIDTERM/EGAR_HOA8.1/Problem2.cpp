#include <iostream>
#include "Problem2.h"

// Forward declaration matching the displayArray definition below
void displayArr(int arr[], int size);

int main() {
    // create the array in the problem
    int arr[15] = {4, 34, 29, 48, 53, 87, 12, 30,
                   44, 25, 93, 67, 43, 19, 74};

    // get the number of elements
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array:\n";
    displayArr(arr, n);

    // perform quick sort
    quickSort(arr, 0, n - 1);

    std::cout << "\nSorted Array:\n";
    displayArr(arr, n);

    return 0;
}

void displayArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}