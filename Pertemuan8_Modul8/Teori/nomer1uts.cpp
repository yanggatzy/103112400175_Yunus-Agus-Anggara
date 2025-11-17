#include <iostream>
#include <string>
using namespace std;

// =======================
// DEFINISI STRUKTUR DATA
// =======================
struct tPanen {
    string namaTanaman;
    string bulanPanen;
    int jumlahPanen;
};

typedef tPanen infotype;

struct elmList {
    infotype info;
    elmList* next;
};

struct List {
    elmList* first;
};

// =======================
// FUNGSI / PROSEDUR DASAR
// =======================
void createList(List &L) {
    L.first = nullptr;
}

elmList* createNewElm(infotype x) {
    elmList* p = new elmList;
    p->info = x;
    p->next = nullptr;
    return p;
}

// =====================================================
// b) PROSEDUR TAMBAH DATA SEBAGAI ELEMEN PERTAMA
// =====================================================
void tambahData(List &L, infotype x) {
    elmList* p = createNewElm(x);
    p->next = L.first;
    L.first = p;
}

// =====================================================
// c) FUNGSI MENCARI HASIL PANEN TERBANYAK
// =====================================================
elmList* panenTerbanyak(List L) {
    if (L.first == nullptr) {
        return nullptr;
    }

    elmList* p = L.first;
    elmList* maxP = p;
    int maxJumlah = p->info.jumlahPanen;

    while (p != nullptr) {
        if (p->info.jumlahPanen > maxJumlah) {
            maxJumlah = p->info.jumlahPanen;
            maxP = p;
        }
        p = p->next;
    }

    return maxP;
}

// =====================================================
// d) PROSEDUR MENAMPILKAN PANEN BERDASARKAN BULAN
// =====================================================
void panenBulanan(List L, string bulan) {
    if (L.first == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    elmList* p = L.first;
    bool found = false;

    cout << "Tanaman yang dipanen pada bulan " << bulan << ": ";
    while (p != nullptr) {
        if (p->info.bulanPanen == bulan) {
            cout << p->info.namaTanaman << " ";
            found = true;
        }
        p = p->next;
    }

    if (!found)
        cout << "(tidak ada data)";
    cout << endl;
}

// =======================
// FUNGSI UTAMA (main)
// =======================
int main() {
    List L;
    createList(L);

    // Data contoh
    tPanen a = {"Padi", "Maret", 100};
    tPanen b = {"Jagung", "Maret", 75};
    tPanen c = {"Labu", "April", 50};
    tPanen d = {"Kedelai", "Maret", 120};

    // Tambahkan data ke list
    tambahData(L, a);
    tambahData(L, b);
    tambahData(L, c);
    tambahData(L, d);

    // Tampilkan hasil panen pada bulan Maret
    panenBulanan(L, "Maret");

    // Cari hasil panen terbanyak
    elmList* maxPanen = panenTerbanyak(L);
    if (maxPanen != nullptr) {
        cout << "Hasil panen terbanyak: "
             << maxPanen->info.namaTanaman
             << " (" << maxPanen->info.jumlahPanen << " kg)"
             << endl;
    } else {
        cout << "List kosong." << endl;
    }

    return 0;
}
