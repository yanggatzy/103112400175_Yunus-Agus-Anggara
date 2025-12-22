# <h1 align="center">Laporan Praktikum Modul 14 - GRAPH</h1>
<p align="center">Yunus Agus Anggara - 103112400175</p>

## Dasar Teori
Graf (graph) merupakan salah satu struktur data non-linier yang digunakan untuk merepresentasikan hubungan antar objek. Graf terdiri dari sekumpulan simpul (vertex/node) dan sisi (edge) yang menghubungkan pasangan simpul tertentu. Struktur data graf banyak digunakan untuk memodelkan berbagai permasalahan nyata seperti jaringan komputer, peta jalan, jejaring sosial, dan struktur dependensi data [1].

Secara umum, graf dapat dibedakan menjadi graf berarah (directed graph) dan graf tidak berarah (undirected graph). Pada graf berarah, setiap sisi memiliki arah tertentu dari satu simpul ke simpul lain, sedangkan pada graf tidak berarah, sisi menyatakan hubungan dua arah antar simpul [1].

Representasi graf dapat dilakukan dengan beberapa cara, salah satunya adalah adjacency list (senarai ketetanggaan). Pada representasi ini, setiap simpul menyimpan daftar simpul lain yang terhubung dengannya. Representasi adjacency list lebih efisien untuk graf yang bersifat jarang (sparse graph) karena penggunaan memori yang lebih kecil dibandingkan matriks ketetanggaan [2].

Selain itu, graf juga mendukung proses penelusuran (traversal), yaitu Depth First Search (DFS) dan Breadth First Search (BFS). DFS melakukan penelusuran dengan mendalami satu cabang terlebih dahulu sebelum berpindah ke cabang lain, sedangkan BFS menelusuri graf secara melebar berdasarkan level kedalaman simpul [2].


### A. Struktur Data Graph<br/>
Struktur data graph terdiri dari simpul (node) dan sisi (edge) yang saling terhubung.
#### 1. Node (Vertex)
Node merupakan elemen utama pada graph yang menyimpan informasi tertentu dan penunjuk ke node lain melalui edge.
#### 2. Edge
Edge merupakan penghubung antar node yang menunjukkan adanya relasi atau hubungan.
#### 3. Adjacency List
Adjacency list adalah cara merepresentasikan graph dengan menggunakan linked list untuk menyimpan node-node yang saling terhubung.

### B. Penelusuran Graph<br/>
Penelusuran graph digunakan untuk mengunjungi seluruh node dalam graph secara sistematis.
#### 1. Depth First Search (DFS)
DFS bekerja dengan mengunjungi node sedalam mungkin sebelum kembali (backtracking).
#### 2. Breadth First Search (BFS)
BFS mengunjungi node berdasarkan urutan level menggunakan struktur data queue.
#### 3. Penanda Visited
Atribut visited digunakan untuk mencegah pengunjungan node yang sama secara berulang.

## Guided 

### 1. Graph
graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode*adrNode;
typedef struct ElmEdge*adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```
graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL){
        if(P -> info == X) return P;
        P = P -> next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end){
    adrNode pStart = findNode (G, start);
    adrNode pEnd = findNode (G, end);

    if (pStart != NULL && pEnd != NULL){
        adrEdge newEdge = new ElmEdge;
        newEdge -> node = pEnd;
        newEdge -> next = pStart -> firstEdge; //insert first di list edge
        pStart -> firstEdge = newEdge;
    }
}
```
graph_init.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;

void createGraph(Graph &G ){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G ,infoGraph X){
    adrNode P = allocateNode(X);
    if (G.first == NULL){
        G.first = P;
    } else {
        adrNode Q = G.first;    
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
graph_print.cpp
```C++
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
```
main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    Graph G;
    createGraph(G);

    insertNode (G,'A');
    insertNode (G,'B');
    insertNode (G,'C');
    insertNode (G,'D');

    connectNode (G,'A','B');
    connectNode (G,'A','C');
    connectNode (G,'B','D');
    connectNode (G,'C','D');
    cout<<"isi graph: "<<endl;
    printGraph(G);
    return 0;
}
```
Pada bagian guided ini dibuat sebuah ADT Graph berarah menggunakan representasi adjacency list. Setiap node memiliki informasi berupa karakter, penanda visited, pointer ke edge pertama, dan pointer ke node berikutnya. Prosedur connectNode digunakan untuk menghubungkan node awal ke node tujuan secara berarah. Hasil implementasi ditampilkan menggunakan prosedur printGraph yang menunjukkan keterhubungan antar node dalam graph.

## Unguided 

### 1. Buatlah ADT Graph tidak berarah file “graph.h”.Buatlah implementasi ADT Graph pada file“graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp” dan Buatlah prosedur untuk menampilkanhasil penelusuran DFS serta penelusuran BFS.
graph.h
```C++
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
```
graph.cpp
```C++
#include "graph.h"
#include<queue>

void CreateGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void InsertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;
    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }

}
void ConnectNode(adrNode N1, adrNode N2){
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node " << P->info << " Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void Visited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = 0;
        P = P->next;
    }
}

