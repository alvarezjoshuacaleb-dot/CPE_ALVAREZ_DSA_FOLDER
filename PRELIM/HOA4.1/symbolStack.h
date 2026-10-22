// Alvarez, Joshua Caleb P.
#ifndef SYMBOLSTACK_H
#define SYMBOLSTACK_H

#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
};

template <typename T>
inline Node<T>* head = nullptr;

template <typename T>
void push(T newData)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

template <typename T>
T pop()
{
    if (head<T> == nullptr)
    {
        std::cout << "Stack underflow.\n";
        return T();
    }

    Node<T>* temp = head<T>;
    T value = temp->data;
    head<T> = head<T>->next;
    delete temp;

    return value;
}

template <typename T>
bool isEmpty()
{
    return head<T> == nullptr;
}

#endif