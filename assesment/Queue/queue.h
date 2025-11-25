#ifndef QUEUE_H
#define QUEUE_H

#include <string>
using namespace std;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

const int MAX = 5;

struct Queue {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enQueue(Queue &Q, Paket p);
void deQueue(Queue &Q);
void viewQueue(Queue Q);
int TotalBiayaPengiriman(Queue Q);

#endif