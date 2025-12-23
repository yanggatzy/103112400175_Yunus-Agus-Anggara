#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node* left;
    Node* right;
};

/* Deklarasi Function */
bool isEmpty(Node* root);
void createTree(Node*& root);
Node* newNode(string nama, float berat, string tier);
void insertNode(Node*& root, Node* node);

void inOrder(Node* root);
Node* mostLeft(Node* root);
Node* mostRight(Node* root);

Node* searchByBeratBadan(Node* root, float berat, Node*& parent);

#endif
