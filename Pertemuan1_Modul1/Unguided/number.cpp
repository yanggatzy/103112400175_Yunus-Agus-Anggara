#include <iostream>
using namespace std;

int main() {
    int angka;
    
    cout << "Masukkan angka (0-100): ";
    cin >> angka;
    
    // Validasi input
    if (angka < 0 || angka > 100) {
        cout << "Angka di luar range (0-100)" << endl;
        return 1;
    }
    
    string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", 
                        "Lima Puluh", "Enam Puluh", "Tujuh Puluh", 
                        "Delapan Puluh", "Sembilan Puluh"};
    
    string satuan[] = {"Nol", "Satu", "Dua", "Tiga", "Empat", "Lima", 
                       "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh",
                       "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas",
                       "Lima Belas", "Enam Belas", "Tujuh Belas", 
                       "Delapan Belas", "Sembilan Belas"};
    
    cout << "Output: ";
    
    if (angka == 0) {
        cout << "Nol";
    } else if (angka >= 1 && angka <= 19) {
        cout << satuan[angka];
    } else if (angka >= 20 && angka <= 99) {
        int puluh = angka / 10;
        int satu = angka % 10;
        
        cout << puluhan[puluh];
        if (satu > 0) {
            cout << " " << satuan[satu];
        }
    } else if (angka == 100) {
        cout << "Seratus";
    }
    
    cout << endl;
    
    return 0;
}