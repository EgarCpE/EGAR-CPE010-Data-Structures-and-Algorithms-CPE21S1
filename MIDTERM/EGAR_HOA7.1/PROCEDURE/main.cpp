#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

//bubble sort

// generate 100 random values
// create a function that will display the random generated values

const int maxSize = 100;

void displayArr(int arr[]);

int main() {
    // create an array with unsorted list with the maxSize size
    int unsortedArr[maxSize];

    // seed for rand to seed for random values
    std::srand(std::time(0));

    // populate the array with random values
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = std::rand() % 100;
    }

    std::cout << "Unsorted Array:" << std::endl;
    displayArr(unsortedArr);

    std::cout << "\nBubble Sort:" << std::endl;
    // bubbleSort(unsortedArr, maxSize);

    std::cout << "\nInsertion Sort:" << std::endl;
    // insertionSort(unsortedArr, maxSize);

    std::cout << "\nSelection Sort:" << std::endl;
    // selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}