#include "circularlist.h"
#include <iostream>

using namespace std;

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}

int main() {
    List L;
    CreateList(L);

    cout << "coba insert first, last, dan after" << endl;

    address P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);

    infotype x;
    x.nim = "07";
    address found = findElm(L, x);
    address P2 = createData("Cindi", "03", 'p', 3.5);
    if (found != NULL) insertAfter(L, found, P2);

    x.nim = "02";
    found = findElm(L, x);
    P2 = createData("Hilmi", "08", 'p', 3.3);
    if (found != NULL) insertAfter(L, found, P2);

    x.nim = "04";
    found = findElm(L, x);
    P2 = createData("Eli", "05", 'p', 3.4);
    if (found != NULL) insertAfter(L, found, P2);

    cout << "\nHasil printInfo():\n";
    printInfo(L);

    return 0;
}