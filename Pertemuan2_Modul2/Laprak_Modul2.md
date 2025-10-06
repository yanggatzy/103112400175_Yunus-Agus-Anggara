# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Yunus Agus Anggara - 103112400175</p>

## Dasar Teori

### A. Array Satu dan Dua Dimensi<br/>
Array merupakan struktur data fundamental dalam pemrograman yang digunakan untuk menyimpan kumpulan elemen dengan tipe data yang sama [1]. Array memungkinkan pengelolaan data yang efisien melalui pengelompokan nilai-nilai terkait di bawah satu nama variabel, sehingga memudahkan dalam proses manipulasi dan akses data.
#### 1. Array Satu Dimensi
Array satu dimensi adalah kumpulan elemen yang disusun secara linear dalam satu baris. Setiap elemen diakses menggunakan satu indeks yang dimulai dari nol. Deklarasi array satu dimensi dalam C++ dilakukan dengan sintaks tipe_data nama_array[ukuran]. Keunggulan utama array satu dimensi adalah kemudahan dalam mengelola data sequential dan efisiensi dalam proses iterasi menggunakan perulangan [1].
#### 2. Array Dua Dimensi
Array dua dimensi merupakan pengembangan dari array satu dimensi yang menyusun elemen dalam bentuk baris dan kolom, membentuk struktur seperti tabel atau matriks. Dalam C++, array dua dimensi dideklarasikan dengan sintaks tipe_data nama_array[baris][kolom]. Struktur ini sangat berguna untuk merepresentasikan data yang memiliki hubungan dua arah seperti matriks dalam matematika, tabel database, atau grid dalam aplikasi grafis [1].

### B. Pointer dan Referensi<br/>
Pointer adalah variabel khusus yang menyimpan alamat memori dari variabel lain, bukan nilai langsungnya [2]. Konsep pointer memungkinkan manipulasi memori yang lebih fleksibel dan efisien dalam pemrograman C++, serta memungkinkan implementasi struktur data dinamis yang kompleks.
#### 1. Pointer dan Array 
Hubungan antara pointer dan array sangat erat dalam C++. Nama array sendiri sebenarnya merupakan pointer konstan yang menunjuk ke elemen pertama array. Dengan menggunakan pointer arithmetic, kita dapat mengakses elemen-elemen array secara efisien tanpa perlu menggunakan indeks secara eksplisit [2].
#### 2. Call by Pointer
Call by pointer adalah mekanisme passing parameter dimana alamat memori dari variabel dilewatkan ke fungsi. Dengan cara ini, fungsi dapat memodifikasi nilai variabel asli karena memiliki akses langsung ke lokasi memorinya. Sintaks yang digunakan melibatkan operator address-of (&) dan dereference (*) untuk mengakses nilai yang ditunjuk [2].
#### 3. Call by Reference
Call by reference mirip dengan call by pointer, namun menggunakan reference yang lebih aman dan mudah digunakan. Reference berperilaku seperti alias untuk variabel asli dan tidak memerlukan operator dereference eksplisit. Mekanisme ini memberikan kemudahan sintaks tanpa kehilangan kemampuan untuk memodifikasi variabel asli [2].

