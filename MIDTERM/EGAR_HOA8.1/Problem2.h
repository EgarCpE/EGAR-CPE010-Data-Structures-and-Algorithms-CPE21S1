#ifndef PROBLEM2_H
#define PROBLEM2_H

// Helper partition function for Quick Sort
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;


    // scans every number in the array for swapping 
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

// quickSort
template <typename T>
void quickSort(T arr[], int low, int high) {

    //checker if low < high 
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

#endif