#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef struct vertex* adrVertex;
typedef struct edge* adrEdge;

struct edge {
    char idVertex;
    int weight;
    adrEdge next;
};

struct vertex {
    char id;
    adrVertex next;
    adrEdge firstEdge;
};

struct graph {
    adrVertex first;
};

// fungsi derajat
int inDegree(graph G, adrVertex v);
int outDegree(graph G, adrVertex v);
int degree(graph G, adrVertex v);

// fungsi graf sederhana
bool isSimpleGraph(graph G);

#endif
