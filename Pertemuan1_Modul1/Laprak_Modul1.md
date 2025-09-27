# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
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

### 1. Hello World

```C++
#include<iostream>
using namespace std;

int main(){
    cout << "hello world" << endl;
    return 0;
}

```
penjelasan singkat guided 1

### 2. Input Output dalam C++

```C++
#include<iostream>
using namespace std;

int main(){
    int angka;
    cout << "Masukan angka: ";
    cin >> angka;
    cout << "Angka yang dimasukkan " << angka << endl;
    return 0;
}
```
penjelasan singkat guided 2

### 3. Operator Aritmatika dalam C++

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    cout << "Penjumlahan : " << angka1 + angka2 <<endl;
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    cout << "Perkalian : " << angka1 * angka2 << endl;
    cout << "Pembagian : " << angka1 / angka2 << endl;
    cout << "Modulus : " << angka1 % angka2 << endl;
    return 0;
}
```
penjelasan singkat guided 3

### 4. Percabangan atau if-else dalam C++

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukan angka 1: ";
    cin >> angka1;
    cout << "masukan angka 2: ";
    cin >> angka2;

    if (angka1 < angka2){
        cout << angka1 << "kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << "lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2){
        cout << angka1 << "sama dengan " << angka2 << endl;
    } else if (angka1 != angka2){
        cout << "angka berbeda " << endl;
    }

    return 0;

}
```
penjelasan singkat guided 4

### 5. Switch Case dalam C++

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "masukan angka 1: ";
    cin >> angka1;
    cout << "masukan angka 2: ";
    cin >> angka2;

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukan pilihan: "<< endl;
    cin >> pilihan;

    switch(pilihan){
        case 1:
        cout << "penjumlahan: "<< angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pengurangan: " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default :
        cout << "pilihan tidak tersedia" << endl;
    }

    return 0;

}
```
penjelasan singkat guided 5

### 6. Perulangan atau Loop dalam C++

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1;
    cout << "masukan angka 1: ";
    cin >> angka1;
    
    for(int i = 0; 1 < angka1; i++){ //increment
        cout << i << " - ";
    }
    
    cout << endl;
    int j = 10;
    while (j > angka1){
        cout << j << " - ";
        j--; //decrement
    }
    
    cout << endl;
    int k = 10;
    do{
        cout << k << " - ";
    } while (k < angka1);


    return 0;
    
}
```
penjelasan singkat guided 6

### 7. Struktur dalam C++

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX =5;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];
    
    for(int i = 0; i < MAX; i++){
        cout << "masukan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "masukan nilai siswa : ";
        cin >> siswa[i].nilai;
        cout << endl;
}

    int j = 0;
    while(j < MAX){
        cout << "Nama siswa: " << siswa[j].nama << ", Nilai: " << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}
```
penjelasan singkat guided 7


## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

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

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
