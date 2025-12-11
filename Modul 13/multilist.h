#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct elemen_induk *address_induk;
typedef struct elemen_anak *address_anak;

struct elemen_anak {
    infotype info;
    address_anak next;
    address_anak prev;
};

struct list_anak {
    address_anak first;
    address_anak last;
};

struct elemen_induk {
    infotype info;
    list_anak anak;
    address_induk next;
    address_induk prev;
};

struct list_induk {
    address_induk first;
    address_induk last;
};

void createList(list_induk &L);
address_induk alokasi(infotype x);
void insertFirstInduk(list_induk &L, address_induk P);
void insertLastInduk(list_induk &L, address_induk P);
void insertAfterInduk(list_induk &L, address_induk Prec, address_induk P);
void deleteFirstInduk(list_induk &L, address_induk &P);
void deleteLastInduk(list_induk &L, address_induk &P);
void deleteAfterInduk(list_induk &L, address_induk Prec, address_induk &P);
address_induk findInduk(list_induk L, infotype x);

address_anak alokasiAnak(infotype x);
void insertFirstAnak(list_anak &LA, address_anak PA);
void insertLastAnak(list_anak &LA, address_anak PA);
void insertAfterAnak(list_anak &LA, address_anak Prec, address_anak PA);
void deleteFirstAnak(list_anak &LA, address_anak &PA);
void deleteLastAnak(list_anak &LA, address_anak &PA);
void deleteAfterAnak(list_anak &LA, address_anak Prec, address_anak &PA);
address_anak findAnak(list_anak LA, infotype x);

void printInfo(list_induk L);

#endif