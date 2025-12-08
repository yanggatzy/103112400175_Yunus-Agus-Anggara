# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA)</h1>
<p align="center">Yunus Agus Anggara - 103112400175</p>

## Dasar Teori
Struktur data adalah cara pengorganisasian data yang memungkinkan proses manipulasi, penyimpanan, dan pengambilan data dilakukan secara efektif dan efisien. Salah satu struktur data yang banyak digunakan untuk proses pencarian dan penyisipan cepat adalah Binary Search Tree (BST). BST merupakan bentuk khusus dari binary tree dengan aturan tertentu yang membuat proses pencarian lebih optimal dibandingkan struktur data linear seperti array atau linked list [1].
Binary tree dan BST banyak digunakan dalam implementasi sistem basis data, compiler, indeks pencarian, hingga sistem penyimpanan berhierarki karena sifatnya yang fleksibel, dinamis, dan terstruktur [2].

### A. Binary Tree<br/>
Binary tree adalah struktur data berbentuk pohon di mana setiap node memiliki maksimum dua anak, yaitu anak kiri (left child) dan anak kanan (right child). Struktur ini bersifat hierarkis dan memungkinkan penyimpanan data secara terorganisir untuk mempermudah pencarian dan pengolahan data.
#### 1. Pengertian Binary Tree
Binary tree adalah himpunan node yang terdiri dari sebuah root dan dua subtree yang masing-masing juga merupakan binary tree. Setiap node dapat memiliki 0, 1, atau 2 child. Struktur ini dapat digunakan untuk berbagai tujuan seperti representasi ekspresi, keputusan, dan pencarian [3].
#### 2. Node dalam Binary Tree
Node adalah elemen dasar dalam tree yang berisi:
- info (data)
- left child
- right child
Node-node tersebut saling terhubung menggunakan pointer sehingga tree bersifat dinamis dan dapat bertambah maupun berkurang sesuai kebutuhan [4].
#### 3. Traversal pada Binary Tree
Traversal adalah metode mengunjungi seluruh node dalam tree dengan urutan tertentu:
- Preorder (Root-Left-Right)
- Inorder (Left-Root-Right)
- Postorder (Left-Right-Root)
Traversal berguna untuk menampilkan isi tree, menyalin tree, maupun menghapus tree secara sistematis [5].

### B. Binary Search Tree (BST)<br/>
Binary Search Tree adalah struktur data pohon biner dengan aturan bahwa nilai pada node kiri selalu lebih kecil dari node induknya, dan node kanan selalu lebih besar. Dengan aturan tersebut, BST memberikan performa pencarian yang lebih cepat.
#### 1. Pengertian BST
Binary Search Tree adalah binary tree terurut, di mana operasi pencarian, penyisipan, dan penghapusan dilakukan berdasarkan perbandingan nilai secara rekursif. BST meminimalkan jumlah langkah pencarian karena data disimpan secara terurut [1].
#### 2. Operasi Dasar BST
Operasi dasar dalam BST meliputi:
- Insert
Memasukkan node baru sesuai aturan BST (lebih kecil → kiri; lebih besar → kanan).
- Search
Pencarian dilakukan dengan membandingkan nilai dan menelusuri tree ke kiri atau kanan.
- Delete
Penghapusan node mempertimbangkan 3 kasus:
1) Node tanpa anak (leaf),
2) Node dengan satu anak,
3) Node dengan dua anak yang memerlukan penggantian dengan inorder successor [6].
#### 3. Kedalaman dan Jumlah Node
- Kedalaman Tree (Depth/Height)
Adalah panjang jalur terpanjang dari root ke leaf. Digunakan untuk mengukur efisiensi tree.

- Jumlah Node (Node Count)
Menghitung total elemen dalam tree menggunakan rekursi.
Rumus dasar:

count = 1 + count(left) + count(right)

Kedua metrik ini penting untuk mengevaluasi efektivitas dan keseimbangan tree [7].

## Guided 

### 1. Rekursif

```C++
#include<iostream>
using namespace std;

int pangkat_2(int x) {//adalah pengkatnya
    if(x == 0) {//basis
        return 1;
    } else if (x > 0) {//rekurens
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukkan nilai x: "; 
    cin >> x;
    cout << endl;
    cout << " 2 pangkat " << x << " adalah : " << pangkat_2(x) ;

    return 0;
}

//misalx = 3
//pangkat_2(3) 
//2 * pangkat_2(2)
//2 * ( 2 * pangkat_2(1))
//2 * (2 * ( 2 * pangkat_2(0))
// = 2 * (2 * (2 * 1))
// = 8

```
Pada Guided 1, fungsi rekursif digunakan untuk menghitung nilai 2^x. Konsep rekursi diterapkan dengan membuat fungsi yang memanggil dirinya sendiri sampai mencapai kondisi dasar, yaitu ketika 𝑥=0. Jika nilai belum mencapai 0, fungsi mengalikan angka 2 dengan hasil pemanggilan fungsi pada nilai 𝑥−1. Guided ini menunjukkan bagaimana rekursi bekerja dengan memecah perhitungan besar menjadi perhitungan kecil secara berulang hingga mencapai kondisi berhenti.

