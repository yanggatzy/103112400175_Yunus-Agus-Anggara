# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Yunus Agus Anggara - 103112400175</p>

## Dasar Teori
Abstract Data Type (ADT) adalah suatu model matematika dari struktur data yang mendefinisikan tipe data beserta operasi-operasi yang dapat dilakukan pada data tersebut tanpa mengekspos detail implementasinya [1]. Konsep ADT memisahkan antara representasi data dan perilakunya, sehingga pengguna hanya perlu mengetahui apa yang dilakukan oleh operasi tersebut, bukan bagaimana cara melakukannya.

### A. Konsep Dasar ADT<br/>
ADT terdiri dari dua komponen utama: deklarasi data dan deklarasi operasi. Deklarasi data menentukan tipe data yang digunakan, sedangkan deklarasi operasi menentukan fungsi-fungsi yang dapat dilakukan pada data tersebut. Dalam implementasinya, ADT menggunakan prinsip enkapsulasi untuk menyembunyikan detail implementasi dari pengguna.
#### 1. Encapsulation (Enkapsulasi)
Enkapsulasi merupakan prinsip dasar dalam ADT yang menyembunyikan detail implementasi dan hanya menampilkan antarmuka yang diperlukan. Hal ini memungkinkan perubahan implementasi tanpa mempengaruhi kode yang menggunakan ADT tersebut.
#### 2. Information Hiding (Penyembunyian Informasi)
ADT menerapkan penyembunyian informasi dengan memisahkan spesifikasi dari implementasi. Pengguna hanya perlu mengetahui operasi yang tersedia, bukan bagaimana operasi tersebut diimplementasikan.
#### 3. Reusability (Kemampuan Pakai Ulang)
Dengan ADT, kode dapat digunakan kembali dalam berbagai program tanpa perlu menulis ulang implementasinya, meningkatkan efisiensi pengembangan perangkat lunak.

### B. Implementasi ADT dalam C++<br/>
Dalam bahasa pemrograman C++, ADT dapat diimplementasikan menggunakan struktur (struct) dan kelas (class). Implementasi biasanya dibagi menjadi file header (.h) untuk deklarasi dan file implementasi (.cpp) untuk definisi fungsi.
#### 1. Header File (.h)
File header berisi deklarasi struktur data dan prototipe fungsi yang membentuk antarmuka ADT.
#### 2. Implementation File (.cpp)
File implementasi berisi definisi detail dari fungsi-fungsi yang dideklarasikan dalam header.
#### 3. Modular Programming
Pemecahan kode menjadi modul-modul terpisah memudahkan maintenance, testing, dan pengembangan program secara berkelompok.

## Guided 

### 1. ADT

mahasiwa.h
```C++
#ifndef MMAHASUSWA_H
#define MMAHASUSWA_H

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```
mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}   

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```

main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;

    system("pause");

    return 0;
}
```
Program ini merupakan contoh implementasi ADT untuk data mahasiswa. ADT dideklarasikan dalam file header mahasiswa.h yang berisi struktur mahasiswa dengan field NIM, nilai1, dan nilai2, serta fungsi inputMhs untuk input data dan rata2 untuk menghitung rata-rata. Implementasi fungsi terdapat di mahasiswa.cpp, sedangkan program utama di main.cpp menggunakan ADT tersebut tanpa perlu mengetahui detail implementasinya. Ini menunjukkan prinsip enkapsulasi dimana detail implementasi disembunyikan dari pengguna.


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
using namespace std;

float NilaiAkhir(float uts, float uas, float tugas) {
    return (uts * 0.3) + (uas * 0.4) + (tugas * 0.3);
}

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

int main() {
    Mahasiswa data[10];
    int jumlah;
    
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlah;
    
    // Input data mahasiswa
    for(int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa " << i+1 << ":\n";
        cout << "Nama: ";
        cin >> data[i].nama;  // Hanya membaca satu kata
        cout << "NIM: ";
        cin >> data[i].nim;
        cout << "Nilai UTS: ";
        cin >> data[i].uts;
        cout << "Nilai UAS: ";
        cin >> data[i].uas;
        cout << "Nilai Tugas: ";
        cin >> data[i].tugas;
        
        data[i].nilaiAkhir = NilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);
    }
    
    cout << "\n\nData Mahasiswa:\n";
    cout << "No\tNama\tNIM\t\tUTS\tUAS\tTugas\tNilai Akhir\n";
    for(int i = 0; i < jumlah; i++) {
        cout << i+1 << "\t" << data[i].nama << "\t" 
             << data[i].nim << "\t" << data[i].uts << "\t" 
             << data[i].uas << "\t" << data[i].tugas << "\t" 
             << data[i].nilaiAkhir << endl;
    }
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_3](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan3_Modul3/Unguided/nomer1/Output-Unguided1-Modul3.png)

