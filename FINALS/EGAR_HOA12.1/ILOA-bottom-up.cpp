#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinSteps(int n)
{
    // Use std::vector instead of fixed array to avoid 'constant value' error
    vector<int> dp(n + 1);

    dp[1] = 0; // Trivial case

    // Fixed lowercase 'for'
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - 1];

        if (i % 2 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        }

        if (i % 3 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 3]);
        }
    }

    return dp[n];
}

int main()
{
    int n = 10; // Change n to test different inputs (e.g., 10, 100)

    cout << "Minimum steps for n = " << n << " is: " << getMinSteps(n) << endl;

    return 0;
}