#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>

template <typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next = nullptr;
    doubleList<T>* prev = nullptr;
};

template <typename T>
doubleList<T>* new_Node(T newData) {

    // Create a new node
    doubleList<T>* newNode = new doubleList<T>;

    // Store the data in the node
    newNode->data = newData;

    // Initialize both pointers
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Return the newly created node
    return newNode;
}

template <typename T>
void dllTraverse(doubleList<T>* head) {

    // Start traversal from the head node
    doubleList<T>* tail = nullptr;
    doubleList<T>* current = head;

    // Display the list in forward order
    std::cout << "Forward Traversal" << std::endl;

    while (current != nullptr) {
        std::cout << current->data << " ";
        tail = current;
        current = current->next;
    }

    std::cout << std::endl;

    // Display the list in reverse order
    std::cout << "Reverse Traversal" << std::endl;

    while (tail != nullptr) {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;
}

template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead) {

    // Create a new node
    doubleList<T>* newNode = new_Node(newData);

    // If the list is empty, make the new node the head
    if (*currentHead == nullptr) {
        *currentHead = newNode;
        return;
    }

    // Link the new node to the current head
    newNode->next = *currentHead;

    // Update the previous pointer of the old head
    (*currentHead)->prev = newNode;

    // Make the new node the new head
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, doubleList<T>** currentHead) {

    // Create a new node
    doubleList<T>* newNode = new_Node(newData);

    // If the list is empty, insert the node as the head
    if (*currentHead == nullptr) {
        *currentHead = newNode;
        return;
    }

    // Traverse to the last node
    doubleList<T>* temp = *currentHead;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Connect the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}

template <typename T>
void dllInsertPosition(T newData, int position, doubleList<T>** currentHead) {

    // Check if the position is valid
    if (position < 1) {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    // Insert at the head if position is 1
    if (position == 1) {
        dllInsertHead(newData, currentHead);
        return;
    }

    // Traverse to the node before the insertion point
    doubleList<T>* temp = *currentHead;

    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // Stop if the position is beyond the list
    if (temp == nullptr) {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    // Insert at the end if needed
    if (temp->next == nullptr) {
        dllInsertEnd(newData, currentHead);
        return;
    }

    // Create the new node
    doubleList<T>* newNode = new_Node(newData);

    // Update the pointers of the surrounding nodes
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

template <typename T>
void dllDeletePosition(int position, doubleList<T>** currentHead) {

    // Return if the list is empty
    if (*currentHead == nullptr) {
        std::cout << "List is Empty!" << std::endl;
        return;
    }

    // Check if the position is valid
    if (position < 1) {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    // Start from the head node
    doubleList<T>* temp = *currentHead;

    // Delete the first node
    if (position == 1) {
        *currentHead = temp->next;

        if (*currentHead != nullptr) {
            (*currentHead)->prev = nullptr;
        }

        delete temp;
        return;
    }

    // Traverse to the target position
    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    // Stop if the position is invalid
    if (temp == nullptr) {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    // Connect the previous node to the next node
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    // Update the previous pointer of the next node
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    // Delete the selected node
    delete temp;
}

template <typename T>
void dllDestroy(doubleList<T>** currentHead) {

    // Start deleting from the head
    doubleList<T>* temp = *currentHead;

    // Delete every node in the list
    while (temp != nullptr) {
        doubleList<T>* next = temp->next;
        delete temp;
        temp = next;
    }

    // Reset the head pointer
    *currentHead = nullptr;
}

#endif