#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

#define MAX_QUEUE 5 

typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE]; 
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
void printInfo(Queue Q);
infotype dequeue(Queue &Q);

#endif