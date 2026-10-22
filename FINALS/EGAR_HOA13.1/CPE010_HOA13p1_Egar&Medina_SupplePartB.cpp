#include <iostream>
#include <thread>
int total = 0;
void add(int number) {
    total = total + number;
}
int main() {
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);
    std::cout << "Before joining: " << total << '\n';
    T1.join();
    std::cout << "After T1: " << total << '\n';
    T2.join();
    std::cout << "After T2: " << total << '\n';
    T3.join();
    std::cout << "After T3: " << total << '\n';
    return 0;
}