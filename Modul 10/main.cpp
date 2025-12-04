#include "bstree.h"

int main(){
    address root = NULL;

    cout << "Binary Search Tree Insert & Traversal" << endl;

    root = insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    return 0;
}