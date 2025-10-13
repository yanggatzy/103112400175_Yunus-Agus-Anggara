#include<iostream>
using namespace std;

// Fungsi tampil matriks
void tampil(int m[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi tukar elemen matriks berdasarkan posisi
void tukarElemen(int a[3][3], int b[3][3], int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

// Fungsi tukar nilai menggunakan pointer
void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    // Deklarasi 2 matriks 3x3
    int matriksA[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matriksB[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};
    
    // Deklarasi 2 pointer
    int *ptr1, *ptr2;
    int a = 10, b = 20;
    ptr1 = &a;
    ptr2 = &b;
    
    // Tampilkan awal
    cout << "Matriks A:\n"; tampil(matriksA);
    cout << "Matriks B:\n"; tampil(matriksB);
    
    // Tukar elemen matriks di posisi [1][2]
    tukarElemen(matriksA, matriksB, 1, 2);
    cout << "\nSetelah tukar elemen [1][2]:\n";
    cout << "Matriks A:\n"; tampil(matriksA);
    cout << "Matriks B:\n"; tampil(matriksB);
    
    // Tukar nilai menggunakan pointer
    cout << "\nSebelum tukar pointer: a=" << a << " b=" << b << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah tukar pointer: a=" << a << " b=" << b << endl;
    
    return 0;
}