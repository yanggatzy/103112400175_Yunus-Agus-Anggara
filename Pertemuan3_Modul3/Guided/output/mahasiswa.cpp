#include <iostream>
#include "mahasiswa.h"

using namespace std;

//Realisasi dari Fungsi InputMhs
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}   

//Realisasi dari Fungsi Rata2
float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}