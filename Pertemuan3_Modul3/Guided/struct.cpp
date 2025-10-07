#include<iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    float niali1, nilai2;
};

void inputMhs(Mahasiswa &m) {
    cout << "Masukkan Nama: ";
    cin >> m.nama;
    cout << "Masukkan Nilai 1: ";
    cin >> m.niali1;      
    cout << "Masukkan Nilai 2: ";
    cin >> m.nilai2;
}

float rata2(Mahasiswa m) {
    return float (m.niali1 + m.nilai2) / 2;
}

int main() {
    Mahasiswa mhs; //pemanggilan struct(ADT)
    inputMhs(mhs); //pemanggilan prosedur
    cout << "Rata-rata: " << rata2(mhs) << endl; //pemanggilan fungsi
    return 0;
}