# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE </h1>
<p align="center">Yunus Agus Anggara - 103112400175</p>

## Dasar Teori
Struktur data queue (antrian) adalah struktur data linear yang mengikuti prinsip FIFO (First In First Out), yaitu elemen yang pertama masuk adalah elemen yang pertama keluar. Konsep ini banyak digunakan pada proses komputasi yang membutuhkan pengolahan data secara berurutan seperti CPU scheduling, buffering, resource sharing, serta pemrosesan data pada sistem jaringan dan basis data [1].

### A. Konsep Dasar Queue<br/>
Queue terdiri dari dua operasi dasar utama, yaitu enqueue (menambah elemen ke bagian belakang/tail) dan dequeue (menghapus elemen dari bagian depan/head). Menurut penelitian oleh Rahman & Hidayat (2019), struktur data queue sangat efektif digunakan untuk proses yang memerlukan pengaturan aliran data secara terstruktur karena mampu mengurangi bottleneck ketika data harus diproses secara berurutan [1].
#### 1. Operasi Enqueue
Operasi enqueue adalah proses memasukkan elemen baru ke bagian belakang antrian. Pada implementasi queue berbasis linked list, penambahan elemen dilakukan dengan membuat node baru dan menempelkannya pada pointer tail.
#### 2. Operasi Dequeue
Operasi dequeue mengambil dan menghapus elemen dari bagian depan (head). Pada queue berbasis array, proses ini dapat melibatkan penggeseran elemen atau menggunakan metode circular agar lebih efisien.
#### 3. Kondisi Queue (Full dan Empty)
Queue dapat berada pada dua kondisi penting:
- Empty → terjadi ketika tidak ada elemen dalam antrian.
- Full → khusus untuk queue berbasis array, terjadi ketika kapasitas maksimum array telah terisi.
Penanganan kondisi ini sangat penting untuk mencegah overflow atau underflow.

### B. Jenis dan Representasi Queue<br/>
Menurut jurnal oleh Prasetyo & Sari (2020), representasi queue dapat dibagi menjadi dua kelompok besar: array-based queue dan linked-list-based queue, masing-masing memiliki kelebihan pada efisiensi memori dan fleksibilitas dalam alokasi ruang [2].
#### 1. Queue Berbasis Array
Queue yang menggunakan array memiliki ukuran tetap. Terdapat tiga mekanisme implementasi:
- Alternatif 1: head tetap, tail bergerak → elemen bergeser saat dequeue.
- Alternatif 2: head bergerak, tail bergerak → indeks head dan tail berubah tanpa penggeseran data.
- Alternatif 3: circular queue → head dan tail berputar menggunakan operasi modulo.
Circular queue lebih efisien karena tidak membuang ruang kosong dalam array.

#### 2. Queue Berbasis Linked List
Queue dengan linked list bersifat dinamis sehingga tidak bergantung pada ukuran array. Pada implementasi ini, setiap elemen adalah node yang saling terhubung, sehingga operasi enqueue dan dequeue menjadi lebih fleksibel tanpa perlu memindahkan elemen di memori.
#### 3. Aplikasi Queue dalam Komputasi Modern
Queue digunakan pada:
- Sistem operasi untuk task scheduling,
- Simulasi antrean pelanggan,
- Sistem jaringan seperti manajemen paket,
- Struktur data pendukung seperti BFS (Breadth First Search).

## Guided 

### 1. QUEUE 
queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL 

#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    int dataAngka;
    address next;
} ;

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchQueue(queue Q, int data);

#endif

