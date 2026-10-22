#include <iostream>

// problem3-newsortlist

int main()
{
    int data[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    int key = 8;
    int low = 0;
    int up = 9;
    int comparisons = 0;

    while (low <= up)
    {
        int middle_Index = (low + up) / 2;

        comparisons++;
        
        std::cout << std::endl;
        std::cout << "Iteration: " << comparisons
                  << " Middle Index = " << data[middle_Index] << std::endl;

        if (data[middle_Index] == key)
        {

            std::cout << std::endl;
            std::cout << "Search element is found" << std::endl;
            std::cout << "Index: " << middle_Index << std::endl;
            std::cout << "Comparisons: " << comparisons << std::endl;
            return 0;
        }
        else if (key < data[middle_Index])
        {
            up = middle_Index - 1;
        }
        else
        {
            low = middle_Index + 1;
        }
    }

    std::cout << "Search element is not found" << std::endl;

    return 0;
}