### 2. Binary Search Tree
BST1.H
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data interger
typedef struct Node* address; //alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan(integer)
    address left; // pointer left
    address right; // pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); //function untuk memasukkan node kedalam BST

//traversal
void preOrder(address root); //function traversal tree secara pre-order (tengah - kiri - kanan atau root - childkiri - childkanan)
void inOrder(address root); //function traversal tree secara in-order (kiri - tengah - kanan atau childkiri - root - childkanan)
void postOrder(address root); //function traversal tree secara post-order (kiri - kanan - tengah atau childkiri - childkanan - root)

//utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

#endif
```
BST1.CPP
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```

Guided 2 menjelaskan bagaimana membangun struktur Binary Search Tree (BST), yang menyimpan data secara terurut dengan aturan bahwa nilai lebih kecil berada di kiri dan nilai lebih besar berada di kanan. Materi mencakup pembuatan node baru, proses penyisipan node ke dalam BST, serta penggunaan tiga metode traversal—InOrder, PreOrder, dan PostOrder—untuk menelusuri dan menampilkan data dari tree. Selain itu, fungsi rekursif juga digunakan untuk menghitung jumlah node dan kedalaman tree, sehingga mahasiswa dapat memahami bagaimana BST bekerja sebagai struktur data hierarkis yang efisien.

### 3. Binary Search Tree 2
BST2.H
```C++
#ifndef BST2_H
#define BST2_H

#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data interger
typedef struct Node* address; //alias address sebagai pointer ke struct Node (Node*)

struct Node {
    infotype info; // info data yang disimpan(integer)
    address left; // pointer left
    address right; // pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah BST kosong atau tidak
void createTree(address &root); //function untuk membuat BST nya (root di-set sebagai NULL)

//alokasi & insert
address newNode(infotype x); //function untuk memasukkan data (infotype) kedalam node
address insertNode(address root, infotype x); //function untuk memasukkan node kedalam BST

//traversal
void preOrder(address root); //function traversal tree secara pre-order (tengah - kiri - kanan atau root - childkiri - childkanan)
void inOrder(address root); //function traversal tree secara in-order (kiri - tengah - kanan atau childkiri - root - childkanan)
void postOrder(address root); //function traversal tree secara post-order (kiri - kanan - tengah atau childkiri - childkanan - root)

//utilities
int countNodes(address root); //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
int treeDepth(address root); //function untuk menghitung height atau kedalaman atau level tree

//FUNCTION & PEOSEDUR BARU
//search
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu

//mostleft & mostright
address mostLeft(address root); //function untuk menampilkan mostleft atau node paling kiri
                                // (node dengan nilai terkecil) didalam BST
address mostRight(address root); //function untuk menampilkan mostright atau node paling kanan
                                 // (node dengan nilai terbesar) didalam BST

//delete
bool deleteNode(address &root, infotype x); //function untuk menghapus node tertentu didalam BST
                                            //(menghapus berdasarkan parameter infotype)
void deleteTree(address &root); //procedur untuk menghapus BST (menghapus seluruh node BST)
#endif
```
BST2.CPP
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }
}
```

Pada Guided 3, BST dikembangkan lebih lanjut dengan menambahkan fitur pencarian node tertentu, menampilkan relasinya seperti parent, sibling, dan child, serta fungsi untuk menemukan nilai terkecil dan terbesar di dalam tree. Materi juga memasukkan proses penghapusan node yang mencakup empat kondisi berbeda, termasuk penanganan node tanpa anak hingga node dengan dua anak yang membutuhkan penggantian dengan inorder successor. Selain itu, disediakan juga fungsi untuk menghapus seluruh tree secara rekursif, sehingga mahasiswa memahami pengelolaan memori dan manipulasi struktur BST secara lengkap.


## Unguided 

### 1.  Soal Unguided 1
Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”:

Type infotype: integer
Type address : pointer to Node
Type Node: <
info : infotype
left, right : address
>
function alokasi( x : infotype ) → address
procedure insertNode( input/output root : address,input x : infotype )
function findNode( x : infotype, root : address )→address
procedure printInorder( input root : address )

Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif
```
bstree.cpp
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    if (P != NULL) {
        P->info = x;
        P->left = NULL;
        P->right = NULL;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // Jika x == root->info, data duplikat → diabaikan
}

address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } else if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

