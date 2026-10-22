#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include "nodes.h"

// A.1 LINEAR SEARCH - ARRAY
void linearSearch(int arr[], int n, int item) {

    int i = 0;

    while (i < n) {

        if (item == arr[i]) {
            std::cout << "Searching is successful!" << std::endl;
            std::cout << "Element found at index: "<< i << std::endl;
            return;
        }
        i++;
    }

    std::cout << "Searching is unsuccessful!"<< std::endl;
}
// A.2 LINEAR SEARCH - LINKED LIST
template <typename T>
void linearLS(Node<T> *head, T dataFind) {

    Node<T> *current = head;
    while (current != NULL) {

        if (current->data == dataFind) {
            std::cout << "Searching is successful!"<< std::endl;
            std::cout << "Element found: " << dataFind << std::endl;
            return;
        }
        current = current->next;
    }

    std::cout << "Searching is unsuccessful!"
              << std::endl;
}


// B.1 BINARY SEARCH - ARRAY
void binarySearch(int arr[], int n, int no) {

    int low = 0;
    int up = n - 1;

    while (low <= up) {

        int mid = (low + up) / 2;

        if (no == arr[mid]) {

            std::cout << "Search element is found!"<< std::endl;
            std::cout << "Element found at index: "<< mid << std::endl;
            return;
        }

        else if (no < arr[mid]) {
            up = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    std::cout << "Search element is not found"<< std::endl;
}


// B.1 BINARY SEARCH - ARRAY
// Function used in the activity format
void binarySearchArr(int item, int n, int arr[]) {
    int low = 0;
    int up = n - 1;

    while (low <= up) {

        int mid = (low + up) / 2;

        if (item == arr[mid]) {

            std::cout << "Searching is successful!"<< std::endl;
            std::cout << "Element found at index: "<< mid << std::endl;
            return;
        }

        else if (item < arr[mid]) {
            up = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    std::cout << "Searching is unsuccessful!"<< std::endl;
}

// B.2 GET MIDDLE NODE
template <typename T>
Node<T> *getMiddle(Node<T> *start, Node<T> *last) {

    if (start == NULL) {
        return NULL;
    }

    Node<T> *slow = start;
    Node<T> *fast = start;

    while (fast != last &&
           fast->next != last) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// B.2 BINARY SEARCH - LINKED LIST
template <typename T>
Node<T> *binarySearchLL(Node<T> *head, T key) {

    Node<T> *start = head;
    Node<T> *last = NULL;

    while (start != last) {

        Node<T> *middle = getMiddle(start, last);

        if (middle == NULL) {
            return NULL;
        }
        if (middle->data == key) {
            return middle;
        }
        else if (middle->data < key) {
            start = middle->next;
        }
        else {
            last = middle;
        }
    }
    return NULL;
}

#endif