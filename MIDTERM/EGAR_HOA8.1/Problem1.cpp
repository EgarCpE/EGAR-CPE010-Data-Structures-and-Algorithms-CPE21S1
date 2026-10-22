#include <iostream>
#include "problem1.h"

int main() {
    int arr[] = {34, 12, 25, 9, 19};
    int n = 5;

    std::cout << "Unsorted Array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";

    hybridQuickSort(arr, 0, n - 1);

    std::cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}