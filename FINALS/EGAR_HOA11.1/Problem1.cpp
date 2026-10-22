#include <iostream>
#include <vector>
#include <chrono>


bool Unique(const std::vector<int>& A) {
    int n = A.size();

    // check every pair of elements
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false; // Found a duplicate
            }
        }
    }

    return true;
}

void test_unique(int n) {
    // responsible for generating a vector of size n with unique elements
    std::vector<int> A;
    for (int i = 0; i < n; i++) {
        A.push_back(i);
    }

    // Measures the start time
    auto start = std::chrono::high_resolution_clock::now();

    bool result = Unique(A);

    // Measures the end time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "Input Size (N) = " << n << std::endl;
    std::cout << "Execution Speed = " << duration << " microseconds" << std::endl;
    std::cout << "Result = " << (result ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

int main() {
    std::cout << "Problem 1: " << std::endl << std::endl;

    test_unique(1000);
    test_unique(10000);
    test_unique(100000);

    return 0;
}