#include "multilist.h"

address_anak alokasiAnak(infotype x) {
    address_anak P = new elemen_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertFirstAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        LA.first = PA;
        LA.last = PA;
    } else {
        PA->next = LA.first;
        LA.first->prev = PA;
        LA.first = PA;
    }
}

void insertLastAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        insertFirstAnak(LA, PA);
    } else {
        PA->prev = LA.last;
        LA.last->next = PA;
        LA.last = PA;
    }
}

void deleteFirstAnak(list_anak &LA, address_anak &PA) {
    if (LA.first != Nil) {
        PA = LA.first;
        if (LA.first == LA.last) {
            LA.first = Nil;
            LA.last = Nil;
        } else {
            LA.first = LA.first->next;
            LA.first->prev = Nil;
            PA->next = Nil;
        }
    }
}

void deleteLastAnak(list_anak &LA, address_anak &PA) {
    if (LA.first != Nil) {
        PA = LA.last;
        if (LA.first == LA.last) {
            LA.first = Nil;
            LA.last = Nil;
        } else {
            LA.last = LA.last->prev;
            LA.last->next = Nil;
            PA->prev = Nil;
        }
    }
}