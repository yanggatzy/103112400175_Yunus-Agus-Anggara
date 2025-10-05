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