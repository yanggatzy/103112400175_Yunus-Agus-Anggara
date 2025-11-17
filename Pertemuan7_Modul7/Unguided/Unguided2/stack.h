#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Stack {
    int data[20];
    int top;
} Stack;

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
bool isFull(Stack S);
bool isEmpty(Stack S);
void pushAscending(Stack &S, infotype x);
#endif