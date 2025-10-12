#include <iostream>
using namespace std;

struct Node { float data; Node* next;};
struct List { Node* head;};

void BuatListKosong(List* L) { L->head = NULL;}

Node* BuatElemen(float X) {
    Node* elm = new Node;
    elm->data = X;
    elm->next = NULL;
    return elm;
}

void InsertAscending(List* L, float X) {
    Node* elm = BuatElemen(X);
    if (L->head == NULL || X < L->head->data) {
        elm->next = L->head; L->head = elm;
        return;
    }
    Node* current = L->head;
    while (current->next != NULL && current->next->data < X) {
        current = current->next;
    }
    elm->next = current->next;
    current->next = elm;
}

void CetakList(List* L) {
    Node* current = L->head;
    while (current != NULL) {
        cout << current->data;
        if (current->next != NULL) cout << " -> ";
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

void InputMultipleData(List* L) {
    int jumlah;
    cout << "Berapa banyak data yang ingin ditambahkan? ";
    cin >> jumlah;
    
    for (int i = 0; i < jumlah; i++) {
        float x;
        cout << "Masukkan data ke-" << (i + 1) << ": ";
        cin >> x;
        InsertAscending(L, x);
    }
}

int main() {
    List dataList;
    BuatListKosong(&dataList);
    
    float dataAwal[] = {10.5, 12.0, 20.9, 25.1};
    for (float x : dataAwal) {
        InsertAscending(&dataList, x);
    }
    cout << "List awal: ";
    CetakList(&dataList);
    
    // Input dari pengguna
    InputMultipleData(&dataList);
    cout << "List akhir: ";
    CetakList(&dataList);
    
    return 0;
}