#ifndef QUEUELL_H
#define QUEUELL_H

template<typename T>
class qNode{
    public:
    T data;
    qNode *next;
};

//creating a new node
template<typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template<typename T>
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData){
// create a new node
qNode<T>* newNode = new_node(newData);
//inserting to an empy queue 
if((*frontPtr) == nullptr && (*backPtr) ==nullptr){
(*frontPtr) = newNode;
(*backPtr) = newNode;
}


//inserting an item into a non empty queue
(*backPtr) ->next = newNode;
(*backPtr) = newNode;


}
template<typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    //create a temporary to store the node to be deleted 
    qNode<T>* deleteNode = nullptr;
    deleteNode = (*frontPtr);
    //check if the queue is only 1 Node
    if((*frontPtr)->next == nullptr && (*backPtr) -> next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }
    //deleting of the Node 
    (*frontPtr)=deleteNode->next;
    delete deleteNode;

}

//display all the elements in the list
template <typename T>
void displayall(qNode<T>* front)  {
    if (front == nullptr){
        std::cout<<"Queue is empty. \n"; 
        return;
    }
    while (front != nullptr){
        std::cout << front->data << " " << std:: endl;
        front = front->next;
    }
    std::cout<<std::endl;
}

// return the front variable


#endif