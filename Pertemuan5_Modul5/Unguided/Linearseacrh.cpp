#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode =  new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next)temp = temp->next;
        temp->next = newNode;
    }
}

void printList(Node* head) {//menampilkan linked list
    cout << "LINEARSEARCH PADA LINKED LIST" << endl;
    cout << "Linked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}

void linearSearch(Node* head, int key) {
    cout << "\nMencari nilai: " << key << endl;
    cout << "\nProses Pencarian:\n";

    Node* current = head;
    int node = 1;

    while (current != nullptr) {
        cout << "Memeriksa node " << node << ":" << current->data ;

        if (current->data == key) {
            cout << " - DITEMUKAN!\n\n";
            cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node : " << current << endl;
            cout << "Data node   : " << current->data << endl;
            cout << "Node berikutnya: " << current->data<< endl;
            return;
        } else {
            cout << " (tidak sama)\n";
        }

        current = current->next;
        node++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
}

int main() {
    Node* head = nullptr;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    printList(head);
    linearSearch(head, 30); // Mencari nilai yang ada
    linearSearch(head, 25); // Mencari nilai yang tidak ada
    return 0;
}