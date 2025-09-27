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