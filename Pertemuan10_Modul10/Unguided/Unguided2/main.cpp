#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = NULL;  
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);   // duplikat, diabaikan
    insertNode(root, 7);

    printInorder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    return 0;
}
