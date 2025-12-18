#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;     
    adrEdge firstEdge; 
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);

adrNode findNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph N1, infoGraph N2); // Undirected

void printGraph(Graph G);
void printDFS(Graph G, adrNode N);
void printBFS(Graph G, adrNode N);

#endif