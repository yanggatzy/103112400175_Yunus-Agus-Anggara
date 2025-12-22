#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
    adrNode first;
};
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
adrNode allocateNode(infoGraph X);
//prosedur untuk menampilkanhasil penelusuran DFS
void printDFS(Graph G, adrNode N);    
//prosedur untuk menampilkanhasil penelusuran BFS
void printBFS(Graph G, adrNode N);                     
void Visited(Graph &G);
#endif           