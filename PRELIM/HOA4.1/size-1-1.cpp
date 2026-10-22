// Alvarez, Joshua Caleb P.
#include <iostream>


const size_t maxCap = 100;
int stack[maxCap]; //Stack with max of 100 elements
int top = -1, i, newData;



void push();
void pop();
void Top();
bool isEmpty();
bool isFull();


int main(){

    int choice;
    std::cout<<" Enter the number of max elements for the new stack: ";
    std::cin>>i;
    while (true){}
        std::cout<<"stack operations"<<std::endl;
        std::cout<< "1. PUSH 2. POP. 3. TOP 4isEmpty" <<std::endl;
        std::cin>>choice;

    switch(choice){
        case 1: push();
        break;
        case 2: pop();
        break;
        case 3: Top();
        break;
        case 4: std::cout<< isEmpty()<<std::endl;
        break;
        default: std::cout<<"Invalid choice. "<< std::endl;
        break;
        }

    return 0;
}

bool isEmpty(){
    //create a condition to check wheter the top element is equal to -1
    if(top == -1 ) return true;
    return false;

}

bool isFull(){
    //checl if we reached the maximum capacity of the array;
    if (top > i-1)return true;
    return false;

}

void push(){
    //check if full -> if yes return error
    if (top == i-1){
        std::cout<<"stack overflow";
        return;
    }

    std:: cout <<"New Value to add into the stack"<< std::endl;
    std::cin >> newData;
    stack[++top] = newData;


}

void Top(){
    //checl if the stack is empty
    if(isEmpty()){
        std::cout<<"stack underflow. "<< std::endl;

    }

    std::cout<<" The element of the top of the stack is" <<stack[top]<<std::endl;

}

void pop(){
    //check if the stack is empty
if(isEmpty()){
    std::cout<<"Stack underflow. "<<std::endl;


    }

    std::cout<<"popping: "<<stack[top];
    //decrement the top value from the stack
    top--;

}


