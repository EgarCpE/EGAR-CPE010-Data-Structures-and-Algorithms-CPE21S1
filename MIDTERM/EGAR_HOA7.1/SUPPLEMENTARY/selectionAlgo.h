#ifndef SELECTIONALGO_H
#define SELECTIONALGO_H

// Helper function to find index of smallest element from index k onwards
template <typename T>
int routine_smallest(T A[], int maxSize, int k) {
    int position = k; // Default position to k in case A[k] is already smallest
    T smallestElement = A[k];

    for (int j = k + 1; j < maxSize; j++) {
        if (A[j] < smallestElement) {
            smallestElement = A[j];
            position = j;
        }
    }

    return position;
}

// Selection sort algorithm
template <typename T>
void selectionSort(T arr[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) { // Optimization: stop at arrSize - 1
        int POS = routine_smallest(arr, arrSize, i);

        // Swap elements using template type T
        T temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    }
}

#endif