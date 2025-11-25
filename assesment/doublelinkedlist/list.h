#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    Node* prev;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

void createList(List &L);
void insertAkhir(List &L, int nilai);
void deleteLast(List &L);
void viewDepan(List L);
void reverseList(List &L);

#endif
