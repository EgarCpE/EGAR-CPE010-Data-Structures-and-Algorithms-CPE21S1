#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <iostream>

// Helper function
template <typename T>
int routine_smallest(T A[], int maxSize, int k) { // k = current index
    int position, j;
    T smallestElement = A[k];

    for (j = k + 1; j < maxSize; j++) {
        if (A[j] < smallestElement) {
            smallestElement = A[j];
            position = j;
        }
    }
    return position;
}

// Bubble Sort
template <typename T>
void bubbleSort(T arr[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - 1 - i; j++) {
            // compare adjacent elements and swap if out of order
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
template <typename T>
void insertionSort(T arr[], int arrSize) {
    int k, j;
    T temp;

    for (k = 1; k < arrSize; k++) {
        temp = arr[k];
        j = k - 1;

        // while (j >= 0 && temp < arr[j]) // responsible for ascending
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--; // responsible for descending
        }

        arr[j + 1] = temp; // responsible for ascending
                           // responsible for descending
    }
}

// Selection Sort
template <typename T>
void selectionSort(T arr[], int arrSize) {
    int POS, temp;

    for (int i = 0; i < arrSize - 1; i++) {
        POS = routine_smallest(arr, arrSize, i);

        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    }
}

#endif