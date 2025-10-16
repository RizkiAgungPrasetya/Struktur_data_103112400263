#include "sll.h"
#include <iostream>
using namespace std;

void CreateList(SLL &L) {
    L.head = NULL;
}

bool IsEmpty(SLL L) {
    return L.head == NULL;
}

void InsertFirst(SLL &L, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = L.head;
    L.head = newNode;
}

void InsertLast(SLL &L, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (IsEmpty(L)) {
        L.head = newNode;
    } else {
        Node* p = L.head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
}

void InsertAfter(Node* prevNode, int x) {
    if (prevNode != NULL) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

void DeleteFirst(SLL &L) {
    if (!IsEmpty(L)) {
        Node* temp = L.head;
        L.head = L.head->next;
        delete temp;
    }
}

void DeleteLast(SLL &L) {
    if (!IsEmpty(L)) {
        if (L.head->next == NULL) {
            delete L.head;
            L.head = NULL;
        } else {
            Node* p = L.head;
            while (p->next->next != NULL) {
                p = p->next;
            }
            delete p->next;
            p->next = NULL;
        }
    }
}

void DeleteAfter(Node* prevNode) {
    if (prevNode != NULL && prevNode->next != NULL) {
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        delete temp;
    }
}


void ViewList(SLL L) {
    if (IsEmpty(L)) {
        cout << "List kosong." << endl;
        return;
    }

    Node* p = L.head;
    cout << "Isi list: ";
    while (p != NULL) {
        cout << p->data;
        if (p->next != NULL) cout << " -> ";
        p = p->next;
    }
    cout << " -> NULL" << endl;
}