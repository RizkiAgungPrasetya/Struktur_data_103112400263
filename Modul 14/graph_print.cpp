#include "graph.h"
#include <queue> 

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung dengan: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void resetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}

void dfsHelper(adrNode N) {
    if (N == NULL || N->visited) return;
    
    N->visited = true;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (!E->node->visited) {
            dfsHelper(E->node);
        }
        E = E->next;
    }
}

void printDFS(Graph G, adrNode N) {
    resetVisited(G); 
    dfsHelper(N);
}

void printBFS(Graph G, adrNode N) {
    resetVisited(G); 
    if (N == NULL) return;

    queue<adrNode> Q;
    Q.push(N);
    N->visited = true;

    while (!Q.empty()) {
        adrNode current = Q.front();
        Q.pop();
        cout << current->info << " ";
        adrEdge E = current->firstEdge;
        while (E != NULL) {
            if (!E->node->visited) {
                E->node->visited = true;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}