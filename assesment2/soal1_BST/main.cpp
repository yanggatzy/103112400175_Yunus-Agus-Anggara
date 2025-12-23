#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    Node* root;

    // Root
    root = newNode("Rizkina Azizah", 60, "Basic");

    // Level 1
    root->left  = newNode("Hakan Ismail", 50, "Bronze");
    root->right = newNode("Olivia Saevali", 65, "Silver");

    // Level 2 kiri
    root->left->left  = newNode("Felix Pedrosa", 47, "Gold");
    root->left->right = newNode("Gamel Al Ghifari", 56, "Platinum");
    root->left->right->left = newNode("Mutiara Fauziah", 52, "Bronze");

    // Level 2 kanan
    root->right->right = newNode("Hanif Al Paiz", 70, "Basic");

    // Child node 70
    root->right->right->left  = newNode("Davi Ilyas", 68, "Silver");
    root->right->right->right = newNode("Abdad Mubarok", 81, "Gold");

    // Output
    cout << "=== Traversal InOrder ===" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "Node MostLeft : " << mostLeft(root)->beratBadan << endl;
    cout << "Node MostRight : " << mostRight(root)->beratBadan << endl;
    cout << endl;

    Node* parent = NULL;
    Node* found = searchByBeratBadan(root, 70, parent);

    if (found != NULL) {
        cout << "Data ditemukan didalam BST!" << endl;
        cout << "--- Data Node Yang Dicari ---" << endl;
        cout << "Nama Member : " << found->namaMember << endl;
        cout << "Berat Badan : " << found->beratBadan << endl;
        cout << "Tier Member : " << found->tierMember << endl;

        cout << "--- Data Parent ---" << endl;
        cout << "Nama Member : " << parent->namaMember << endl;
        cout << "Berat Badan : " << parent->beratBadan << endl;
        cout << "Tier Member : " << parent->tierMember << endl;

        cout << "---" << endl;
        cout << "Tidak Memiliki Sibling" << endl;

        cout << "--- Data Child Kiri ---" << endl;
        cout << "Nama Member : " << found->left->namaMember << endl;
        cout << "Berat Badan : " << found->left->beratBadan << endl;
        cout << "Tier Member : " << found->left->tierMember << endl;

        cout << "---" << endl;
        cout << "--- Data Child Kanan ---" << endl;
        cout << "Nama Member : " << found->right->namaMember << endl;
        cout << "Berat Badan : " << found->right->beratBadan << endl;
        cout << "Tier Member : " << found->right->tierMember << endl;
    }

    return 0;
}
