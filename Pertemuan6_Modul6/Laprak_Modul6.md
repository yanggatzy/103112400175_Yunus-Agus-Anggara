# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List(Bagian Pertama)</h1>
<p align="center">Yunus Agus Angara - 103112400175</p>

## Dasar Teori
Linked list atau senarai berantai merupakan salah satu struktur data dinamis yang terdiri dari sejumlah node atau simpul yang saling terhubung melalui pointer. Setiap node biasanya memiliki dua bagian utama, yaitu data dan pointer yang menunjuk ke node berikutnya [1]. Keunggulan linked list dibandingkan array adalah ukurannya yang fleksibel (tidak tetap), sehingga dapat menyesuaikan jumlah elemen secara dinamis saat program dijalankan.

### A. Linked List<br/>
Linked list digunakan untuk menyimpan dan mengelola data secara berantai, di mana setiap elemen memiliki referensi ke elemen lainnya. Berbeda dengan array yang menggunakan indeks, linked list menggunakan pointer untuk menghubungkan setiap elemen. Jenis-jenis linked list antara lain:
#### 1. Singly Linked List
Setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya. Arah traversal hanya bisa dilakukan satu arah, dari awal (head) menuju akhir (tail).
#### 2. Doubly Linked List
Setiap node memiliki dua pointer, yaitu next dan prev, sehingga traversal bisa dilakukan dua arah baik maju maupun mundur. Struktur ini mempermudah operasi seperti insert, delete, dan search di posisi mana pun dalam list [2].
#### 3. Circular Linked List
Merupakan variasi dari singly atau doubly linked list, di mana node terakhir akan menunjuk kembali ke node pertama, membentuk struktur melingkar.

### B. Doubly Linked List<br/>
Doubly linked list adalah bentuk lanjutan dari linked list yang setiap nodenya memiliki dua pointer, yaitu:
- next → menunjuk ke node setelahnya, dan
- prev → menunjuk ke node sebelumnya.

Struktur ini memungkinkan operasi pencarian dan penghapusan dilakukan dari dua arah dengan efisiensi yang lebih baik. Meskipun membutuhkan lebih banyak memori karena dua pointer di setiap node, keunggulannya adalah waktu akses yang lebih cepat untuk traversal dan kemudahan dalam modifikasi list.
#### 1. Struktur Node
Setiap node terdiri dari:
- Info/data: berisi informasi (misalnya data kendaraan atau makanan),
- Pointer next: menunjuk ke node berikutnya,
- Pointer prev: menunjuk ke node sebelumnya.
#### 2. Operasi Utama Doubly Linked List
Operasi yang umum dilakukan pada doubly linked list antara lain:
- CreateList: membuat list kosong.
- InsertFirst / InsertLast: menambah elemen di awal atau akhir list.
- DeleteFirst / DeleteLast / DeleteByValue: menghapus elemen berdasarkan posisi atau nilai tertentu.
- FindElm: mencari node berdasarkan kunci tertentu (misalnya nomor polisi).
- PrintInfo: menampilkan isi list dari awal hingga akhir.
#### 3. Keunggulan Doubly Linked List
- Dapat diakses dua arah (maju dan mundur).
- Mudah dalam operasi insert dan delete pada posisi mana pun tanpa perlu traversal penuh.
- Cocok untuk aplikasi yang membutuhkan navigasi dua arah seperti editor teks, browser history, playlist, dan struktur antrian dinamis [2].

## Guided 

### 1. Insert Double linked List
listMakanan.h
```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif
```

listMakanan.cpp
```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```

main.cpp
```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
program membahas penerapan dasar dari doubly linked list dengan operasi penambahan dan penghapusan elemen pada struktur data yang terdiri dari node berisi informasi serta dua pointer yaitu next dan prev. Program pertama berfokus pada proses insert atau penambahan data ke dalam list, di mana setiap node baru dapat dimasukkan di posisi awal, akhir, maupun di antara dua node lain. Proses ini memanfaatkan pointer prev dan next untuk menjaga keterhubungan dua arah antar node sehingga operasi penyisipan dapat dilakukan tanpa kehilangan koneksi antar elemen. Dengan adanya dua pointer tersebut, traversal atau penelusuran list bisa dilakukan dari depan ke belakang maupun sebaliknya.

### 2. Delete Double Linked List
Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```

Doublylist.cpp
```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```

main.cpp
```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}

```
program kedua, berfokus pada operasi delete atau penghapusan elemen dari list. Penghapusan dilakukan dengan berbagai kondisi, yaitu menghapus elemen pertama, elemen terakhir, elemen di tengah, maupun ketika list hanya memiliki satu elemen. Untuk mendukung hal tersebut, digunakan fungsi findElm() yang berguna mencari node berdasarkan nilai tertentu (misalnya nomor polisi kendaraan) sebelum proses penghapusan dilakukan. Kemudian, fungsi deleteByNopol() akan memeriksa posisi node tersebut dan menghapusnya dengan menyesuaikan pointer next dan prev dari node di sekitarnya agar hubungan antar node tetap terjaga. Proses ini memperlihatkan keunggulan doubly linked list dibandingkan singly linked list karena pointer prev membuat penghapusan elemen di tengah menjadi lebih mudah tanpa perlu melakukan traversal penuh dari awal list.


## Unguided 

### 1. (isi dengan soal unguided 1)

Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

struct kendaraan {
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

// Tipe list
struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
void deleteByNopol(List &L, string nopol);
void printInfo(List L);

#endif

```

Doublylist.cpp
```C++
#include "DoublyList.h"
using namespace std;

void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = Nil;
        L.last = Nil;
    } else {
        P = L.last;
        L.last = P->prev;
        L.last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}

