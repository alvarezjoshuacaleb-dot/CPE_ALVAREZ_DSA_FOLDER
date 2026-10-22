#include <iostream>
#include "CPE010_HOA9p1_Group1_sc1.h"

int main() {

    GeneralTree<char> A('A');
    GeneralTree<char> B('B');
    GeneralTree<char> C('C');
    GeneralTree<char> D('D');
    GeneralTree<char> E('E');
    GeneralTree<char> F('F');
    GeneralTree<char> G('G');

    GeneralTree<char> H('H');
    GeneralTree<char> I('I');
    GeneralTree<char> J('J');

    GeneralTree<char> K('K');
    GeneralTree<char> L('L');
    GeneralTree<char> M('M');
    GeneralTree<char> N('N');

    GeneralTree<char> P('P');
    GeneralTree<char> Q('Q');


    // A children
    A.insertChild(&B);
    A.insertChild(&C);
    A.insertChild(&D);
    A.insertChild(&E);
    A.insertChild(&F);
    A.insertChild(&G);

    // D child
    D.insertChild(&H);

    // E children
    E.insertChild(&I);
    E.insertChild(&J);

    // J children
    J.insertChild(&P);
    J.insertChild(&Q);

    // F children
    F.insertChild(&K);
    F.insertChild(&L);
    F.insertChild(&M);

    // G child
    G.insertChild(&N);


    std::cout << "PreOrder: ";
    A.preOrder();
    std::cout << std::endl;

    std::cout << "InOrder: ";
    A.inOrder();
    std::cout << std::endl;

    std::cout << "PostOrder: ";
    A.postOrder();
    std::cout << std::endl;

    return 0;
}