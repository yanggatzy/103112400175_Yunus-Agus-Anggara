#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List L;
    createList(L);

    int menu, nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), "
             << "4 reverse & view (depan), 0 exit\n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertAkhir(L, nilai);
                break;

            case 2:
                deleteLast(L);
                break;

            case 3:
                viewDepan(L);
                break;

            case 4:
                reverseList(L);
                cout << "List setelah di-reverse: ";
                viewDepan(L);
                break;

            case 0:
                break;

            default:
                cout << "Menu salah!\n";
        }
    } while (menu != 0);

    return 0;
}
