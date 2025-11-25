#include "Queue.h"
#include <iostream>
#include <iomanip>
using namespace std;

void createQueue(Queue &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(Queue Q) {
    return (Q.Tail == MAX - 1);
}

void enQueue(Queue &Q, Paket p) {
    if (isFull(Q)) {
        cout << "Queue penuh! Tidak bisa menambah data." << endl;
        return;
    }
    
    if (isEmpty(Q)) {
        Q.Head = 0;
        Q.Tail = 0;
    } else {
        Q.Tail++;
    }
    
    Q.dataPaket[Q.Tail] = p;
    cout << "Data paket berhasil ditambahkan!" << endl;
}

void deQueue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong! Tidak ada data untuk dihapus." << endl;
        return;
    }
    
    cout << "Data paket berhasil dihapus: " << Q.dataPaket[Q.Head].KodeResi << " - " << Q.dataPaket[Q.Head].NamaPengirim << endl;
    
    if (Q.Head == Q.Tail) {
        Q.Head = -1;
        Q.Tail = -1;
    } else {
        Q.Head++;
    }
}

void viewQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    
    cout << "\n=== DATA QUEUE PAKET ===" << endl;
    cout << setw(10) << "Kode Resi" << setw(15) << "Pengirim" 
         << setw(8) << "Berat" << setw(12) << "Tujuan" << endl;
    cout << "------------------------------------------" << endl;
    
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << setw(10) << Q.dataPaket[i].KodeResi
             << setw(15) << Q.dataPaket[i].NamaPengirim
             << setw(8) << Q.dataPaket[i].BeratBarang
             << setw(12) << Q.dataPaket[i].Tujuan << endl;
    }
}

int TotalBiayaPengiriman(Queue Q) {
    if (isEmpty(Q)) {
        return 0;
    }
    
    int totalBerat = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBerat += Q.dataPaket[i].BeratBarang;
    }
    
    return totalBerat * 8250;
}