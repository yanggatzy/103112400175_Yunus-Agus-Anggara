#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue antrian;
    int pilihan;
    Paket p;
    
    // 1) Buat queue kosong
    createQueue(antrian);
    cout << "Queue berhasil dibuat" << endl;
    
    // Input data paket sesuai soal
    cout << "\n=== INPUT DATA PAKET ===" << endl;
    
    Paket paket1 = {"123456", "Hutao", 14, "Sumeru"};
    Paket paket2 = {"234567", "Ayaka", 10, "Fontaine"};
    Paket paket3 = {"345678", "Bennet", 7, "Natlan"};
    Paket paket4 = {"456789", "Furina", 16, "Liyue"};
    Paket paket5 = {"567890", "Neuvillette", 6, "Inazuma"};
    
    enQueue(antrian, paket1);
    enQueue(antrian, paket2);
    enQueue(antrian, paket3);
    enQueue(antrian, paket4);
    enQueue(antrian, paket5);
    
    cout << "\n=== TAMPILKAN QUEUE SETELAH INPUT ===" << endl;
    viewQueue(antrian);
    
    cout << "\n=== HAPUS DATA PAKET (deQueue 1x) ===" << endl;
    deQueue(antrian);
    
    cout << "\n=== TAMPILKAN QUEUE SETELAH deQueue ===" << endl;
    viewQueue(antrian);
    
    do {
        cout << "\n--- Komaniya Ekspress ---" << endl;
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. Tampilkan queue paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan anda : ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                cout << "\n=== INPUT DATA PAKET ===" << endl;
                cout << "KodeResi: "; 
                cin >> p.KodeResi;
                cout << "NamaPengirim: "; 
                cin.ignore(); 
                getline(cin, p.NamaPengirim);
                cout << "BeratBarang: "; 
                cin >> p.BeratBarang;
                cout << "Tujuan: "; 
                cin.ignore(); 
                getline(cin, p.Tujuan);
                enQueue(antrian, p);
                break;
                
            case 2:
                cout << "\n=== HAPUS DATA PAKET ===" << endl;
                deQueue(antrian);
                break;
                
            case 3:
                viewQueue(antrian);
                break;
                
            case 4:
                {
                    int total = TotalBiayaPengiriman(antrian);
                    cout << "\n=== TOTAL BIAYA PENGIRIMAN ===" << endl;
                    cout << "Total Berat: " << (total / 8250) << " kg" << endl;
                    cout << "Biaya per kg: Rp 8250" << endl;
                    cout << "Total Biaya: Rp " << total << endl;
                }
                break;
                
            case 0:
                cout << "Terima kasih telah menggunakan Komaniya Ekspress!" << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
    
    return 0;
}