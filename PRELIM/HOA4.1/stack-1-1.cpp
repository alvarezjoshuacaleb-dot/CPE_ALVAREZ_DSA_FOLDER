//Alvarez, Joshua Caleb P.
#include <iostream>
#include <stack>

using namespace std;

int main(){
    //create an object for the stac
    stack<int> newStack;
    std:: cout << " Stack Empty?:  "<<newStack.empty()<<std::endl;
    //push to the stack
    newStack.push(3);
    newStack.push(8);
    newStack.push(15);

    std::cout<<"Stack Empty?:  "<<newStack.empty()<<std::endl;
    std::cout<<"The size of the stack: "<<newStack.size()<<std::endl;
    std::cout<<"The top of the element is: "<<newStack.top()<<std::endl;
    std::cout<<"Removing the elements from the stack: \n";

    std::cout<<"The top of the element: is: "<<newStack.top()<<std::endl;
    newStack.pop();
     std::cout<<"The top of the element: is: "<<newStack.top()<<std::endl;
    newStack.pop();
     std::cout<<"The top of the element: is: "<<newStack.top()<<std::endl;
    newStack.pop();

    return 0;
}