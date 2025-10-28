#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil)
        L.first->prev = P;
    else
        L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil)
        L.last->next = P;
    else
        L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address Prec) {
    P->next = Prec->next;
    P->prev = Prec;
    if (Prec->next != Nil)
        Prec->next->prev = P;
    else
        L.last = P;
    Prec->next = P;
}

void printForward(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void printBackward(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->prev;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    if (P != Nil) {
        L.first = P->next;
        if (L.first != Nil)
            L.first->prev = Nil;
        else
            L.last = Nil;
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.last;
    if (P != Nil) {
        L.last = P->prev;
        if (L.last != Nil)
            L.last->next = Nil;
        else
            L.first = Nil;
        P->next = Nil;
        P->prev = Nil;
    }
}


void smartInsert(List &L, infotype X) {
    address P = alokasi(X);

    if (L.first == Nil) {
        insertFirst(L, P);
        cout << "Smart Insert: List kosong, insert " << X << " di first" << endl;
        return;
    }

    if (X < L.first->info) {
        insertFirst(L, P);
        cout << "Smart Insert: " << X << " < first, insert di first" << endl;
        return;
    }

    if (X % 2 == 0) {
        insertLast(L, P);
        cout << "Smart Insert: " << X << " genap, insert di last" << endl;
        return;
    }

    if (X > L.last->info) {
        insertLast(L, P);
        cout << "Smart Insert: " << X << " ganjil, lebih besar dari last, insert di last" << endl;
        return;
    }

    address Q = L.first;
    while (Q->next != Nil && !(Q->info == 5 && Q->next->info == 7)) {
        Q = Q->next;
    }

    if (Q->next != Nil) {
        insertAfter(L, P, Q);
        cout << "Smart Insert: " << X << " di antara 5 dan 7" << endl;
    } else {
        insertLast(L, P);
        cout << "Smart Insert: kondisi lain, insert di last" << endl;
    }
}

int conditionalDelete(List &L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        address nextP = P->next;
        if (P->info % 2 != 0) {
            if (P == L.first)
                deleteFirst(L, P);
            else if (P == L.last)
                deleteLast(L, P);
            else {
                P->prev->next = P->next;
                P->next->prev = P->prev;
            }
            dealokasi(P);
            count++;
        }
        P = nextP;
    }
    return count;
}

void deleteByValue(List &L, infotype X) {
    address P = L.first;
    while (P != Nil && P->info != X) {
        P = P->next;
    }
    if (P == Nil) {
        cout << "Nilai " << X << " tidak ditemukan" << endl;
        return;
    }

    if (P == L.first)
        deleteFirst(L, P);
    else if (P == L.last)
        deleteLast(L, P);
    else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }
    cout << "Nilai " << X << " berhasil dihapus" << endl;
    dealokasi(P);
}

void deleteAll(List &L) {
    address P;
    int count = 0;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
        count++;
    }
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
}


int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    cout << "ADVANCED OPERATIONS" << endl;
    cout << "SMART INSERT DEMO" << endl;

    smartInsert(L, 5);
    smartInsert(L, 3);
    smartInsert(L, 8);
    smartInsert(L, 6);
    smartInsert(L, 4);
    smartInsert(L, 7);

    cout << "\nHasil Smart Insert:" << endl;
    cout << "Forward: ";
    printForward(L);
    cout << "Backward: ";
    printBackward(L);

    cout << "\nCONDITIONAL DELETE" << endl;
    cout << "Sebelum Conditional Delete: ";
    printForward(L);
    int deleted = conditionalDelete(L);
    cout << "Conditional Delete: " << deleted << " elemen ganjil dihapus" << endl;
    cout << "Setelah Conditional Delete: ";
    printForward(L);

    cout << "\nDELETE BY VALUE DEMO" << endl;
    deleteByValue(L, 6);
    deleteByValue(L, 10);
    cout << "List akhir: ";
    printForward(L);

    cout << "\nDELETE ALL DEMO" << endl;
    deleteAll(L);

    return 0;
}