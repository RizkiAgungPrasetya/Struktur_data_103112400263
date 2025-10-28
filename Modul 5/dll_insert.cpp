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

void insertFirst(List &L, address P) {
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika lits kosong, set last juga ke P
    L.first = P; //Update first list menjadi P
}

void insertLast(List &L, address P, address R) {
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; 
    if (L.last != Nil) L.last->next = P;
    else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R) {
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika R bukan elemen terakhir, set prev elemen setelah R ke P
    else L.last = P; // Jika R adalah elemen terakhir, update last list menjadi P
    R->next = P; // Set pointer next dari R ke P
}

address alokasi(infotype x) {
    address P = new elmlist; // Alokasi memori untuk elemen baru
    P->info = x; // Set info elemen baru
    P->next = Nil; // Inisialisasi next ke Nil
    P->prev = Nil; // Inisialisasi prev ke Nil
    return P; // Kembalikan alamat elemen baru
}

void printInfo(List L) {
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P
        P = P->next; // Pindah ke elemen berikutnya
    }
    cout << endl;
}
int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    address P1 = alokasi(10);
    address P2 = alokasi(20);
    address P3 = alokasi(30);

    insertFirst(L, P1); // Insert 10 at the beginning
    insertLast(L, P2, L.last); // Insert 20 at the end
    insertAfter(L, P3, P1); // Insert 30 after 10

    printInfo(L); // Expected output: 10 30 20

    return 0;
}