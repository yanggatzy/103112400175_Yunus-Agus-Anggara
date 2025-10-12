#include <iostream>
using namespace std;

float NilaiAkhir(float uts, float uas, float tugas) {
    return (uts * 0.3) + (uas * 0.4) + (tugas * 0.3);
}

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

int main() {
    Mahasiswa data[10];
    int jumlah;
    
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlah;
    
    // Input data mahasiswa
    for(int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa " << i+1 << ":\n";
        cout << "Nama: ";
        cin >> data[i].nama;  // Hanya membaca satu kata
        cout << "NIM: ";
        cin >> data[i].nim;
        cout << "Nilai UTS: ";
        cin >> data[i].uts;
        cout << "Nilai UAS: ";
        cin >> data[i].uas;
        cout << "Nilai Tugas: ";
        cin >> data[i].tugas;
        
        // Hitung nilai akhir
        data[i].nilaiAkhir = NilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);
    }
    
    // Tampilkan data
    cout << "\n\nData Mahasiswa:\n";
    cout << "No\tNama\tNIM\t\tUTS\tUAS\tTugas\tNilai Akhir\n";
    for(int i = 0; i < jumlah; i++) {
        cout << i+1 << "\t" << data[i].nama << "\t" 
             << data[i].nim << "\t" << data[i].uts << "\t" 
             << data[i].uas << "\t" << data[i].tugas << "\t" 
             << data[i].nilaiAkhir << endl;
    }
    
    return 0;
}