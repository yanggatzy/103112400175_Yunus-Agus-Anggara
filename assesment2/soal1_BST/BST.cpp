#include "bst.h"
#include <iostream>
using namespace std;

bool isEmpty(Node* root) {
    return root == NULL;
}

void createTree(Node*& root) {
    root = NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node* node = new Node;
    node->namaMember = nama;
    node->beratBadan = berat;
    node->tierMember = tier;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(Node*& root, Node* node) {
    if (root == NULL) {
        root = node;
        return;
    }

    if (node->beratBadan < root->beratBadan)
        insertNode(root->left, node);
    else
        insertNode(root->right, node);
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}

Node* mostLeft(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* mostRight(Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

Node* searchByBeratBadan(Node* root, float berat, Node*& parent) {
    if (root == NULL)
        return NULL;

    if (root->beratBadan == berat)
        return root;

    parent = root;

    if (berat < root->beratBadan)
        return searchByBeratBadan(root->left, berat, parent);
    else
        return searchByBeratBadan(root->right, berat, parent);
}
