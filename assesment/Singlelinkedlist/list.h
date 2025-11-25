#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct List {
    Node* head;
};

void createList(List &L);
void insertAkhir(List &L, string nama);
void deleteNama(List &L, string nama);
void viewList(List L);
int hitungGenap(List L);

#endif
