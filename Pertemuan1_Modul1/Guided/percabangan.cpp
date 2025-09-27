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