#include "graph.h"

int inDegree(graph G, adrVertex v) {
    int count = 0;
    adrVertex u = G.first;

    while (u != NULL) {
        adrEdge e = u->firstEdge;
        while (e != NULL) {
            if (e->idVertex == v->id) {
                count++;
            }
            e = e->next;
        }
        u = u->next;
    }
    return count;
}

int outDegree(graph G, adrVertex v) {
    int count = 0;
    adrEdge e = v->firstEdge;

    while (e != NULL) {
        count++;
        e = e->next;
    }
    return count;
}

int degree(graph G, adrVertex v) {
    return inDegree(G, v) + outDegree(G, v);
}

bool isSimpleGraph(graph G) {
    adrVertex u = G.first;

    while (u != NULL) {
        adrEdge e1 = u->firstEdge;
        while (e1 != NULL) {
            adrEdge e2 = e1->next;
            while (e2 != NULL) {
                if (e1->idVertex == e2->idVertex) {
                    return false; // busur paralel ditemukan
                }
                e2 = e2->next;
            }
            e1 = e1->next;
        }
        u = u->next;
    }
    return true;
}
