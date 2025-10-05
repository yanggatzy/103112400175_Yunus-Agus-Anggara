# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Yunus Agus Anggara - 103112400175</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Array Dua Dimensi

```C++
#include<iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i =0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
    
    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for(int i = 0; i < 2; i++){ //perulangan baris
        for(int j = 0; j < 2; j++){ //kolom
            for(int k = 0; k < 2; k++){ //kali
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
penjelasan singkat guided 1

### 2. arrNpointer

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[] ={10, 20, 30, 40, 50};
    int* ptr = arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; ++i){
        cout << "Elemen array ke-" << i+1 << " menggunakan pointer: " << (ptr + i) << endl; 
    }

    //mengakses elemen array menggunakan indeks
    for(int i = 0; i < 5; ++i) {
        cout << "Elemen array ke-" << i+1 << " menggunakan indeks: " << arr[i] << endl;
    }
    return 0;
}
```
penjelasan singkat guided 2

### 3. Function & Procedure

```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran) {
    int MAX = arr[0];
    for(int i = 0; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }

    cout << "total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;

}

int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++) {
        cout << "masukan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
penjelasan singkat guided 3

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini :


```C++
#include <iostream>
using namespace std;

int matriksA[3][3] {
    {7, 12, 22},
    {31, 6, 41},
    {15, 19, 36}
};

int matriksB[3][3] {
    {11, 34, 7},
    {3, 25, 41},
    {5, 18, 33}
};

int matriksC[3][3] = {0}; //utk penjumlahan
int matirksD[3][3] = {0}; // utk pengurangan
int matriksE[3][3] = {0}; // utk perkalian

void tampilkanMatriks(int matriks[3][3], string namaMatriks) {
    cout << "Matriks " << namaMatriks << " : " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

void tampilkanKeduaMatriks() {
    cout << "=== MATRIKS YANG TERSEDIA ===" << endl;
    tampilkanMatriks(matriksA, "A");
    cout << endl;
    tampilkanMatriks(matriksB, "B");
    cout << endl;
}

void penjumlahanMatriks(){
    cout << "=== Operasi Penjumlahan Matriks ===" << endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matriksC[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }

    cout << "Hasil Penjumlahan Matriks A + B : " << endl;
    tampilkanMatriks(matriksC, "C (A + B)");
}

void penguranganMatriks(){
    cout << "=== Operasi Pengurangan Matriks ===" << endl;


    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matirksD[i][j] = matriksA[i][j] - matriksB[i][j];
        }
    }

    cout << "Hasil Pengurangan Matriks A - B : " << endl;
    tampilkanMatriks(matirksD, "D (A - B)");
}

void perkalianMatriks(){
    cout << "=== Operasi Perkalian Matriks ===" << endl;


    for(int i = 0; i < 3; i++){ //perulangan baris
        for(int j = 0; j < 3; j++){ //kolom
            for(int k = 0; k < 3; k++){ //kali
                matriksE[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }

    cout << "Hasil Perkalian Matriks A * B : " << endl;
    tampilkanMatriks(matriksE, "E (A * B)");
}

int main() {
    int pilihan;
    tampilkanKeduaMatriks();

    do {
        cout << "=== Menu Program Matriks ===" << endl;
        cout << "1. Penjumlahan Matriks" << endl;
        cout << "2. Pengurangan Matriks" << endl;
        cout << "3. Perkalian Matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih operasi (1-4): ";
        cin >> pilihan;
        cout << endl;

        switch(pilihan) {
            case 1:
                penjumlahanMatriks();
                break;
            case 2:
                penguranganMatriks();
                break;
            case 3:
                perkalianMatriks();
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while(pilihan != 4);

    return 0;
};
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan2_Modul2/Unguided/Output-Unguided1-Modul2.png)

![Screenshot Output Unguided 1_1](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan2_Modul2/Unguided/Output-Unguided1.2-Modul2.png)

penjelasan unguided 1 

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan
luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar
yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas.
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui
pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa
nilainya telah berubah.

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
