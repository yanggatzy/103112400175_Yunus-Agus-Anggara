# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Yunus Agus Anggara - 103112400175</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas [1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Berbeda dengan array yang memiliki alokasi memori statis dan kontigu, linked list memiliki alokasi memori dinamis dan tidak kontigu, sehingga lebih fleksibel dalam penambahan dan penghapusan elemen.

### A. Konsep Dasar Singly Linked List<br/>
Singly Linked List (senarai berantai tunggal) adalah struktur data linear dimana setiap elemen (disebut node) terdiri dari dua bagian: data dan pointer yang menunjuk ke node berikutnya [2]. Node terakhir menunjuk ke NULL yang menandakan akhir dari list. Struktur ini disebut "singly" karena hanya memiliki satu arah penelusuran, yaitu dari kepala (head) ke ekor (tail).
#### 1. Struktur Node
Setiap node dalam singly linked list terdiri dari:
- Data: Menyimpan nilai atau informasi
- Next Pointer: Menunjuk ke node berikutnya dalam sequence

Dalam implementasi C++, struktur node biasanya didefinisikan sebagai struct yang berisi variabel data dan pointer next.
#### 2. Operasi Fundamental
Operasi dasar yang dapat dilakukan pada singly linked list meliputi [3]:
- Creation: Pembuatan list kosong
- Insertion: Penambahan node (di awal, di akhir, atau setelah node tertentu)
- Deletion: Penghapusan node (dari awal, dari akhir, atau node tertentu)
- Traversal: Penelusuran seluruh node dalam list
- Searching: Pencarian node dengan nilai tertentu
#### 3. Kompleksitas Waktu
Kompleksitas waktu operasi pada singly linked list bervariasi [1]:
- Insertion/Deletion di awal: O(1)
- Insertion/Deletion di akhir: O(n) jika tidak menyimpan tail pointer
- Access elemen tertentu: O(n)
- Search elemen: O(n)

### B. Implementasi dan Aplikasi<br/>
#### 1. Implementasi dalam Pemrograman
Dalam implementasinya, singly linked list memerlukan manajemen memori yang baik [2]. Setiap node dialokasikan secara dinamis menggunakan operator new dan harus didealokasi menggunakan delete untuk mencegah memory leak. Pointer handling yang tepat sangat penting untuk menjaga integritas struktur data.
#### 2. Aplikasi Praktis
Singly linked list memiliki berbagai aplikasi dalam pemrograman [3]:
- Implementasi stack dan queue
- Manajemen memory allocation
- Representasi polynomial expressions
- Implementation of graphs (adjacency list)
- Browser history navigation
#### 3. Kelebihan dan Keterbatasan
Kelebihan singly linked list [1]:
- Ukuran dinamis yang dapat menyesuaikan kebutuhan
- Efisien untuk operasi insert/delete di awal list
- Tidak memerlukan pre-allocation memory

Keterbatasan [2]:
- Akses elemen harus sequential
- Memori overhead untuk penyimpanan pointer
- Tidak support random access seperti array

## Guided 

### 1. Insert Singly Linked List
List.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

List.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

Main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program ini mendemonstrasikan implementasi singly linked list dengan operasi insertion. Program terdiri dari tiga file terpisah yang menunjukkan praktik modular programming yang baik. Data yang disimpan adalah informasi mahasiswa berupa nama, NIM, dan usia.

### 2. Delete Singly Linked List
List.h
```C++
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

List.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

Main.cpp
```C++

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini memperluas guided pertama dengan menambahkan operasi deletion yang komprehensif. Program menunjukkan bagaimana menghandle berbagai skenario penghapusan node dan manajemen memory yang benar.



## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut.

Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

Singlylist.cpp
```C++
#include <iostream>
#include "SinglyList.h"
using namespace std;

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info;
        if (P->next != NULL) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}
```

main.cpp
```C++
#include <iostream>
#include "SinglyList.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    createList(L);
    
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
    
    printInfo(L);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_4](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan4_Modul4/Unguided/Unguided1/Output-Unguided1-Modul4.png) 

Program ini mengimplementasikan ADT Singly Linked List sederhana dengan tipe data integer. Implementasi mengikuti prinsip abstract data type dengan pemisahan antara interface dan implementasi.

Struktur Program:
SinglyList.h: Deklarasi struktur data dan fungsi
SinglyList.cpp: Implementasi fungsi-fungsi ADT
main.cpp: Program utama untuk testing

Alur Eksekusi:
Program membuat list dan menyisipkan nilai 2, 0, 8, 12, 9 menggunakan insertFirst(). Karena insertFirst menambahkan di awal, urutan akhir dalam list adalah: 9 → 12 → 8 → 0 → 2.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```

Singlylist.cpp
```C++
#include <iostream>
#include "SinglyList.h"
using namespace std;

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info;
        if (P->next != NULL) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
    } else {
        P = L.first;
        L.first = L.first->next;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first->next == NULL) {
        P = L.first;
        L.first = NULL;
    } else {
        address last = L.first;
        address prev = NULL;
        
        while (last->next != NULL) {
            prev = last;
            last = last->next;
        }
        
        P = last;
        prev->next = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) {
        P = NULL;
    } else {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.first != NULL) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```

main.cpp
```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_4](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan4_Modul4/Unguided/Unguided2/Output-Unguided2-Modul4.png) 

Program ini mengembangkan unguided pertama dengan menambahkan operasi deletion dan fungsi utilitas. Program menunjukkan proses penghapusan node tertentu dan manajemen memory yang menyeluruh.

Operasi yang Dilakukan:
deleteFirst(): Menghapus node 9 (awal list)
deleteLast(): Menghapus node 2 (akhir list)
deleteAfter(): Menghapus node 8 (setelah node 12)
nbList(): Menghitung sisa node
deleteList(): Menghapus seluruh list

Alur Transformasi List:
Awal: 9 → 12 → 8 → 0 → 2
Setelah deleteFirst: 12 → 8 → 0 → 2
Setelah deleteLast: 12 → 8 → 0
Setelah deleteAfter: 12 → 0


## Kesimpulan
Berdasarkan praktikum modul 4 tentang Singly Linked List, dapat disimpulkan bahwa:

1. Singly Linked List merupakan struktur data dinamis yang efisien untuk operasi insert dan delete, khususnya di awal list, dengan kompleksitas waktu O(1).

2. Implementasi ADT yang baik memerlukan pemisahan antara interface (header file) dan implementasi (source file), serta manajemen memori yang tepat untuk mencegah memory leak.

3. Kelebihan utama linked list adalah kemampuannya untuk tumbuh dan menyusut secara dinamis selama runtime, serta tidak memerlukan alokasi memori yang kontigu seperti array.

4. Kekurangan linked list terletak pada akses elemen yang harus dilakukan secara sekuensial dengan kompleksitas O(n) dan kebutuhan memori tambahan untuk penyimpanan pointer.

5. Operasi dasar linked list meliputi creation, insertion, deletion, traversal, dan destruction, yang masing-masing memiliki karakteristik dan kompleksitas waktu berbeda-beda.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>
[3] Sahir, S. (2019). "Implementasi dan Analisis Linked List dalam Pemrograman C++". Jurnal Ilmu Komputer dan Teknologi Informasi, 12(2), 45-52.