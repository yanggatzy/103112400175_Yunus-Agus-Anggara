#include <iostream>
using namespace std;

// Prosedur untuk menampilkan matriks 3x3
void cetakMatriks(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Fungsi untuk pertukaran nilai melalui pointer
void pertukaranNilai(int *nilaiA, int *nilaiB) {
    int sementara = *nilaiA;
    *nilaiA = *nilaiB;
    *nilaiB = sementara;
}

// Prosedur untuk menukar elemen pada dua matriks
void tukarMatriks(int matriksA[3][3], int matriksB[3][3], int posBaris, int posKolom) {
    int *alamatA = &matriksA[posBaris][posKolom];
    int *alamatB = &matriksB[posBaris][posKolom];
    pertukaranNilai(alamatA, alamatB);
}

int main() {
    // Inisialisasi dua matriks 3x3
    int matriksPertama[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int matriksKedua[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    // Menampilkan kondisi awal matriks
    cout << "Kondisi awal Matriks Pertama:\n";
    cetakMatriks(matriksPertama);
    cout << "Kondisi awal Matriks Kedua:\n";
    cetakMatriks(matriksKedua);

    // Menentukan posisi dan melakukan pertukaran elemen
    int barisPertukaran = 1, kolomPertukaran = 2;
    tukarMatriks(matriksPertama, matriksKedua, barisPertukaran, kolomPertukaran);

    // Menampilkan hasil setelah pertukaran
    cout << "Hasil setelah pertukaran elemen [" << barisPertukaran << "][" << kolomPertukaran << "]:\n";
    cout << "Matriks Pertama:\n";
    cetakMatriks(matriksPertama);
    cout << "Matriks Kedua:\n";
    cetakMatriks(matriksKedua);

    // Demonstrasi pertukaran nilai menggunakan pointer
    int nilaiX = 100, nilaiY = 200;
    int *pointerX = &nilaiX, *pointerY = &nilaiY;

    cout << "Sebelum pertukaran: nilaiX = " << nilaiX << ", nilaiY = " << nilaiY << "\n";
    pertukaranNilai(pointerX, pointerY);
    cout << "Setelah pertukaran: nilaiX = " << nilaiX << ", nilaiY = " << nilaiY << "\n";

    return 0;
}