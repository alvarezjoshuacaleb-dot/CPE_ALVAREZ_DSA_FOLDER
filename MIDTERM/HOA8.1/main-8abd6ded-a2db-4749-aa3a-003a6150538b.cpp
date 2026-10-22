#include <iostream>
#include "sortingAlgorithms.h"

void display(int arr[], int size);

int main() {

    // Example array after Quick Sort partition
    int leftSubList[] = {3, 4, 2};
    int rightSubList[] = {8, 7, 9};

    int leftSize = 3;
    int rightSize = 3;

    std::cout << "QUICK SORT PARTITION EXAMPLE\n";
    std::cout << "============================\n";

    std::cout << "Left Sub-list: ";
    display(leftSubList, leftSize);

    std::cout << "Pivot: 6\n";

    std::cout << "Right Sub-list: ";
    display(rightSubList, rightSize);

    // Sort the left and right sub-lists
    // using Insertion Sort
    insertionSort(leftSubList, leftSize);
    insertionSort(rightSubList, rightSize);

    std::cout << "\nAFTER USING INSERTION SORT\n";
    std::cout << "==========================\n";

    std::cout << "Left Sub-list: ";
    display(leftSubList, leftSize);

    std::cout << "Pivot: 6\n";

    std::cout << "Right Sub-list: ";
    display(rightSubList, rightSize);

    std::cout << "\nFinal Sorted Array: ";

    display(leftSubList, leftSize);
    std::cout << "6 ";
    display(rightSubList, rightSize);

    return 0;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}