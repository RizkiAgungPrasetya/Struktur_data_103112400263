#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEL 20
#define NIL -1

typedef int infotype;

struct stack
{
    infotype info[MaxEL];
    int top;
};

void CreateStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void Push(Stack &s, infotype x);
infotype Pop(Stack &s);
void printInfo(Stack s);
void balikStack(Stack s);

#endif
