#include <iostream>
#include "singly_ll.h"


int main(){
    
    SingleList<int> *head =  new SingleList<int>;
    SingleList<int> *second = new SingleList<int>;
    SingleList<int> *third = new SingleList<int>;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    std::cout << "Linked list traversal: ";
    listTraversal(head);

    std::cout<<"newly inserted head of linked list: ";
    sllinsertHead(0,&head);
    listTraversal(head);

    std::cout <<"newly inserted after a node of linked list: ";
    sllGeneralinsertion(3,head);
    listTraversal(head);

    sllGeneralinsertion(4,head->next);
    listTraversal(head);

    sllinsertEnd(10, &head);
    listTraversal(head);

    std::cout<<"deleting a node: \n";
    sllDelete(10,&head);
    listTraversal(head);
    

    delete head;
    delete second;
    delete third;

    
}