#ifndef SLL_N
#define SLL_N

struct Node {
    int data;
    Node* next;
};

struct SLL {
    Node* head;
};

//Konstruktor
void Createlist(SLL &L);

//Predikat
bool IsEmpty(SLL L);

//Primitif
void InsertFirst(SLL &L, int x);
void InsertLast(SLL &L, int x);
void InsertAfter(Node* prevNode, int x);

void DeleteFirst(SLL &L);
void DeleteLast(SLL &L);
void DeleteAfter(Node* prevNode);

void ViewList(SLL L);

#endif