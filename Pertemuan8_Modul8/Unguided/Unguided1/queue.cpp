#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = 0;

}
bool isEmptyQueue(Queue Q){
    return (Q.head == 0);
}
bool isFullQueue(Queue Q){
    return(Q.tail == MAX_QUEUE);
}
void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh" << endl;

    }
    if (isEmptyQueue(Q)){
        Q.head = 1;
        Q.tail = 1;
        Q.info[0] = x;
    }else{
        Q.tail++;
        Q.info[Q.tail - 1] = x;
    }
    
}
infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "queue kosong" << endl;
        return -1;
    }
    infotype hasil = Q.info[0];
    for (int i = 0; i < Q.tail - 1; i++){
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail == 0){
        Q.head = 0;
    }
    return hasil;
}
void printInfo(Queue Q) {
    int H, T;

    // Konversi posisi HEAD & TAIL ke format tugas (0 → -1 untuk kosong)
    if (isEmptyQueue(Q)) {
        H = -1;
        T = -1;
    } else {
        H = Q.head - 1;   // HEAD selalu = 1 → ditampilkan sebagai 0
        T = Q.tail - 1;   // TAIL = jumlah elemen → ditampilkan indeks terakhir
    }

    // Cetak HEAD - TAIL
    cout << H << "  -  " << T << "  |  ";

    // Tampilkan isi queue
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = 0; i < Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}