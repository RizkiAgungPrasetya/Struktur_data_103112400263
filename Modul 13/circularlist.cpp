#include "circularlist.h"
#include <iostream>

using namespace std;

void CreateList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    if (P != NULL) {
        delete P;
        P = NULL;
    }
}

void insertFirst(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        P->next = P; 
    } else {
        address last = L.First;
        while (last->next != L.First) last = last->next;
        P->next = L.First;
        last->next = P;
        L.First = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec == NULL) return;
    P->next = Prec->next;
    Prec->next = P;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        insertFirst(L, P);
    } else {
        address last = L.First;
        while (last->next != L.First) last = last->next;
        last->next = P;
        P->next = L.First;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL;
        return;
    }
    if (L.First->next == L.First) {
        P = L.First;
        L.First = NULL;
    } else {
        address last = L.First;
        while (last->next != L.First) last = last->next;
        P = L.First;
        L.First = P->next;
        last->next = L.First;
        P->next = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
        return;
    }
    P = Prec->next;
    if (P == Prec) {
        L.First = NULL;
        P->next = NULL;
    } else {
        Prec->next = P->next;
        P->next = NULL;
        if (P == L.First) {
            L.First = Prec->next;
        }
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == NULL) {
        P = NULL;
        return;
    }
    if (L.First->next == L.First) {
        P = L.First;
        L.First = NULL;
    } else {
        address prev = L.First;
        address cur = L.First->next;
        while (cur->next != L.First) {
            prev = cur;
            cur = cur->next;
        }
        P = cur;
        prev->next = L.First;
        P->next = NULL;
    }
}

address findElm(List L, infotype x) {
    if (L.First == NULL) return NULL;
    address P = L.First;
    do {
        if (P->info.nim == x.nim) return P;
        P = P->next;
    } while (P != L.First);
    return NULL;
}

void printInfo(List L) {
    if (L.First == NULL) {
        cout << "List kosong\n";
        return;
    }
    address P = L.First;
    int idx = 1;
    do {
        cout << idx << ". Nama : " << P->info.nama << endl;
        cout << "   Nim  : " << P->info.nim << endl;
        cout << "   JK   : " << P->info.jenis_kelamin << endl;
        cout << "   IPK  : " << P->info.ipk << endl;
        P = P->next;
        idx++;
    } while (P != L.First);
}