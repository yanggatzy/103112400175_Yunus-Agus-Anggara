#include "list.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.head = NULL;
    L.tail = NULL;
}

void insertAkhir(List &L, int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->prev = NULL;
    baru->next = NULL;

    if (L.head == NULL) {
        L.head = L.tail = baru;
    } else {
        L.tail->next = baru;
        baru->prev = L.tail;
        L.tail = baru;
    }
}

void deleteLast(List &L) {
    if (L.tail == NULL) {
        cout << "List kosong\n";
        return;
    }

    if (L.head == L.tail) {
        delete L.tail;
        L.head = L.tail = NULL;
    } else {
        Node* hapus = L.tail;
        L.tail = L.tail->prev;
        L.tail->next = NULL;
        delete hapus;
    }
}

void viewDepan(List L) {
    if (L.head == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node* temp = L.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void reverseList(List &L) {
    Node* temp = L.head;
    Node* tukar = NULL;

    while (temp != NULL) {
        tukar = temp->prev;
        temp->prev = temp->next;
        temp->next = tukar;

        temp = temp->prev;  
    }

    if (tukar != NULL) {
        L.tail = L.head;
        L.head = tukar->prev;
    }
}
