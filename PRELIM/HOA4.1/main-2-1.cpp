//Alvarez,Joshua Caleb P.
#include <iostream>
#include "stacklist.h"

int main() {
    std::cout << "------ PUSHING 'c' 'p' 'e' ONTO THE STACK ------ \n";

    // Push elements
    push<char>('c');
    push<char>('p');
    push<char>('e');

    // Display the current top
    std::cout << "Top: " << Top<char>() << std::endl; // Top should be 'e'
    displayAll<char>();
    std::cout << std::endl;

    std::cout << "\n ------ Popping all the elements ------- \n";

    while (!isEmpty<char>()) {
        std::cout << "Popped: " << pop<char>() << std::endl;
    }

    std::cout << "\n ------ Testing the Underflow ------ \n";
    pop<char>(); // Should trigger underflow handling in your stacklist.h

    return 0;
}