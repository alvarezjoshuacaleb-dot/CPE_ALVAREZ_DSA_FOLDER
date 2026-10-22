// Alvarez, Joshua Caleb P.
#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>

// class node that contains data and the next
template <typename T>
class Node {
public:
    T data;     // VALUE THAT WE NEED TO STORE
    Node* next; // POINTER TO THE NEXT NODE
};

// global pointer for the top of the stack
template <typename T>
inline Node<T>* head = nullptr;  // 'inline' avoids multiple definition errors

// push
template <typename T>
void push(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

// pop
template <typename T>
T pop() {
    if (head<T> == nullptr) {
        std::cout << "Stack underflow." << std::endl;
        return T(); // return default value of T
    }
    Node<T>* temp = head<T>;
    T temVal = temp->data;
    head<T> = head<T>->next;
    delete temp;
    return temVal;
}

// top
template <typename T>
T Top() {
    if (head<T> == nullptr) {
        std::cout << "Stack underflow." << std::endl;
        return T();
    }
    std::cout << "Top of Stack: " << head<T>->data << std::endl;
    return head<T>->data;
}

// isEmpty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// displayAll
template <typename T>
void displayAll() {
    if (head<T> == nullptr) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    Node<T>* temp = head<T>;
    while (temp != nullptr) {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif
