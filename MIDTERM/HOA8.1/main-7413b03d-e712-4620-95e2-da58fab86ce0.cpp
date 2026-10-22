#include <iostream>
#include "quickSort.h"

const int SIZE = 15;

void displayArray(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    int arr[SIZE] = {
        4, 34, 29, 48, 53,
        87, 12, 30, 44, 25,
        93, 67, 43, 19, 74
    };

    std::cout << "Original Array: ";
    displayArray(arr);

    quickSort(arr, 0, SIZE - 1);

    std::cout << "Sorted Array: ";
    displayArray(arr);

    std::cout << "\nQuick Sort Average Time Complexity: O(N log N)" << std::endl;
    std::cout << "Quick Sort Worst Time Complexity: O(N^2)" << std::endl;

    return 0;
}