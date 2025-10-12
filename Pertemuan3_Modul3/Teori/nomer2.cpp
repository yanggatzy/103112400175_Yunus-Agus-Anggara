#include <iostream>
using namespace std;

struct Node { float data; Node *next; };
Node *head, *tail;

bool CariNilai(float X) {
    Node *current = head;
    while(current != NULL) {
        if(current->data == X) return true;
        current = current->next;
    }
    return false;
}

void HapusElemen(float X) {
    if (head == NULL) { cout << "List Kosong" << endl; return;}
    if (!CariNilai(X)) { cout << X << " tidak ditemukan" << endl; return;}

    Node *prev = NULL;
    Node *current = head;
    
    while(current != NULL && current->data != X) { prev = current; current = current->next;}
    if(current != NULL) {
        if(prev == NULL) {
            head = head->next;
            delete current;
            cout << X << " di awal dihapus" << endl;
        }
        else if(current->next == NULL) {
            prev->next = NULL;
            tail = prev;
            delete current;
            cout << X << " di akhir dihapus" << endl;
        }
        else {
            Node *hapus = current->next;
            current->next = hapus->next;
            if(hapus == tail) tail = current;
            delete hapus;
            cout << "Elemen setelah " << X << " dihapus" << endl;
        }
    }
}

void PrintList() {
    Node *current = head;
    while(current != NULL) {
        cout << current->data;
        if(current->next != NULL) cout << " -> ";
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    // Inisialisasi list: 15 -> 30 -> 40 -> 50
    head = new Node{15, NULL};
    head->next = new Node{30, NULL};
    head->next->next = new Node{40, NULL};
    head->next->next->next = new Node{50, NULL};
    tail = head->next->next->next;

    cout << "List awal: ";
    PrintList();

    float angka;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angka;
    
    HapusElemen(angka);
    cout << "List setelah penghapusan: ";
    PrintList();

    return 0;
}