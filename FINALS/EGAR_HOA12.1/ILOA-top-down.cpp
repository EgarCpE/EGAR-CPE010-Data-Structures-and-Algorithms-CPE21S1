#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Maximum value for n (adjust if testing larger numbers)
const int MAX = 100000;
int memo[MAX]; // Global array, initialized in main

int getMinSteps(int n)
{
    if (n == 1) return 0; // Base case[cite: 2]

    if (memo[n] != -1) return memo[n]; // We have solved it already :)[cite: 2]

    int r = 1 + getMinSteps(n - 1); // '-1' step. 'r' will contain the optimal answer finally[cite: 2]

    if (n % 2 == 0) {
        r = min(r, 1 + getMinSteps(n / 2)); // '/2' step[cite: 2]
    }

    if (n % 3 == 0) {
        r = min(r, 1 + getMinSteps(n / 3)); // '/3' step[cite: 2]
    }

    memo[n] = r; // Save the result. If you forget this step, then it's same as plain recursion.[cite: 2]
    return r;
}

int main()
{
    int n = 10; // Change n to test different values

    // Initialize memo array with -1 (-1 means not solved yet)[cite: 2]
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    cout << "Minimum steps for n = " << n << " is: " << getMinSteps(n) << endl;

    return 0;
}