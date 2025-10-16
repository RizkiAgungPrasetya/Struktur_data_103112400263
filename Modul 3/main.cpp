#include "sll.h"
#include <iostream>
using namespace std;

int main() {
    SLL L;
    CreateList(L);

    cout << "InsertFirst 10, 20" << endl;
    InsertFirst(L, 10);
    InsertFirst(L, 20);
    ViewList(L);

    cout << "InsertLast 30, 40" << endl;
    InsertLast(L, 30);
    InsertLast(L, 40);
    ViewList(L);

    cout << "DeleteFirst" << endl;
    DeleteFirst(L);
    ViewList(L);

    cout << "DeleteLast" << endl;
    DeleteLast(L);
    ViewList(L);

    cout << "InsertAfter node pertama (50)" << endl;
    InsertAfter(L.head, 50);
    ViewList(L);

    cout << "DeleteAfter node pertama" << endl;
    DeleteAfter(L.head);
    ViewList(L);

    return 0;
}
