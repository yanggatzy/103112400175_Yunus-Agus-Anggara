#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef struct Node* adrNode;
typedef struct Edge* adrEdge;

struct Edge {
    adrNode to;
    adrEdge next;
};

struct Node {
    char info;          // Nama kota
    bool visited;
    bool active;        // simulasi lockdown
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode newNode(char X);
void insertNode(Graph &G, char X);
adrNode findNode(Graph G, char X);
void connect(Graph &G, char A, char B);
void printGraph(Graph G);
void resetVisited(Graph G);
void DFS(adrNode P);
bool isConnected(Graph G, char ignoredNode);
void analisisKotaKritis(Graph G);

#endif
