#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    list_induk L;
    createList(L);

    address_induk P1 = alokasi(1);
    insertLastInduk(L, P1);
    
    address_induk P2 = alokasi(2);
    insertLastInduk(L, P2);

    insertLastAnak(P1->anak, alokasiAnak(10));
    insertLastAnak(P1->anak, alokasiAnak(11));
    
    insertLastAnak(P2->anak, alokasiAnak(20));
    insertFirstAnak(P2->anak, alokasiAnak(19));


    printInfo(L);

    cout << "Menghapus anak terakhir dari Induk 1..." << endl;
    address_anak PDel;
    deleteLastAnak(P1->anak, PDel);
    
    printInfo(L);

    return 0;
}