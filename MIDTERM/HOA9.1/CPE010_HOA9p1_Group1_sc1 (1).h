//Alvarez,Joshua Caleb P.
#ifndef GENERAL_TREE_H
#define GENERAL_TREE_H

#include <iostream>

template <typename T>
class GeneralTree {
private:
    T key;

    GeneralTree<T>* child;
    GeneralTree<T>* sibling;

public:
    GeneralTree(T value);

    void insertChild(GeneralTree<T>* newChild);

    void preOrder();
    void inOrder();
    void postOrder();
};

template <typename T>
GeneralTree<T>::GeneralTree(T value) {
    key = value;
    child = nullptr;
    sibling = nullptr;
}

template <typename T>
void GeneralTree<T>::insertChild(GeneralTree<T>* newChild) {

    if (child == nullptr) {
        child = newChild;
    }
    else {
        GeneralTree<T>* temp = child;

        while (temp->sibling != nullptr) {
            temp = temp->sibling;
        }

        temp->sibling = newChild;
    }
}

template <typename T>
void GeneralTree<T>::preOrder() {

    std::cout << key << " ";

    if (child != nullptr) {
        child->preOrder();
    }

    if (sibling != nullptr) {
        sibling->preOrder();
    }
}

template <typename T>
void GeneralTree<T>::inOrder() {

    if (child != nullptr) {
        child->inOrder();
    }

    std::cout << key << " ";

    if (sibling != nullptr) {
        sibling->inOrder();
    }
}

template <typename T>
void GeneralTree<T>::postOrder() {

    if (child != nullptr) {
        child->postOrder();
    }

    if (sibling != nullptr) {
        sibling->postOrder();
    }

    std::cout << key << " ";
}

#endif