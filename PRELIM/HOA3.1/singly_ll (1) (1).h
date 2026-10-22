#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

template <typename T>
class SingleList {
public:
    T data;
    SingleList<T>* next = nullptr;
};

// Traverse the list
template <typename T>
void listTraversal(SingleList<T>* head) {

    while (head != nullptr) {

        std::cout << head->data;

        if (head->next != nullptr) {
            std::cout << " -> ";
        }

        head = head->next;
    }

    std::cout << std::endl;
}

// Insert at the head
template <typename T>
void sllinsertHead(T newData, SingleList<T>** head) {

    SingleList<T>* newNode = new SingleList<T>;

    newNode->data = newData;
    newNode->next = *head;

    *head = newNode;
}

// Insert after a specific node
template <typename T>
void sllGeneralinsertion(T newData, SingleList<T>* prevNode) {

    if (prevNode == nullptr) {
        std::cout << "Previous node cannot be null." << std::endl;
        return;
    }

    SingleList<T>* newNode = new SingleList<T>;

    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Insert at the end
template <typename T>
void sllinsertEnd(T newData, SingleList<T>** head) {

    SingleList<T>* newNode = new SingleList<T>;

    newNode->data = newData;
    newNode->next = nullptr;

    // Empty list
    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    SingleList<T>* currentNode = *head;

    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

// Delete a node
template <typename T>
void sllDelete(T findData, SingleList<T>** head) {

    if (*head == nullptr)
        return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    // Search for the node
    while (currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // Not found
    if (currNode == nullptr)
        return;

    // Delete head
    if (prevNode == nullptr) {
        *head = currNode->next;
    }
    // Delete middle/end
    else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

// Delete entire list
template <typename T>
void sllDeleteList(SingleList<T>** head) {

    SingleList<T>* currentNode = *head;

    while (currentNode != nullptr) {

        SingleList<T>* temp = currentNode;
        currentNode = currentNode->next;

        delete temp;
    }

    *head = nullptr;
}

#endif