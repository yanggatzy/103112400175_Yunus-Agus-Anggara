# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Yunus Agus Anggara - 103112400175</p>


## Dasar Teori
Linked List atau senarai berantai merupakan salah satu struktur data dinamis yang terdiri atas elemen-elemen yang disebut node [1]. Setiap node memiliki dua bagian utama, yaitu bagian data yang menyimpan nilai dan bagian pointer yang menunjuk ke node berikutnya. Struktur ini memungkinkan penyimpanan data yang fleksibel karena ukuran Linked List dapat bertambah atau berkurang selama program berjalan tanpa perlu mengalokasikan ulang memori seperti pada array.

Singly Linked List adalah jenis Linked List yang paling sederhana, di mana setiap node hanya menunjuk ke node berikutnya dan tidak memiliki pointer kembali ke node sebelumnya. Proses pencarian, penambahan, dan penghapusan data dilakukan secara sekuensial dari head hingga tail [2].

### A. Linear Search pada Linked List<br/>
Linear Search adalah metode pencarian yang dilakukan dengan memeriksa satu per satu elemen mulai dari awal hingga elemen yang dicari ditemukan atau mencapai akhir Linked List.
#### Ciri khas dari algotima ini adalah
1. Tidak memerlukan data yang terurut.
2. Kompleksitas waktu pencarian adalah O(n).
3. Implementasinya sederhana dan mudah diterapkan.
#### Kelebihan
- Cocok untuk dataset kecil.
- Mudah diimplementasikan dan dipahami.
#### Kekurangan
- Tidak efisien untuk dataset besar karena membutuhkan pengecekan satu per satu.

### B. Binary Search pada Linked List<br/>
Binary Search adalah algoritma pencarian yang bekerja dengan cara membagi data menjadi dua bagian secara berulang hingga menemukan elemen yang dicari. Namun, karena Linked List tidak mendukung akses langsung ke indeks elemen seperti array, implementasi Binary Search pada Linked List menjadi lebih kompleks [2].
#### Karakteristik
1. Data harus terurut secara ascending.
2. Proses pencarian dilakukan dengan menemukan node tengah di setiap iterasi.
3. Kompleksitas waktu secara teori adalah O(log n), tetapi pada Linked List bisa meningkat karena traversal.
#### Kelebihan
Lebih cepat dari Linear Search pada data besar yang sudah terurut.
#### Kekurangan
Kurang efisien pada Linked List karena tidak bisa langsung mengakses elemen tengah.

## Guided 

### 1. LINEARSEARCH SINGLE LINKED LIST

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
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
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
Program ini membuat Singly Linked List dengan tiga node berisi data 10, 20, dan 30. Fungsi linearSearch() digunakan untuk mencari nilai tertentu dengan menelusuri setiap node dari head. Jika nilai yang dicari ditemukan, fungsi mengembalikan pointer ke node tersebut, dan jika tidak, mengembalikan nullptr.
Konsepnya sederhana dan langsung: memeriksa satu per satu hingga data ditemukan.

### 2. BINARYSEARCH SINGLE LINKED LIST

```C++
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
```
Program ini menerapkan algoritma Binary Search pada Linked List yang datanya sudah terurut. Langkah pertama adalah menghitung ukuran Linked List, lalu menentukan node tengah (mid).
Jika nilai tengah sesuai dengan nilai yang dicari, pencarian berhenti. Jika tidak, pencarian dilanjutkan ke bagian kiri atau kanan berdasarkan perbandingan nilai tengah dengan key.
Program ini menunjukkan penerapan konsep Binary Search dalam struktur data Linked List meskipun dengan keterbatasan efisiensi.


## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma BinarySearch pada Linked List untuk mencari elemen tertentu. 
Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir

Petunjuk Tugas 1:
- Gunakan struktur Node dengan data integer dan pointer next
- Implementasikan fungsi append() untuk menambah node
- Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan
- Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar
- Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi
- Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian


```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_5](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan5_Modul5/Unguided/Output-Unguided1-Modul5.png) 


Program ini membuat Linked List dengan elemen 10, 20, 30, 40, 50 menggunakan fungsi append(). Kemudian dilakukan pencarian menggunakan algoritma Linear Search dengan menampilkan proses pencarian di setiap langkah, seperti node yang sedang diperiksa dan hasil akhirnya.
Apabila data ditemukan, program akan menampilkan alamat memori node, nilai data, serta node berikutnya. Jika tidak ditemukan, akan muncul pesan bahwa nilai tidak ditemukan. Implementasi ini memperlihatkan prinsip traversal Linked List secara berurutan dengan tampilan hasil pencarian yang informatif.

### 2. Implementasikan program C++ yang menggunakan algoritma LinearSearch pada Linked List untuk mencari elemen tertentu. 
Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan linear search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir

Petunjuk Tugas 2:
- Gunakan struktur Node dengan data integer dan pointer next
- Implementasikan fungsi append() untuk menambah node
- Implementasikan fungsi linearSearch() yang mengembalikan pointer ke node yang ditemukan
- Data dalam linked list tidak perlu terurut untuk linear search
- Tampilkan setiap langkah pencarian dan node yang sedang diperiksa
- Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian

```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
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
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_5](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan5_Modul5/Unguided/Output-Unguided2-Modul5.png) 


Program ini mengimplementasikan algoritma Linear Search pada Linked List.Proses pencarian dilakukan dengan menelusuri setiap node dari awal (head) hingga akhir list. Jika data pada node saat ini sama dengan nilai yang dicari (key), maka node tersebut dikembalikan sebagai hasil pencarian. Jika seluruh node sudah diperiksa dan data tidak ditemukan, fungsi mengembalikan nullptr.
Program juga memiliki fungsi append() untuk menambah node baru di akhir list, sehingga linked list dapat terbentuk secara dinamis.
Dengan algoritma ini, pencarian bersifat sekuensial (satu per satu), sehingga mudah diimplementasikan namun memiliki kompleksitas waktu O(n).

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa:
1. Linear Search cocok digunakan untuk data yang tidak terurut karena prosesnya sederhana dan mudah diimplementasikan.
2. Binary Search lebih efisien untuk data terurut, namun penerapannya dalam Linked List tidak seefisien pada array karena tidak dapat mengakses elemen secara langsung.
3. Pemahaman konsep pointer dan traversal node sangat penting untuk mengimplementasikan kedua metode pencarian ini.
4. Setiap algoritma memiliki kelebihan dan kelemahan tersendiri tergantung pada struktur data dan kondisi dataset yang digunakan.

## Referensi
[1] S. Priyanta, “Implementasi Struktur Data Linked List untuk Pengelolaan Data Dinamis,” Jurnal Teknologi Informasi dan Ilmu Komputer (JTIIK), vol. 6, no. 2, 2019.
[2] M. D. Nugroho, “Analisis dan Implementasi Single Linked List pada Pemrograman C++,” Jurnal Rekayasa Teknologi Informasi dan Komputer (JRTIK), vol. 1, no. 1, 2020.