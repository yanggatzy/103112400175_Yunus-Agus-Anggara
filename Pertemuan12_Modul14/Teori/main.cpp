#include "graph.h"

int main() {
    graph G;
    G.first = NULL;

    // ===== CREATE VERTEX =====
    adrVertex A = new vertex{'A', NULL, NULL};
    adrVertex B = new vertex{'B', NULL, NULL};
    adrVertex C = new vertex{'C', NULL, NULL};
    adrVertex D = new vertex{'D', NULL, NULL};
    adrVertex E = new vertex{'E', NULL, NULL};

    // ===== LINK VERTEX (A → B → C → D → E) =====
    G.first = A;
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;

    // ===== CREATE EDGES =====
    // A → C (12)
    A->firstEdge = new edge{'C', 12, NULL};
    A->firstEdge->next = new edge{'D', 60, NULL};

    // B → A (10)
    B->firstEdge = new edge{'A', 10, NULL};

    // C → B (20)
    C->firstEdge = new edge{'B', 20, NULL};
    C->firstEdge->next = new edge{'D', 32, NULL};

    // D → (tidak ada edge)
    D->firstEdge = NULL;

    // E → A (7)
    E->firstEdge = new edge{'A', 7, NULL};

    // ===== TEST OUTPUT =====
    cout << "InDegree A  : " << inDegree(G, A) << endl;
    cout << "OutDegree A : " << outDegree(G, A) << endl;
    cout << "Degree A    : " << degree(G, A) << endl;

    cout << "Is Simple Graph? ";
    if (isSimpleGraph(G))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
