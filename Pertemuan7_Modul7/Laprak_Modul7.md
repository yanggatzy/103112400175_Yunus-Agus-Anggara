# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Yunus Agus Anggara - 103112400175</p>

## Dasar Teori
Struktur data stack adalah struktur data linear yang menerapkan aturan LIFO (Last In First Out), yaitu elemen terakhir yang masuk adalah elemen pertama yang keluar. Stack banyak digunakan dalam berbagai proses komputasi seperti function call, undo-redo, expression evaluation, dan backtracking [1].

Stack memiliki dua operasi utama yaitu:
- push() → memasukkan elemen ke puncak stack
- pop() → mengeluarkan elemen dari puncak stack

Selain itu, terdapat operasi pengecekan seperti:
- isEmpty() → mengecek apakah stack kosong
- isFull() → mengecek apakah stack penuh (pada implementasi array)

Menurut penelitian dalam International Journal of Computer Applications, stack merupakan komponen penting dalam compiler, khususnya dalam parsing ekspresi menggunakan metode reverse polish notation serta infix–postfix conversion [2].

Stack dapat diimplementasikan menggunakan dua pendekatan:
1. Stack berbasis array, dengan ukuran tetap

2. Stack berbasis linked list, dengan ukuran dinamis mengikuti alokasi memori

### A. Implementasi Stack<br/>
#### 1. Stack Menggunakan Linked List
- Memanfaatkan node dinamis
- Operasi push menambahkan node di awal list
- Operasi pop menghapus node paling atas
#### 2. Stack Menggunakan Array
- Menggunakan indeks top sebagai penanda elemen teratas
- Operasi push dan pop dilakukan pada indeks top

### B. Operasi Tambahan<br/>
#### 1. update()
Mengubah nilai pada posisi tertentu di dalam stack.
#### 2. search()
Mencari elemen dalam stack dan mengembalikan posisi jika ditemukan.
#### 3. balikStack()
Membalik urutan elemen stack, biasanya menggunakan stack bantu.


## Guided 

### 1. PUSH and POP STACK
stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node* address;

struct node{
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif

```
stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
}
```
Pada guided 1, stack diimplementasikan menggunakan struktur data linked list, di mana setiap elemen disimpan dalam node dinamis dan dihubungkan melalui pointer. Operasi push menambahkan node baru ke bagian top, sedangkan pop menghapus node teratas dan menggeser pointer top ke node berikutnya. Fungsi tambahan seperti update, view, dan searchData digunakan untuk memodifikasi, menampilkan isi stack, serta mencari data tertentu di dalam tumpukan. Konsep ini menggambarkan karakteristik stack yaitu bersifat LIFO (Last In First Out), sesuai prinsip bahwa elemen terakhir yang dimasukkan adalah elemen pertama yang dikeluarkan.

### 2.  BALIK STACK
stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //Array untuk menyimpan eleman stack
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // Menambahkan elemen ke dalam stack
infotype pop(Stack &S); // Mengambil elemen teratas dari stack
void printInfo(Stack S);
void balikStack(Stack &S); // Membalik urutan elemen dalam stack

#endif
```
stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Pada guided 2, stack direpresentasikan menggunakan array berukuran tetap dan operasi dasar push, pop, serta printInfo digunakan untuk memanipulasi isi stack. Fungsi balikStack bekerja dengan menggunakan dua stack sementara untuk membalik urutan elemen: stack pertama menampung elemen hasil pop dari stack asli (membalik urutan), stack kedua membalik lagi urutan tersebut, dan hasil akhirnya dikembalikan ke stack asli. Teknik ini menunjukkan bagaimana stack dapat dimanfaatkan untuk manipulasi urutan data tanpa perlu struktur data lain selain stack itu sendiri.


## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
Type infotype : integer
Type Stack <
info : array [20] of integer
top : integer
>
procedure CreateStack( input/output S : Stack )
procedure push(input/output S : Stack, input x : infotype)
function pop(input/output t S : Stack )→ infotype
procedure printInfo( input S : Stack )
procedure balikStack(input/output S :Stack )

Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”

stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Stack {
    int data[20];
    int top;
} Stack;

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
bool isFull(Stack S);
bool isEmpty(Stack S);
#endif
```
stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S){
    S.top = -1;
}

