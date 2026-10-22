#include <iostream>
#include <chrono>
#include <iomanip>

// 1st Algo
int rpower(int x, int n) {
    if (n == 0)
        return 1;

    return x * rpower(x, n - 1);
}

// 2nd Algo
int brpower(int x, int n) {
    if (n == 0)
        return 1;

    if (n % 2 != 0) {
        int y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }

    int y = brpower(x, n / 2);
    return y * y;
}

// way to test (structure taken from the lab activity)
void power_test(int x, int n) {
    const int repetitions = 2000;

    volatile int result = 0;

    std::cout << "\nBase (x): " << x
              << "\nExponent (n): " << n << '\n';

    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    for (int i = 0; i < repetitions; i++) {
        result = rpower(x, n);
    }

    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    double rpower_time =
        std::chrono::duration<double, std::micro>(
            end - begin
        ).count() / repetitions;

    std::cout << "rpower result = " << result << '\n';
    std::cout << "Average time taken by rpower = " << rpower_time << " microseconds\n";

    begin = std::chrono::steady_clock::now();

    for (int i = 0; i < repetitions; i++) {
        result = brpower(x, n);
    }

    end = std::chrono::steady_clock::now();

    double brpower_time =
        std::chrono::duration<double, std::micro>(
            end - begin
        ).count() / repetitions;

    std::cout << "brpower result = " << result << '\n';
    std::cout << "Average time taken by brpower = " << brpower_time << " microseconds\n";
}

int main() {
    std::cout << std::fixed << std::setprecision(4);

    int x = 1;

    power_test(x, 100);
    power_test(x, 1000);
    power_test(x, 10000);

    return 0;
}