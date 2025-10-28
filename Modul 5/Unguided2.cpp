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

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
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

void deleteAfter(List &L, address &P, address R) {
    P = R->next;
    if (P != Nil) {
        R->next = P->next;
        if (P->next != Nil)
            P->next->prev = R;
        else
            L.last = R;
        P->next = Nil;
        P->prev = Nil;
    }
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
    if (P == L.first) {
        deleteFirst(L, P);
    } else if (P == L.last) {
        deleteLast(L, P);
    } else {
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
    cout << "TASK 1: DELETE OPERATIONS" << endl;

    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(2));

    cout << "List awal: ";
    printInfo(L);

    deleteByValue(L, 2);
    cout << "Setelah deleteByValue(2): ";
    printInfo(L);

    deleteByValue(L, 5);
    cout << "List tetap: ";
    printInfo(L);

    insertFirst(L, alokasi(4));
    insertFirst(L, alokasi(5));

    cout << "List setelah tambah data: ";
    printInfo(L);

    deleteAll(L);

    return 0;
}