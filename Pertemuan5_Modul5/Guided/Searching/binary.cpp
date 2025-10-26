#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs bianry search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}