#include "DoublyList.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype x;
    string nopolCari, nopolHapus;
    int n;

    cout << "Masukkan jumlah data kendaraan: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan Nomor Polisi : ";
        cin >> x.nopol;

        // Cek apakah nopol sudah ada
        address cek = findElm(L, x.nopol);
        if (cek != Nil) {
            cout << "Nomor Polisi sudah terdaftar\n\n";
            i--; // ulangi input
            continue;
        }

        cout << "Masukkan Warna Kendaraan : ";
        cin >> x.warna;
        cout << "Masukkan Tahun Kendaraan : ";
        cin >> x.thnBuat;
        cout << endl;

        address P = alokasi(x);
        insertLast(L, P);
    }

    // Cetak semua data kendaraan
    printInfo(L);

    // Cari kendaraan berdasarkan nopol
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> nopolCari;
    cout << endl;

    address hasil = findElm(L, nopolCari);
    if (hasil != Nil) {
        cout << "Nomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna : " << hasil->info.warna << endl;
        cout << "Tahun : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << endl;

    // Hapus kendaraan berdasarkan nopol
    cout << "Masukan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;
    cout << endl;

    deleteByNopol(L, nopolHapus);
    cout << endl;

    // Tampilkan data setelah penghapusan
    printInfo(L);

    return 0;
}
