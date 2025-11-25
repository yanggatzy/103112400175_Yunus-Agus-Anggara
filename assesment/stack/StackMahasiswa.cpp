#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa &StackMHS) {
    return StackMHS.Top == -1;
}

bool isFull(StackMahasiswa &StackMHS) {
    return StackMHS.Top == MAX - 1;
}

void createStack(StackMahasiswa &StackMHS) {
    StackMHS.Top = -1;
}

void Push(StackMahasiswa &StackMHS) {
    if (isFull(StackMHS)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    
    Mahasiswa m;
    cout << "Masukkan data mahasiswa:" << endl;
    cout << "Nama: "; cin.ignore(); getline(cin, m.Nama);
    cout << "NIM: "; getline(cin, m.NIM);
    cout << "NilaiTugas: "; cin >> m.NilaiTugas;
    cout << "NilaiUTS: "; cin >> m.NilaiUTS;
    cout << "NilaiUAS: "; cin >> m.NilaiUAS;
    
    StackMHS.Top++;
    StackMHS.data[StackMHS.Top] = m;
}

void Pop(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!" << endl;
        return;
    }
    StackMHS.Top--;
    cout << "Data berhasil di-pop" << endl;
}

void Update(StackMahasiswa &StackMHS, int posisi) {
    if (posisi < 1 || posisi > StackMHS.Top + 1) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    
    int index = StackMHS.Top - posisi + 1;
    cout << "Update data posisi " << posisi << ":" << endl;
    cout << "Nama: "; cin.ignore(); getline(cin, StackMHS.data[index].Nama);
    cout << "NIM: "; getline(cin, StackMHS.data[index].NIM);
    cout << "NilaiTugas: "; cin >> StackMHS.data[index].NilaiTugas;
    cout << "NilaiUTS: "; cin >> StackMHS.data[index].NilaiUTS;
    cout << "NilaiUAS: "; cin >> StackMHS.data[index].NilaiUAS;
    cout << "Data berhasil di-update" << endl;
}

void View(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!" << endl;
        return;
    }
    
    cout << "\n=== DATA STACK MAHASISWA ===" << endl;
    for (int i = StackMHS.Top; i >= 0; i--) {
        float nilaiAkhir = 0.2 * StackMHS.data[i].NilaiTugas + 
                          0.4 * StackMHS.data[i].NilaiUTS + 
                          0.4 * StackMHS.data[i].NilaiUAS;
        
        cout << "Posisi: " << StackMHS.Top - i + 1 << endl;
        cout << "Nama: " << StackMHS.data[i].Nama << endl;
        cout << "NIM: " << StackMHS.data[i].NIM << endl;
        cout << "Nilai Tugas: " << StackMHS.data[i].NilaiTugas << endl;
        cout << "Nilai UTS: " << StackMHS.data[i].NilaiUTS << endl;
        cout << "Nilai UAS: " << StackMHS.data[i].NilaiUAS << endl;
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        cout << "------------------------" << endl;
    }
}
void SearchNilaiAkhir(StackMahasiswa &StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!" << endl;
        return;
    }
    
    cout << "\n=== MAHASISWA DENGAN NILAI AKHIR ANTARA "
         << NilaiAkhirMin << " DAN " << NilaiAkhirMax << " ===" << endl;
    
    bool found = false;
    for (int i = 0; i <= StackMHS.Top; i++) {
        float nilaiAkhir = 0.2 * StackMHS.data[i].NilaiTugas + 
                          0.4 * StackMHS.data[i].NilaiUTS + 
                          0.4 * StackMHS.data[i].NilaiUAS;
        
        if (nilaiAkhir >= NilaiAkhirMin && nilaiAkhir <= NilaiAkhirMax) {
            cout << "Nama: " << StackMHS.data[i].Nama << ", NIM: " 
                 << StackMHS.data[i].NIM << ", Nilai Akhir: " 
                 << nilaiAkhir << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Tidak ada mahasiswa dengan nilai akhir dalam rentang tersebut." << endl;
    }
}

void MaxNilaiAkhir(StackMahasiswa &StackMHS) {
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong!" << endl;
        return;
    }
    
    float maxNilaiAkhir = -1.0;
    int indexMax = -1;
    
    for (int i = 0; i <= StackMHS.Top; i++) {
        float nilaiAkhir = 0.2 * StackMHS.data[i].NilaiTugas + 
                          0.4 * StackMHS.data[i].NilaiUTS + 
                          0.4 * StackMHS.data[i].NilaiUAS;
        
        if (nilaiAkhir > maxNilaiAkhir) {
            maxNilaiAkhir = nilaiAkhir;
            indexMax = i;
        }
    }
    
    cout << "\n=== MAHASISWA DENGAN NILAI AKHIR TERBESAR ===" << endl;
    cout << "Nama: " << StackMHS.data[indexMax].Nama << endl;
    cout << "NIM: " << StackMHS.data[indexMax].NIM << endl;
    cout << "Nilai Tugas: " << StackMHS.data[indexMax].NilaiTugas << endl;
    cout << "Nilai UTS: " << StackMHS.data[indexMax].NilaiUTS << endl;
    cout << "Nilai UAS: " << StackMHS.data[indexMax].NilaiUAS << endl;
    cout << "Nilai Akhir: " << maxNilaiAkhir << endl;
}