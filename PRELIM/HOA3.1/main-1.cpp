#include <iostream>
#include "doubly_ll.h"

int main() {

    // Create the head node
    doubleList<char>* head = new_Node('C');

    // Create the remaining nodes
    doubleList<char>* second = new_Node('P');
    doubleList<char>* third = new_Node('E');

    // Link the nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Initial Traversal" << std::endl;
    dllTraverse(head);

    // Insert at the head
    std::cout << "\nInsertion at Head" << std::endl;
    dllInsertHead('A', &head);
    dllTraverse(head);

    // Insert at position 3
    std::cout << "\nInsertion at Position 3" << std::endl;
    dllInsertPosition('G', 3, &head);
    dllTraverse(head);

    // Insert at the end
    std::cout << "\nInsertion at End" << std::endl;
    dllInsertEnd('Z', &head);
    dllTraverse(head);

    // Delete node at position 3
    std::cout << "\nDeletion at Position 3" << std::endl;
    dllDeletePosition(3, &head);
    dllTraverse(head);

    // Free all allocated memory
    dllDestroy(&head);

    return 0;
}