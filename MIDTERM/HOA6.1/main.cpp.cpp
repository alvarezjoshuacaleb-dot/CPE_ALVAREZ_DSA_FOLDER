#include <iostream>
#include <cstdlib>
#include <ctime>
#include "nodes.h"
#include "searching.h"

const int max_size = 50;

int main() {

    // GENERATE RANDOM DATASET
    int dataset[max_size];

    std::srand(std::time(0));

    for (int i = 0; i < max_size; i++) {
        dataset[i] = std::rand();
    }

    std::cout << "===================================="<< std::endl;
    std::cout << "          GENERATED DATASET"<< std::endl;
    std::cout << "===================================="<< std::endl;
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;


    // LINEAR SEARCH - ARRAY

    int searchNumber;
    std::cout << "===================================="<< std::endl;
    std::cout << "        LINEAR SEARCH - ARRAY"<< std::endl;
    std::cout << "===================================="<< std::endl;
    std::cout << "Enter number to search: ";
    std::cin >> searchNumber;

    linearSearch(
        dataset,
        max_size,
        searchNumber
    );

    std::cout << std::endl;

    // LINEAR SEARCH - LINKED LIST
    Node<char> *name1 = new_node('J');
    Node<char> *name2 = new_node('O');
    Node<char> *name3 = new_node('S');
    Node<char> *name4 = new_node('H');
    Node<char> *name5 = new_node('U');
    Node<char> *name6 = new_node('A');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = NULL;

    std::cout << "===================================="<< std::endl;
    std::cout << "     LINEAR SEARCH - LINKED LIST"<< std::endl;
    std::cout << "===================================="<< std::endl;
    std::cout << "Name: ";

    Node<char> *current = name1;

    while (current != NULL) {
        std::cout << current->data;
        current = current->next;
    }

    std::cout << std::endl;

    // Successful search
    std::cout << "Linked list Linear Search : ";
    linearLS(name1, 'S');

    // Unsuccessful search
    std::cout << "Linked list Linear Search : ";
    linearLS(name1, 'B');
    std::cout << std::endl;

    // BINARY SEARCH - ARRAY
    int sortedArr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "===================================="<< std::endl;
    std::cout << "        BINARY SEARCH - ARRAY"<< std::endl;
    std::cout << "===================================="<< std::endl;
    std::cout << "Array: ";

    for (int i = 0; i < 7; i++) {
        std::cout << sortedArr[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "Array Binary Search : ";
    binarySearchArr(8, 6, sortedArr);

    std::cout << "Array Binary Search : ";
    binarySearchArr(8, 10, sortedArr);

    std::cout << std::endl;


    // BINARY SEARCH - LINKED LIST

    Node<int> *head = new_node(3);

    head->next = new_node(5);
    head->next->next = new_node(6);
    head->next->next->next = new_node(8);
    head->next->next->next->next = new_node(11);
    head->next->next->next->next->next = new_node(12);
    head->next->next->next->next->next->next = new_node(14);
    head->next->next->next->next->next->next->next = new_node(15);
    head->next->next->next->next->next->next->next->next = new_node(17);
    head->next->next->next->next->next->next->next->next->next = new_node(18);

    std::cout << "===================================="<< std::endl;
    std::cout << "    BINARY SEARCH - LINKED LIST"<< std::endl;
    std::cout << "===================================="<< std::endl;
    std::cout << "List: ";
    Node<int> *temp = head;

    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    Node<int> *result = binarySearchLL(head, 8);
    if (result != NULL) {

        std::cout << "Search element is found!"<< std::endl;
        std::cout << "Element found: "<< result->data<< std::endl;
    }
    else {
        std::cout << "Search element is not found"<< std::endl;
    }
    return 0;
}