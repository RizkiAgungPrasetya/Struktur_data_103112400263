#include "graph.h"

adrNode findNode(Graph &G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph N1, infoGraph N2) {
    adrNode p1 = findNode(G, N1);
    adrNode p2 = findNode(G, N2);

    if (p1 != NULL && p2 != NULL) {
        adrEdge e1 = new ElmEdge;
        e1->node = p2;
        e1->next = p1->firstEdge;
        p1->firstEdge = e1;

        adrEdge e2 = new ElmEdge;
        e2->node = p1;
        e2->next = p2->firstEdge;
        p2->firstEdge = e2;
    }
}