Program ini mengimplementasikan ADT sederhana untuk mengelola data mahasiswa. Struktur Mahasiswa berfungsi sebagai ADT yang mengandung data nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Fungsi NilaiAkhir merupakan operasi yang didefinisikan untuk menghitung nilai akhir berdasarkan rumus yang diberikan. Program demonstrates penggunaan ADT dalam menyimpan dan memproses data multiple mahasiswa, menampilkan prinsip modularitas dan encapsulation dimana perhitungan nilai akhir dipisahkan dari logika utama program. 

### 2. Buatlah ADT pelajaran

pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

pelajaran.cpp
```C++
#include "pelajaran.h"
#include <iostream>

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    
    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_3](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan3_Modul3/Unguided/nomer2/Output-Unguided2-Modul3.png)

Program ini menunjukkan implementasi ADT yang lebih formal dengan pemisahan antara deklarasi dan implementasi. File pelajaran.h mendeklarasikan struktur pelajaran dan fungsi-fungsi operasinya (create_pelajaran dan tampil_pelajaran), sementara pelajaran.cpp berisi implementasi detail dari fungsi-fungsi tersebut. Program utama hanya menggunakan antarmuka yang disediakan tanpa mengetahui detail implementasi, menunjukkan prinsip information hiding yang merupakan konsep kunci dalam ADT.

### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include<iostream>
using namespace std;

void tampil(int m[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarElemen(int a[3][3], int b[3][3], int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int matriksA[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matriksB[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};
    
    int *ptr1, *ptr2;
    int a = 10, b = 20;
    ptr1 = &a;
    ptr2 = &b;
    
    cout << "Matriks A:\n"; tampil(matriksA);
    cout << "Matriks B:\n"; tampil(matriksB);
    
    tukarElemen(matriksA, matriksB, 1, 2);
    cout << "\nSetelah tukar elemen [1][2]:\n";
    cout << "Matriks A:\n"; tampil(matriksA);
    cout << "Matriks B:\n"; tampil(matriksB);
    
    cout << "\nSebelum tukar pointer: a=" << a << " b=" << b << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah tukar pointer: a=" << a << " b=" << b << endl;
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_3](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan3_Modul3/Unguided/nomer3/Output-Unguided3-Modul3.png)

Program ini mendemonstrasikan konsep ADT melalui operasi pada array 2D dan pointer. Fungsi tampil, tukarElemen, dan tukarPointer membentuk operasi-operasi ADT yang bekerja pada struktur data array dan pointer. Program menunjukkan bagaimana ADT dapat digunakan untuk mengabstraksi operasi manipulasi data kompleks, dimana pengguna hanya perlu memanggil fungsi tanpa perlu memahami algoritma pertukaran yang terjadi. Ini merupakan contoh bagaimana ADT menyederhanakan interaksi dengan struktur data yang kompleks.

## Kesimpulan
Abstract Data Type (ADT) merupakan konsep fundamental dalam pemrograman yang memisahkan antara spesifikasi dan implementasi struktur data. Melalui praktikum ini, dapat disimpulkan bahwa ADT memberikan beberapa keuntungan penting: 
1) Enkapsulasi menyembunyikan detail implementasi sehingga perubahan internal tidak mempengaruhi kode pengguna, 
2) Modularitas memudahkan pengembangan dan maintenance program, 
3) Reusability memungkinkan kode digunakan kembali dalam berbagai konteks. Implementasi ADT dalam C++ menggunakan struct dan pemisahan file header/implementation terbukti efektif dalam menciptakan kode yang terorganisir, mudah dipahami, dan mudah dikembangkan.

## Referensi
[1] Shaffer, C. A. (2013). Data Structures and Algorithm Analysis in C++. Dover Publications.
[2] Stroustrup, B. (2013). The C++ Programming Language. Addison-Wesley Professional.
