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

int getSize(Node* head) {//menghitung ukuran linked list
    int count = 0;
    for (Node* temp = head; temp; temp = temp->next) count++;
    return count;
}

Node* getNodeAt(Node* head, int index) {//mendapatkan node pada index tertentu
    int count = 0;
    for (Node* temp = head; temp; temp = temp->next, count++) {
        if (count == index) return temp;
    }
    return nullptr;
}

void printList(Node* head) {//menampilkan linked list
    cout << "BINARYSEARCH PADA LINKED LIST" << endl;
    cout << "Linked List: -> ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}

Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getSize(head) - 1;
    int iterasi = 1;

    cout << "\nMencari nilai: " << key << endl;
    cout << "\nProses Pencarian:\n" << endl;

    while (left <= right) {
        int mid = (right + left) / 2;
        Node* midNode = getNodeAt(head, mid);
        
        if (!midNode) break;
        cout << "Iterasi ke-" << iterasi++ << ": Mid = " << midNode->data << "(indeks tengah)";
        if (midNode->data == key) {
            cout << "- DITEMUKAN!\n\n";
            cout << "Hasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat Node: " << midNode << endl;
            cout << "Data Node: " << midNode->data << endl;
            cout << "Node Berikutnya: " << midNode->next << endl;
            return midNode;
        }
        if (midNode->data < key) {
            cout << "-> Cari dibagian kanan" << endl;
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
    }
    cout << "Tidak ada elemen tersisa"<< endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!"<< endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    printList(head);
    binarySearch(head, 40);
    cout << endl;
    binarySearch(head, 25);
    return 0;
}