void deleteByNopol(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == Nil) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan.\n";
        return;
    }

    if (P == L.first) {
        deleteFirst(L, P);
    } else if (P == L.last) {
        deleteLast(L, P);
    } else {
        address Prec = P->prev;
        deleteAfter(Prec, P);
    }

    cout << "Data dengan nomor polisi " << nopol << " berhasil di hapus.\n";
    dealokasi(P);
}

void printInfo(List L) {
    if (L.first == Nil) {
        cout << "List kosong\n";
        return;
    }

    cout << "DATA LIST 1\n\n";
    address P = L.first;
    while (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna : " << P->info.warna << endl;
        cout << "Tahun : " << P->info.thnBuat << endl << endl;
        P = P->next;
    }
}

```

main.cpp
```C++
#include "DoublyList.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype x;
    string nopolCari, nopolHapus;
    int n;

    cout << "Masukkan jumlah data kendaraan: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan Nomor Polisi : ";
        cin >> x.nopol;

        // Cek apakah nopol sudah ada
        address cek = findElm(L, x.nopol);
        if (cek != Nil) {
            cout << "Nomor Polisi sudah terdaftar\n\n";
            i--; // ulangi input
            continue;
        }

        cout << "Masukkan Warna Kendaraan : ";
        cin >> x.warna;
        cout << "Masukkan Tahun Kendaraan : ";
        cin >> x.thnBuat;
        cout << endl;

        address P = alokasi(x);
        insertLast(L, P);
    }

    // Cetak semua data kendaraan
    printInfo(L);

    // Cari kendaraan berdasarkan nopol
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> nopolCari;
    cout << endl;

    address hasil = findElm(L, nopolCari);
    if (hasil != Nil) {
        cout << "Nomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna : " << hasil->info.warna << endl;
        cout << "Tahun : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << endl;

    // Hapus kendaraan berdasarkan nopol
    cout << "Masukan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;
    cout << endl;

    deleteByNopol(L, nopolHapus);
    cout << endl;

    // Tampilkan data setelah penghapusan
    printInfo(L);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_6](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan6_Modul6/Unguided/Output-Unguided1-Modul6.png) 

##### Output 2
![Screenshot Output Unguided 2_6](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan6_Modul6/Unguided/Output-Unguided2-Modul6.png) 

##### Output 3
![Screenshot Output Unguided 3_6](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan6_Modul6/Unguided/Output-Unguided3-Modul6.png) 

Pada bagian unguided, praktikum dikembangkan lebih lanjut dengan membuat implementasi ADT (Abstract Data Type) Doubly Linked List secara modular menggunakan tiga file terpisah, yaitu DoublyList.h, DoublyList.cpp, dan main.cpp. File header (.h) berisi deklarasi struktur data dan fungsi, file implementasi (.cpp) berisi definisi fungsi-fungsi utama seperti insertLast, findElm, deleteByNopol, deleteFirst, deleteLast, dan deleteAfter, sedangkan file utama (main.cpp) digunakan untuk menjalankan program dan menampilkan hasilnya.

Program pada bagian ini menampilkan data kendaraan dengan atribut seperti nomor polisi, warna, dan tahun pembuatan. Pengguna diminta menentukan jumlah data kendaraan yang akan dimasukkan, kemudian program akan memeriksa apakah nomor polisi yang diinput sudah terdaftar atau belum menggunakan fungsi findElm(). Jika nomor polisi sudah ada, program akan menampilkan pesan bahwa data duplikat tidak dapat dimasukkan. Setelah semua data dimasukkan, program menampilkan seluruh isi list dengan urutan tertentu. Selanjutnya, pengguna dapat mencari kendaraan tertentu berdasarkan nomor polisi dan menghapus data kendaraan yang diinginkan menggunakan fungsi deleteByNopol(), yang di dalamnya memanfaatkan deleteFirst, deleteLast, dan deleteAfter tergantung posisi data yang akan dihapus.

Program ini menunjukkan bagaimana konsep pointer dua arah bekerja dalam struktur data dinamis untuk mendukung proses penambahan, pencarian, dan penghapusan data dengan efisien. Selain itu, implementasi modular juga membuat kode menjadi lebih terstruktur, mudah dipelihara, dan sesuai dengan prinsip pemrograman berorientasi abstraksi data.

## Kesimpulan
Doubly linked list merupakan struktur data yang efisien untuk manipulasi data dinamis karena setiap elemen memiliki dua arah koneksi (prev dan next). Dengan struktur ini, operasi seperti insert, delete, dan search dapat dilakukan dari dua arah tanpa kehilangan referensi node.
Dibandingkan dengan singly linked list, doubly linked list lebih fleksibel dan efisien pada kasus traversal dua arah, meskipun membutuhkan memori tambahan.
Implementasi pada praktikum ini juga menunjukkan pentingnya modularisasi kode dengan memisahkan deklarasi (.h), implementasi (.cpp), dan eksekusi utama (main.cpp).

## Referensi
[1] Rahmawati, D., & Hidayat, T. (2020). Analisis Efisiensi Struktur Data Linked List dalam Penyimpanan Dinamis pada Bahasa C++. Jurnal Teknologi Informasi dan Komputer (JTIK), 6(2), 85–93.
[2] Siregar, F., & Santoso, A. (2021). Implementasi Doubly Linked List pada Sistem Manajemen Data Dinamis Berbasis Pointer di C++. Jurnal Ilmiah Informatika dan Komputer (JIIK), 9(3), 112–120.