### C. Function dan Procedure<br/>
Dalam pemrograman modular, function dan procedure merupakan blok kode yang dirancang untuk melakukan tugas tertentu [3]. Pendekatan modular ini meningkatkan organisasi kode, mengurangi duplikasi, dan memudahkan proses debugging serta maintenance.
#### 1. Function
Function adalah subprogram yang mengembalikan nilai setelah dieksekusi. Dalam C++, function dideklarasikan dengan tipe return value tertentu Function ideal digunakan ketika kita membutuhkan hasil perhitungan atau operasi yang akan digunakan kembali dalam program. Function membantu dalam memecah program besar menjadi bagian-bagian kecil yang lebih terkelola [3].
#### 2. Procedure
Procedure (dalam C++ biasanya berupa void function) adalah subprogram yang tidak mengembalikan nilai. Procedure digunakan untuk menjalankan serangkaian perintah tanpa perlu menghasilkan nilai balik, seperti menampilkan output atau memodifikasi variabel global. Procedure berguna untuk mengelompokkan kode yang melakukan tugas tertentu tanpa membutuhkan nilai kembali [3].

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
Program ini mendemonstrasikan operasi matriks 2x2 dengan array dua dimensi. Program melakukan penjumlahan dan perkalian matriks, menunjukkan bagaimana array multidimensi dapat digunakan untuk merepresentasikan dan memanipulasi struktur data tabular.

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
Program ini mengilustrasikan hubungan erat antara array dan pointer. Menunjukkan dua cara berbeda untuk mengakses elemen array: melalui pointer arithmetic dan melalui indeks array konvensional.

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
Program ini menunjukkan penggunaan function yang mengembalikan nilai (cariMAX) dan procedure yang tidak mengembalikan nilai (operasiAritmatika). Mengilustrasikan konsep modular programming dengan memisahkan logika program ke dalam unit-unit yang lebih kecil dan terfokus.

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

Program ini mengimplementasikan sistem operasi matriks 3x3 yang komprehensif. Menggunakan array dua dimensi untuk merepresentasikan matriks dan menerapkan konsep modular programming dengan memisahkan setiap operasi ke dalam procedure terpisah. Program menunjukkan penanganan array multidimensi yang efektif dan implementasi antarmuka pengguna berbasis menu.

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
#include<iostream>
using namespace std;

int main(){
    int panjang = 10;
    int lebar = 5;
    int luas = 0;

    int *ptrpanjang = &panjang;
    int *ptrlebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;

    cout << "\n--- Hasil Perhitungan ---" << endl;
    luas = (*ptrpanjang) * (*ptrlebar);
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << 2 * (*ptrpanjang + *ptrlebar) << endl;

    *ptrpanjang = 12; // Mengubah nilai panjang melalui pointer
    *ptrlebar = 6;   // Mengubah nilai lebar melalui pointer
    
    luas = (*ptrpanjang) * (*ptrlebar);
    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru: " << lebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << 2 * (*ptrpanjang + *ptrlebar) << endl;

    return 0;

}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan2_Modul2/Unguided/Output-Unguided2-Modul2.png)

Program ini mendemonstrasikan penggunaan pointer untuk manipulasi variabel. Menunjukkan konsep call by pointer dimana variabel dimodifikasi melalui alamat memorinya. Program membuktikan bahwa perubahan nilai melalui pointer mempengaruhi variabel asli, mengilustrasikan bagaimana pointer memungkinkan akses dan modifikasi data secara langsung di level memori.

## Kesimpulan
Berdasarkan praktikum modul 2 tentang pengenalan Bahasa C++ bagian kedua, dapat disimpulkan bahwa:

1) Array satu dan dua dimensi merupakan struktur data fundamental yang efisien untuk mengelola kumpulan data terstruktur, dengan array dua dimensi khususnya berguna untuk merepresentasikan data tabular seperti matriks.

2) Pointer memberikan fleksibilitas tinggi dalam manipulasi memori dan memiliki hubungan erat dengan array, dimana nama array sendiri berperilaku seperti pointer konstan ke elemen pertama.

3) Call by pointer dan call by reference memungkinkan modifikasi variabel asli dalam fungsi.

4) Function dan procedure mendukung pemrograman modular dengan memisahkan kode ke dalam unit-unit fungsional.

5) Penggunaan kombinasi array, pointer, dan function/procedure memungkinkan pengembangan program yang efisien dan terstruktur dengan baik.

## Referensi
[1] Stroustrup, B. (2013). The C++ Programming Language. Addison-Wesley Professional.

[2] Prata, S. (2011). C++ Primer Plus. Addison-Wesley Professional.

[3] Lippman, S. B., Lajoie, J., & Moo, B. E. (2012). C++ Primer. Addison-Wesley Professional.
