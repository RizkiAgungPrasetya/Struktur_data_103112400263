#include "bstree.h"

address newNode(infotype x){
    address temp = new Node;
    temp -> info = x;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

address insertNode(address root, infotype x){
    if(root == NULL)
    return newNode(x);

    if(x < root -> info)
    root -> left = insertNode(root -> left, x);
    else if(x > root -> info)
    root -> right = insertNode(root -> right, x);

    return root;
}

void inOrder(address root){
    if(root != NULL){
        inOrder(root -> left);
        cout << root -> info << " ";
        inOrder(root -> right);
    }
}