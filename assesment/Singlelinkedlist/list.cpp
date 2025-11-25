#include "list.h"
#include <iostream>

void createList(List &L) {
    L.head = NULL;
}

void insertAkhir(List &L, string nama) {
    Node* baru = new Node();
    baru->nama = nama;
    baru->next = NULL;

    if (L.head == NULL) {
        L.head = baru;
    } else {
        Node* temp = L.head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void deleteNama(List &L, string nama) {
    if (L.head == NULL) {
        cout << "List kosong\n";
        return;
    }

    if (L.head->nama == nama) {
        Node* hapus = L.head;
        L.head = L.head->next;
        delete hapus;
        return;
    }

    Node* temp = L.head;
    while (temp->next != NULL && temp->next->nama != nama) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Nama tidak ditemukan\n";
        return;
    }

    Node* hapus = temp->next;
    temp->next = temp->next->next;
    delete hapus;
}

void viewList(List L) {
    if (L.head == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node* temp = L.head;
    while (temp != NULL) {
        cout << temp->nama << " ";
        temp = temp->next;
    }
    cout << endl;
}

int hitungGenap(List L) {
    int count = 0;
    Node* temp = L.head;

    while (temp != NULL) {
        if (temp->nama.length() % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}
