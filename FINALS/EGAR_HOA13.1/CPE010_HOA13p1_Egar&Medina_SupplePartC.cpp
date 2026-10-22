#include <iostream>
#include <thread>
// Straight copied and slightly modified from HOA 6.1 (Linear Search Algo)
void linearSearchArr(int data[], int arrSize, int findNum, int *result) {
    int j = 0; // comps
    int i = 0; // counts
    while (i < arrSize) {
        if (findNum == data[i]) {
            j++;
        }
        i++;
    }
    *result = j;
}
int main() {
    int data[] = {6, 7, 4, 2, 0, 5, 8, 1, 5, 4, 6, 5};
    int findNum = 5;
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    std::thread T1(linearSearchArr, &data[0], 4, findNum, &result1);
    std::thread T2(linearSearchArr, &data[4], 4, findNum, &result2);
    std::thread T3(linearSearchArr, &data[8], 4, findNum, &result3);
    T1.join();
    T2.join();
    T3.join();
    std::cout << "Thread 1 matches: " << result1 << '\n';
    std::cout << "Thread 2 matches: " << result2 << '\n';
    std::cout << "Thread 3 matches: " << result3 << '\n';
    int total = result1 + result2 + result3;
    std::cout << "The element '" << findNum << "' is found " << total << " time/s.\n";
    return 0;
}