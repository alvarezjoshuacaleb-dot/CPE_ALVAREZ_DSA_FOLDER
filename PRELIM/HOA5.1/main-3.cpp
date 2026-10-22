//ALvarez, Joshua Caleb p.
#include<iostream>
#include<queue>

void display(std::queue<char>r);
void empty();

//
int main(){ 
    std::queue<char> q;

    q.push('C');
    q.push('P');
    q.push('E');
    q.push('0');
    q.push('1');
    q.push('0');

    //display
    display(q);

    //empty
    std::cout<<"is the queue empty = "<< q.empty()<<std::endl;

    //size
    std::cout<<"Size of the queue: "<< q.size() << std::endl;

    //front
    std::cout<<"The front of the queue is: "<< q.front()<<std::endl;

    //back
    std::cout<<"The back of the queue is: "<< q.back()<<std::endl;

    //pop
    std::cout << "Popping front queue..... " << q.front()<<std::endl;
    q.pop();
    //display
    display(q);

    //push another element
    q.push('1');

    //display
    display(q);

    
}

void display(std::queue<char>r){
    std::queue<char> c = r;

    while(!c.empty()){
        std::cout<<" "<<c.front();
        c.pop();

    }
    std::cout<<"\n";

}


    






