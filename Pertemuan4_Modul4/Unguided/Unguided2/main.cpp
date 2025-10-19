#include <iostream>
#include "SinglyList.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    address deletedNode;
    createList(L);
    
    // Membuat linked list seperti soal nomor 1
    P1 = alokasi(2);
    insertFirst(L, P1);
    
    P2 = alokasi(0);
    insertFirst(L, P2);
    
    P3 = alokasi(8);
    insertFirst(L, P3);
    
    P4 = alokasi(12);
    insertFirst(L, P4);
    
    P5 = alokasi(9);
    insertFirst(L, P5);
    
    // Menghapus node 9 menggunakan deleteFirst()
    deleteFirst(L, deletedNode);
    if (deletedNode != NULL) {
        dealokasi(deletedNode);
    }
    
    // Menghapus node 2 menggunakan deleteLast()
    deleteLast(L, deletedNode);
    if (deletedNode != NULL) {
        dealokasi(deletedNode);
    }
    
    // Menghapus node 8 menggunakan deleteAfter()
    // Mencari node sebelum node 8 (yaitu node 12)
    address Prec = L.first; // Node 12 adalah first sekarang
    deleteAfter(L, Prec, deletedNode);
    if (deletedNode != NULL) {
        dealokasi(deletedNode);
    }
    
    // Menampilkan linked list setelah penghapusan
    printInfo(L);
    
    // Menampilkan jumlah node
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;
    
    // Menghapus seluruh node
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
    
    return 0;
}