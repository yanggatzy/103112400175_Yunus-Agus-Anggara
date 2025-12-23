#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');

    connect(G, 'A', 'B');
    connect(G, 'B', 'C');
    connect(G, 'C', 'D');
    connect(G, 'B', 'E');

    cout << "Membangun Jaringan Distribusi Vaksin\n";
    printGraph(G);

    analisisKotaKritis(G);

    return 0;
}
