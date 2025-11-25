#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List L;
    createList(L);

    int pilihan;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                insertAkhir(L, nama);
                break;

            case 2:
                cout << "Masukkan nama untuk delete: ";
                cin >> nama;
                deleteNama(L, nama);
                break;

            case 3:
                viewList(L);
                break;

            case 4:
                cout << "Jumlah nama dengan huruf genap: "
                     << hitungGenap(L) << endl;
                break;

            case 0:
                break;

            default:
                cout << "Pilihan salah\n";
        }

    } while (pilihan != 0);

    return 0;
}