```
queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchQueue(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah updateQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchQueue(Q, 4);
    searchQueue(Q, 9);

    return 0;
}
```
Pada guided pertama, mahasiswa diperkenalkan pada konsep dasar stack dan cara kerjanya melalui contoh yang sudah disiapkan pada modul. Tahap ini membantu mahasiswa memahami prinsip LIFO serta mengenali fungsi-fungsi dasar seperti push, pop, dan peek sebelum masuk ke implementasi program.
### 2. QUEUE REPRESENTASI ARRAY
queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
main.cpp
```C++

#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" <<  endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Pada guided kedua, mahasiswa mulai mempraktikkan langsung langkah-langkah yang diberikan untuk mengimplementasikan operasi stack dalam program. Dengan mengikuti instruksi secara sistematis, mahasiswa dapat melihat bagaimana perubahan terjadi pada struktur stack setiap kali operasi dilakukan, sehingga memperkuat pemahaman konsep secara terarah.


## Unguided 

### 1.Soal Unguided 1
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file“queue.h”.Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
queue.cpp
```C++
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
```
main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_8](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan8_Modul8/Unguided//Unguided1/Output-Unguided1-Modul8.png) 


Pada unguided pertama, mahasiswa diberi tugas untuk membuat program stack secara mandiri tanpa instruksi detail, sehingga mendorong kemampuan analisis dalam menentukan alur logika dan struktur program.

### 2. Soal Unguided 2
Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).
queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;

}
bool isEmptyQueue(Queue Q){
    return Q.tail < Q.head;
}
bool isFullQueue(Queue Q){
    return(Q.tail == MAX_QUEUE - 1);
}
void enqueue(Queue &Q, infotype x){
   
   if(!isFullQueue(Q)){
    Q.tail++;
    Q.info[Q.tail] = x;
   }else{
        cout << "queue penuh \n";
   }
    
    
}
infotype dequeue(Queue &Q){
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head];
        Q.head++;

        // reset ketika kosong
        if (Q.head > Q.tail) {
            Q.head = 0;
            Q.tail = -1;
        }
        return x;
    }
    cout << "Queue kosong!\n";
    return -1;
   
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << "\n";
}

```
main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_8](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan8_Modul8/Unguided//Unguided2/Output-Unguided2-Modul8.png) 


Pada unguided kedua, mahasiswa diminta mengembangkan fitur tambahan atau memodifikasi kode agar lebih lengkap dan sesuai kebutuhan tugas, sehingga melatih kreativitas serta pemahaman konsep stack dalam situasi yang lebih bebas.

### 3. Soal Unguided 3
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).
queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
queue.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;

}
bool isEmptyQueue(Queue Q){
    return(Q.head == -1 && Q.tail == -1);
}
bool isFullQueue(Queue Q){
    return((Q.tail + 1) % MAX_QUEUE == Q.head);
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "queue penuh" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;

    }else{
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }
    Q.info[Q.tail] = x;
}
infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        return -1;
    }
    infotype temp = Q.info[Q.head];
    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    }else{
        Q.head = (Q.head + 1) % MAX_QUEUE;
    }
    return temp;
}
void printInfo(Queue Q){
    cout << " " << Q.head << " - " << Q.tail << "\t | ";

    if(isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return;
    }

    int i = Q.head;
    while(true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAX_QUEUE;
    }
    cout << endl;
}
```
main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_8](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan8_Modul8/Unguided//Unguided3/Output-Unguided3-Modul8.png) 


Pada unguided ketiga, mahasiswa melakukan pengujian dan memastikan program stack berjalan dengan benar, termasuk memeriksa hasil push, pop, dan kondisi stack penuh atau kosong. Tahap ini membantu meningkatkan ketelitian dan kemampuan debugging.
## Kesimpulan
Secara keseluruhan, praktikum stack memungkinkan mahasiswa memahami konsep struktur data LIFO secara menyeluruh, mulai dari tahap guided yang terarah hingga unguided yang lebih mandiri. Melalui proses ini, mahasiswa dapat menguasai operasi push, pop, dan peek serta memahami bagaimana stack bekerja dalam penyimpanan dan pengelolaan data pada berbagai aplikasi pemrograman.

## Referensi
[1] Rahman, M. A., & Hidayat, T. (2019). Analisis Efektivitas Struktur Data Queue pada Sistem Antrian Digital. Jurnal Teknologi Informatika dan Komputer, 5(2), 112–120.
[2] Prasetyo, D., & Sari, R. (2020). Implementasi Struktur Data Queue Menggunakan Array dan Linked List dalam Pengembangan Sistem Pemrosesan Data. Jurnal Ilmu Komputer dan Aplikasi, 8(1), 45–53.
