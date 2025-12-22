#include "graph.h"
#include <iostream>
using namespace std;

void printGraph(Graph G){
    adrNode P = G.first;
    while (P != NULL){
        cout << "Node: " << P->info << " terhubung ke ";
        adrEdge E = P->firstEdge;
        while (E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        P = P->next;
    }
}