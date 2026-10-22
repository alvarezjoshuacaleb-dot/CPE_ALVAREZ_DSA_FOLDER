#include <iostream>
#include "queuell.h"

void display(qNode<char>* front) {
    qNode<char>* current = front;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

int main() {
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    std::cout << "====================================" << std::endl;
    std::cout << "--------- QUEUE ELEMENTS ----------" << std::endl;
    std::cout << "====================================" << std::endl;

    enqueue(&front, &back, 'J');
    std::cout << front->data << " " << back->data << std::endl;

    enqueue(&front, &back, 'C');
    std::cout << front->data << " " << back->data << std::endl;

    enqueue(&front, &back, 'Z');
    std::cout << front->data << " " << back->data << std::endl;

    enqueue(&front, &back, 'I');
    std::cout << front->data << " " << back->data << std::endl;

    enqueue(&front, &back, 'E');

    dequeue(&front, &back);

    std::cout << front->data << " " << back->data << std::endl;

    std::cout << "\nDISPLAYING ALL OF THE ELEMENTS....\n\n";

    display(front);

    return 0;
}
