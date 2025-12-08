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
    insertNode(root, 6);  // duplikat, akan diabaikan
    insertNode(root, 7);

    cout << "InOrder Traversal: ";
    printInorder(root);

    cout << endl;
    return 0;
}
