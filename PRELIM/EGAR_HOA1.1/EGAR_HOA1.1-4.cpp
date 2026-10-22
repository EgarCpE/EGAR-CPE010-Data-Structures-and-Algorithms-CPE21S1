#include <iostream>

int SumofTwoNum(int num1, int num2);

int main() {
    std::cout << SumofTwoNum(6, 14) << std::endl;

    return 0;
}

int SumofTwoNum(int fNum, int lNum) {
    int total = fNum + lNum;
    return total;
}