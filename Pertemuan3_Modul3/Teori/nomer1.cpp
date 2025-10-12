#include <iostream>
using namespace std;

struct Node { // a. Deklarasi list dari linked list
    float data;
    Node* next;
};

struct List{
    Node* head;
};

void BuatListKosong(List* L) {  // b. Prosedur untuk membuat sebuah list kosong
    L->head = NULL;
}

Node* BuatElemen(float X) {  // c. Prosedur untuk membuat elemen baru bernama "elm" yang memiliki nilai "X"
    Node* elm = new Node;
    elm->data = X;
    elm->next = NULL;
    return elm;
}

void InsertAscending(List* L, float X) { // d. Prosedur insertAscending 
    Node* elm = BuatElemen(X);
    
    // Kasus 1: List kosong
    if (L->head == NULL) {
        L->head = elm;
        return;
    }
    
    // Kasus 2: Insert di depan
    if (X < L->head->data) {
        elm->next = L->head;
        L->head = elm;
        return;
    }
    
    // Kasus 3: Insert di tengah atau akhir
    Node* current = L->head;
    while (current->next != NULL && current->next->data < X) {
        current = current->next;
    }
    
    elm->next = current->next;
    current->next = elm;
}

void CetakList(List* L) { // Prosedur untuk mencetak isi dari linked list
    Node* current = L->head;
    while (current != NULL) {
        cout << current->data;
        if (current->next != NULL) cout << " -> ";
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    List dataList;
    BuatListKosong(&dataList);
    
    
    InsertAscending(&dataList, 10.5);
    InsertAscending(&dataList, 12.0);
    InsertAscending(&dataList, 20.9);
    InsertAscending(&dataList, 25.1);

    InsertAscending(&dataList, 15.3);
    InsertAscending(&dataList, 5.7);
    
    cout << "Linked List Ascending: ";
    CetakList(&dataList);
    
    return 0;
}