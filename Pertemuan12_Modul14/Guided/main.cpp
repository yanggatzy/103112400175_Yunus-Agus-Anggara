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