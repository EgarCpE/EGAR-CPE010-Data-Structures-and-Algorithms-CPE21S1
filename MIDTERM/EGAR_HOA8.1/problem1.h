#ifndef PROBLEM1_H
#define PROBLEM1_H

// Partition function from Quick Sort
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    T temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Simple Selection Sort for sub-lists
template <typename T>
void selectionSort(T arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        int minIdx = i;
        for (int j = i + 1; j <= end; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        T temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

// Partitions first, then sorts left and right sub-lists
template <typename T>
void hybridQuickSort(T arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Sort sub-lists using selection sort
        selectionSort(arr, low, pi - 1);
        selectionSort(arr, pi + 1, high);
    }
}

#endif