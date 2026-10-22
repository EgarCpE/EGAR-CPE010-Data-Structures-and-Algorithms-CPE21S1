#include <iostream>

//problem4-modi-binarysearch

int BSrecursive(
     int array[],
     int low, 
     int high, 
     int target)
{
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    std::cout << "Checking element: " << array[mid] << std::endl;

    if (array[mid] == target) {
        return mid;
    }
    
    if (target < array[mid]) {
        return BSrecursive(array, low, mid - 1, target);
    } 
    else {
        return BSrecursive(array, mid + 1, high, target);
    }
}

int main()
{
    int array[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int target = 8;

    int index = BSrecursive(array, 0, 9, target);

    if (index != -1) {
        std::cout << std::endl;
        std::cout << "Element found at index: " << index << std::endl;
    } 
    else {
        std::cout << "Element not found!" << std::endl;
    }

    return 0;
}