//prosedur untuk menampilkanhasil penelusuran DFS
void printDFS(Graph G, adrNode N){
    if(N != NULL && N->visited == 0){
        cout << N->info << " ";
        N->visited = 1;

        adrEdge E = N->firstEdge;
        while(E != NULL){
            if(E->node->visited == 0){
                printDFS(G, E->node);
            }
            E = E->next;
        }
    }
}

//prosedur untuk menampilkanhasil penelusuran BFS
void printBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    queue<adrNode> Q;

    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}
```
main.cpp
```C++
#include "graph.h"
#include<iostream>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode a = findNode(G, 'A');
    adrNode b = findNode(G, 'B');
    adrNode c = findNode(G, 'C');
    adrNode d = findNode(G, 'D');
    adrNode e = findNode(G, 'E');
    adrNode f = findNode(G, 'F');
    adrNode g = findNode(G, 'G'); 
    adrNode h = findNode(G, 'H');

    ConnectNode(a, b);
    ConnectNode(a, c);
    ConnectNode(b, d);
    ConnectNode(b, e);
    ConnectNode(c, f);
    ConnectNode(c, g);
    ConnectNode(d, h);
    ConnectNode(e, h);
    ConnectNode(f, h);
    ConnectNode(g, h);
    PrintInfoGraph(G);
    cout << endl ;


    Visited(G);
    cout << "Hasil penulusuran DFS : " ;
    printDFS(G, a);
    cout << endl ;


    Visited(G);
    cout << "Hasil penulusuran BFS : " ;
    printBFS(G, a);
    cout << endl ;
    
    return 0;

}
```
### Output Unguided :

##### Output 1 Menampilkan setiap node beserta node-node lain yang terhubung (PrintInfoGraph).
![Screenshot Output Unguided 1_14](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan12_Modul14/Unguided/Output-Unguided1-Modul14.png)

##### Output 2 Hasil penelusuran DFS.
![Screenshot Output Unguided 2_14](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan12_Modul14/Unguided/Output-Unguided2-Modul14.png)

##### Output 3 Hasil penelusuran BFS.
![Screenshot Output Unguided 3_14](https://github.com/yanggatzy/103112400175_Yunus-Agus-Anggara/blob/main/Pertemuan12_Modul14/Unguided/Output-Unguided3-Modul14.png)

Pada bagian unguided, dibuat ADT Graph tidak berarah, di mana setiap sisi yang ditambahkan akan menghubungkan dua node secara dua arah. Hal ini terlihat pada prosedur ConnectNode yang membuat dua edge sekaligus untuk masing-masing node.

Selain itu, diimplementasikan algoritma penelusuran DFS dan BFS. DFS direalisasikan menggunakan pendekatan rekursif dengan memanfaatkan atribut visited, sedangkan BFS menggunakan struktur data queue untuk mengatur urutan penelusuran node. Prosedur Visited digunakan untuk mereset status kunjungan sebelum melakukan traversal ulang. Hasil traversal DFS dan BFS menunjukkan perbedaan urutan kunjungan node sesuai dengan karakteristik masing-masing algoritma.

## Kesimpulan
Berdasarkan hasil praktikum Modul 14 tentang Graph, dapat disimpulkan bahwa struktur data graph sangat efektif dalam merepresentasikan hubungan antar data. Representasi adjacency list memudahkan pengelolaan node dan edge serta lebih efisien dalam penggunaan memori. Implementasi algoritma DFS dan BFS menunjukkan cara penelusuran graph yang berbeda namun saling melengkapi. DFS cocok untuk eksplorasi mendalam, sedangkan BFS lebih sesuai untuk penelusuran berdasarkan tingkat kedalaman. Pemahaman konsep graph dan traversal sangat penting dalam pengembangan aplikasi yang melibatkan struktur data kompleks.

## Referensi
[1] Sedgewick, R., & Wayne, K. (2011). Graph Algorithms. Princeton University.
[2] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
