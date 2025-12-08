#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = NULL;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6); 
    insertNode(root,7);
    
    cout << "Inorder     : ";
    printInorder(root);
    cout << endl;

    cout << "Preorder    : ";
    printPreorder(root);
    cout << endl;

    cout << "Postorder   : ";
    printPostorder(root);
    cout << endl;
    return 0;
}