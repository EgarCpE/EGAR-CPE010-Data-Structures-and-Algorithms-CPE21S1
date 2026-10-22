#include <iostream>

const int ROWS = 4;
const int COLS = 4;

int matrix[ROWS][COLS] = {
    // Lab supple given matrix
    {4, 7, 1, 6},
    {6, 7, 3, 9},
    {3, 8, 1, 2},
    {7, 1, 7, 3}
};

int pathFind(int row, int column, int remain){
    if (row >= ROWS || column >= COLS) {
        return 0;
    }

    remain = remain - matrix[row][column];
    if (remain < 0){
        return 0;
    }

    if (row == ROWS - 1 && column == COLS - 1){
        if (remain == 0) {
            return 1;
        }
        return 0;
    }

    int right = pathFind(row, column + 1, remain);
    int down = pathFind(row + 1, column, remain);
    return right + down;
}

int main() {
    int cost;

    std::cout << "4x4 Matrix Given:\n";
    for (int row = 0; row < ROWS; row++){
        for (int column = 0; column < COLS; column++){
            std::cout << matrix[row][column] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "=======\nEnter path cost to find: ";
    std::cin >> cost;

    std::cout << "\nNumber of paths: " << pathFind(0, 0, cost) << std::endl;

    return 0;
}