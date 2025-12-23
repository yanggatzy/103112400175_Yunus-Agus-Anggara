#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode newNode(char X) {
    adrNode P = new Node;
    P->info = X;
    P->visited = false;
    P->active = true;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, char X) {
    adrNode P = newNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
}

adrNode findNode(Graph G, char X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

void connect(Graph &G, char A, char B) {
    adrNode NA = findNode(G, A);
    adrNode NB = findNode(G, B);

    adrEdge EA = new Edge;
    EA->to = NB;
    EA->next = NA->firstEdge;
    NA->firstEdge = EA;

    adrEdge EB = new Edge;
    EB->to = NA;
    EB->next = NB->firstEdge;
    NB->firstEdge = EB;
}

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->to->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void resetVisited(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = false;
        P = P->next;
    }
}

void DFS(adrNode P) {
    if (P == NULL || !P->active || P->visited)
        return;

    P->visited = true;
    adrEdge E = P->firstEdge;
    while (E != NULL) {
        DFS(E->to);
        E = E->next;
    }
}

bool isConnected(Graph G, char ignoredNode) {
    adrNode P = G.first;

    while (P != NULL) {
        P->active = (P->info != ignoredNode);
        P = P->next;
    }

    resetVisited(G);

    adrNode start = G.first;
    while (start != NULL && !start->active)
        start = start->next;

    if (start == NULL) return true;

    DFS(start);

    P = G.first;
    while (P != NULL) {
        if (P->active && !P->visited)
            return false;
        P = P->next;
    }

    return true;
}

void analisisKotaKritis(Graph G) {
    adrNode P = G.first;

    cout << "\nAnalisis Kota Kritis (Single Point of Failure)\n";

    while (P != NULL) {
        if (!isConnected(G, P->info)) {
            cout << "[PERINGATAN] Kota " << P->info
                 << " adalah KOTA KRITIS!\n";
            cout << "-> Jika " << P->info
                 << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << P->info
                 << " aman (redundansi oke).\n";
        }
        P = P->next;
    }
}