void push(Stack &S, infotype x){
    if(!isFull(S)){
        S.top++;
        S.data[S.top] = x;
    }else{
        cout << "Stack is full!" << endl;
    }
}

infotype pop(Stack &S ){
    if (isEmpty(S)){
        cout << "Stack is empty!" << endl;
        return -1; // Return an invalid value or handle error appropriately
    }else{
        infotype x = S.data[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S){
    if(isEmpty(S)){
        cout << "Stack is empty!" << endl;
    }else{
        for(int i = S.top; i >= 0; i--){
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S){
    Stack tempStack;
    CreateStack(tempStack);
    while(!isEmpty(S)){
        infotype x = pop(S);
        push(tempStack, x);
    }
    S = tempStack;
}

bool isFull(Stack S){
    return S.top == 19;
}

bool isEmpty(Stack S){
    return S.top == -1;
}
```
main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main(){
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_7](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan7_Modul7/Unguided/Unguided1/Output-Unguided1-Modul7.png) 



Pada unguided 1, dibuat ADT stack berbasis array dengan ukuran tetap 20 elemen yang mendukung operasi push, pop, printInfo, dan balikStack. Stack diinisialisasi dengan nilai top = -1 sebagai indikator kosong. Operasi push menambahkan elemen ke indeks top+1, sedangkan pop mengurangi top dan mengembalikan nilai teratas. Fungsi balikStack menggunakan stack sementara untuk membalik urutan elemen. Implementasi ini memperkuat pemahaman konsep dasar stack sebagai struktur data LIFO menggunakan array statis.

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Stack {
    int data[20];
    int top;
} Stack;

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
bool isFull(Stack S);
bool isEmpty(Stack S);
void pushAscending(Stack &S, infotype x);
#endif
```
stack.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S){
    S.top = -1;
}
void push(Stack &S, infotype x){
    if(!isFull(S)){
        S.top++;
        S.data[S.top] = x;
    }else{
        cout << "Stack is full!" << endl;
    }
}

infotype pop(Stack &S ){
    if (isEmpty(S)){
        cout << "Stack is empty!" << endl;
        return -1; // Return an invalid value or handle error appropriately
    }else{
        infotype x = S.data[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S){
    if(isEmpty(S)){
        cout << "Stack is empty!" << endl;
    }else{
        for(int i = S.top; i >= 0; i--){
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S){
    Stack tempStack;
    CreateStack(tempStack);
    while(!isEmpty(S)){
        infotype x = pop(S);
        push(tempStack, x);
    }
    S = tempStack;
}

bool isFull(Stack S){
    return S.top == 19;
}

bool isEmpty(Stack S){
    return S.top == -1;
}

void pushAscending(Stack &S, infotype x){
    if(isFull(S)){
        cout << "Stack is full!" << endl;
        return;
    }

    Stack tempStack;
    CreateStack(tempStack);

    // Pindahkan elemen dari S ke tempStack sampai menemukan posisi yang tepat
    while(!isEmpty(S) && S.data[S.top] > x){
        infotype y = pop(S);
        push(tempStack, y);
    }

    // Masukkan elemen baru
    push(S, x);

    // Kembalikan elemen dari tempStack ke S
    while(!isEmpty(tempStack)){
        infotype y = pop(tempStack);
        push(S, y);
    }
}
```
main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main(){
   cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
    }
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_7](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan6_Modul7/Unguided/Unguided2/Output-Unguided2-Modul7.png) 

Pada unguided 2, ditambahkan prosedur pushAscending, yang memungkinkan data disimpan pada stack dalam kondisi terurut naik. Prosesnya menggunakan stack sementara untuk memindahkan elemen yang lebih besar dari nilai baru, sehingga posisi yang tepat dapat ditemukan. Setelah elemen baru dimasukkan, seluruh elemen dari stack sementara dikembalikan ke stack utama. Metode ini meniru konsep insertion sort namun diimplementasikan hanya dengan operasi stack.

### 3.  Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

stack.h
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Stack {
    int data[20];
    int top;
} Stack;

void CreateStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
bool isFull(Stack S);
bool isEmpty(Stack S);
void pushAscending(Stack &S, infotype x);
#endif
```
stack.cpp
```C++
#include "stack.h"
#include <iostream>
#include <limits>
using namespace std;

void CreateStack(Stack &S){
    S.top = -1;
}
void push(Stack &S, infotype x){
    if(!isFull(S)){
        S.top++;
        S.data[S.top] = x;
    }else{
        cout << "Stack is full!" << endl;
    }
}

infotype pop(Stack &S ){
    if (isEmpty(S)){
        cout << "Stack is empty!" << endl;
        return -1; // Return an invalid value or handle error appropriately
    }else{
        infotype x = S.data[S.top];
        S.top--;
        return x;
    }
}

void printInfo(Stack S){
    if(isEmpty(S)){
        cout << "Stack is empty!" << endl;
    }else{
        for(int i = S.top; i >= 0; i--){
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S){
    Stack tempStack;
    CreateStack(tempStack);
    while(!isEmpty(S)){
        infotype x = pop(S);
        push(tempStack, x);
    }
    S = tempStack;
}

bool isFull(Stack S){
    return S.top == 19;
}

bool isEmpty(Stack S){
    return S.top == -1;
}

void pushAscending(Stack &S, infotype x){
    if(isFull(S)){
        cout << "Stack is full!" << endl;
        return;
    }

    Stack tempStack;
    CreateStack(tempStack);

    // Pindahkan elemen dari S ke tempStack sampai menemukan posisi yang tepat
    while(!isEmpty(S) && S.data[S.top] > x){
        infotype y = pop(S);
        push(tempStack, y);
    }

    // Masukkan elemen baru
    push(S, x);

    // Kembalikan elemen dari tempStack ke S
    while(!isEmpty(tempStack)){
        infotype y = pop(tempStack);
        push(S, y);
    }
}

void getInputStream(Stack &S) {
    char c;

    cout << "Masukkan input: ";

    cin.get(c);

    while (c != '\n') {
        push(S, c - '0'); 
        cin.get(c);
    }
}

```
main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main(){
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_7](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan6_Modul7/Unguided//Unguided3/Output-Unguided3-Modul7.png) 


Pada unguided 3, ditambahkan prosedur getInputStream yang membaca input karakter satu per satu menggunakan cin.get() hingga pengguna menekan ENTER. Setiap karakter dimasukkan ke dalam stack, sehingga data tersimpan sesuai urutan input user. Method ini menunjukkan pemanfaatan stack untuk menampung stream karakter secara langsung, yang kemudian dapat ditampilkan atau dibalik menggunakan prosedur lain seperti printInfo dan balikStack.

## Kesimpulan
Dari seluruh percobaan guided dan unguided, dapat disimpulkan bahwa stack merupakan struktur data sederhana namun sangat berguna dengan prinsip LIFO (Last In First Out). Melalui implementasi menggunakan array maupun linked list, stack dapat digunakan untuk berbagai operasi seperti pembalikan data, penyimpanan terurut, dan pemrosesan input stream karakter. Pemanfaatan stack juga terlihat pada banyak aplikasi nyata seperti algoritma rekursi, penyusunan ekspresi, pengolahan teks, hingga sistem navigasi. Dengan latihan ini, mahasiswa telah memahami cara kerja dan implementasi stack secara mendalam.

## Referensi
[1] Yudistira, N., & Hidayat, R. (2020). Implementasi Struktur Data Stack dalam Pengolahan Data Berbasis LIFO. Jurnal Teknologi dan Sistem Informasi, 6(2), 45–52.
[2] Pratama, A., & Nugroho, A. (2019). Analisis Penggunaan Stack pada Proses Pemrograman dan Algoritma. Jurnal Informatika dan Rekayasa Perangkat Lunak, 7(1), 12–20.