```
main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = NULL;  

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);  // duplikat, akan diabaikan
    insertNode(root, 7);

    cout << "InOrder Traversal: ";
    printInorder(root);

    cout << endl;
    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_10](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan10_Modul10/Unguided//Unguided1/Output-Unguided1-Modul10.png)

Pada Unguided 1, mahasiswa diminta membuat dua fungsi rekursif, yaitu fungsi untuk menghitung deret Fibonacci dan fungsi untuk menghitung perpangkatan bilangan. Latihan ini memperkuat pemahaman bahwa rekursi bekerja dengan memecah persoalan besar menjadi sub-masalah yang lebih kecil hingga mencapai kondisi dasar. Fibonacci mencontohkan rekursi bercabang, sedangkan perpangkatan mencontohkan rekursi linear, sehingga mahasiswa dapat membedakan pola rekursi yang berbeda berdasarkan kasus penggunaannya.

### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer
/* fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree */

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);

#endif
```
bstree.cpp
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    if (P != NULL) {
        P->info = x;
        P->left = NULL;
        P->right = NULL;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // Jika x == root->info, data duplikat → diabaikan
}

address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } else if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == NULL) {
        return start;
    }

    start += root->info;

    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);

    return start;
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) {
        return start;
    }

    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);

    return max(leftDepth, rightDepth);
}
```
main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = NULL;  
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);   // duplikat, diabaikan
    insertNode(root, 7);

    printInorder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    return 0;
}

```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_10](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan10_Modul10/Unguided//Unguided2/Output-Unguided2-Modul10.png)

Pada Unguided 2, mahasiswa diminta menambahkan tiga fungsi analitis pada BST, yaitu menghitung jumlah node, menghitung total nilai semua info node, dan menghitung kedalaman tree maksimal. Ketiga fungsi ini menggunakan rekursi sebagai dasar proses penelusuran, di mana setiap langkah menelusuri subtree kiri dan kanan untuk mengumpulkan data. Latihan ini memperkenalkan cara melakukan agregasi pada struktur tree serta menunjukkan bagaimana kedalaman tree dapat mempengaruhi performa operasi pencarian.

### 3. Print tree secara pre-order dan post-order.

bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);
void printPreorder(address root);
void printPostorder(address root);


#endif
```

bstree.cpp
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address P = new Node;
    if (P != NULL) {
        P->info = x;
        P->left = NULL;
        P->right = NULL;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // Jika x == root->info, data duplikat → diabaikan
}

address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } else if (x == root->info) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == NULL) {
        return start;
    }

    start += root->info;

    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);

    return start;
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) {
        return start;
    }

    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);

    return max(leftDepth, rightDepth);
}

void printPreorder(address root) {
    if (root != NULL) {
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(address root) {
    if (root != NULL) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}
```

main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = NULL;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); 
    insertNode(root,7);
    
    cout << "Inorder     : ";
    printInorder(root);
    cout << endl;

    cout << "Preorder    : ";
    printPreorder(root);
    cout << endl;

    cout << "Postorder   : ";
    printPostorder(root);
    cout << endl;
    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_10](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan10_Modul10/Unguided//Unguided3/Output-Unguided3-Modul10.png)

Unguided 3 berfokus pada pembangunan Binary Search Tree secara menyeluruh, mulai dari pembuatan struktur node, fungsi insert, pencarian, hingga traversal InOrder, PreOrder, dan PostOrder. Tugas ini mengajak mahasiswa mengimplementasikan logika rekursif untuk menelusuri tree, memahami pengaturan posisi kiri dan kanan pada setiap node, serta memverifikasi hasil output agar sesuai dengan sifat BST. Dengan latihan ini, mahasiswa belajar bagaimana struktur data tree mengelola data secara terurut dan dapat diakses dengan kompleksitas waktu yang efisien.

## Kesimpulan
Secara keseluruhan, praktikum ini membantu mahasiswa memahami konsep rekursi dan penerapannya dalam struktur data Binary Search Tree. Melalui guided dan unguided, mahasiswa dilatih mengimplementasikan operasi dasar seperti insert, search, traversal, serta analisis seperti menghitung node dan kedalaman. Praktikum ini menegaskan bahwa rekursi sangat efektif digunakan pada struktur data yang bersifat hierarkis seperti tree, dan BST memberikan dasar penting untuk memahami algoritma pencarian yang efisien.

## Referensi
[1] Samanta, D. “Classic Data Structures.” Prentice-Hall India, 2019.
[2] Cormen, T., Leiserson, C., Rivest, R., Stein, C. “Introduction to Algorithms.” MIT Press, 2022.
[3] Knuth, Donald. “The Art of Computer Programming, Volume 1.” Addison-Wesley, 2011.
[4] Malik, D. S. “Data Structures Using C++.” Course Technology, 2017.
[5] Shaffer, Clifford. “Data Structures and Algorithm Analysis.” Dover Publications, 2021.
[6] Goodrich, Tamassia & Goldwasser. “Data Structures & Algorithms in C++.” Wiley, 2020.
[7] Weiss, Mark Allen. “Data Structures and Algorithm Analysis.” Pearson, 2014.
