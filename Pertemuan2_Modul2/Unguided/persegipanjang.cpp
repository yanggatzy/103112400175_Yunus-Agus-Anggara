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