#ifndef MMAHASUSWA_H
#define MMAHASUSWA_H

//Definisi Tipe(Sturct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

//Deklarasi Primitif (fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
