#include "stack.h"
#include <iostream>
#include <limits>
using namespace std;

void CreateStack(Stack &S){
    S.top = -1;
}
void push(Stack &S, infotype x){
    if(!isFull(S)){
        S.top++;
        S.data[S.top] = x;
    }else{
        cout << "Stack is full!" << endl;
    }
}

infotype pop(Stack &S ){
    if (isEmpty(S)){
        cout << "Stack is empty!" << endl;
        return -1; // Return an invalid value or handle error appropriately
    }else{
        infotype x = S.data[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S){
    if(isEmpty(S)){
        cout << "Stack is empty!" << endl;
    }else{
        for(int i = S.top; i >= 0; i--){
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S){
    Stack tempStack;
    CreateStack(tempStack);
    while(!isEmpty(S)){
        infotype x = pop(S);
        push(tempStack, x);
    }
    S = tempStack;
}

bool isFull(Stack S){
    return S.top == 19;
}

bool isEmpty(Stack S){
    return S.top == -1;
}

void pushAscending(Stack &S, infotype x){
    if(isFull(S)){
        cout << "Stack is full!" << endl;
        return;
    }

    Stack tempStack;
    CreateStack(tempStack);

    // Pindahkan elemen dari S ke tempStack sampai menemukan posisi yang tepat
    while(!isEmpty(S) && S.data[S.top] > x){
        infotype y = pop(S);
        push(tempStack, y);
    }

    // Masukkan elemen baru
    push(S, x);

    // Kembalikan elemen dari tempStack ke S
    while(!isEmpty(tempStack)){
        infotype y = pop(tempStack);
        push(S, y);
    }
}

void getInputStream(Stack &S) {
    char c;

    cout << "Masukkan input: ";

    cin.get(c);

    while (c != '\n') {
        push(S, c - '0'); 
        cin.get(c);
    }
}
