#ifndef BSTREE_H
#include <iostream>

using namespace std;

typedef int infotype;
typedef struct Node*address;

struct Node{
    infotype info;
    address left;
    address right;
};

address newNode(infotype x);

address insertNode(address root, infotype x);

void inOrder(address root);

#endif