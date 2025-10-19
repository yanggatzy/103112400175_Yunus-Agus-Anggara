#include <iostream>
#include <string>
using namespace std;

const int MAX = 12;

struct Buku {
    string judul;
    string penulis;
};

struct RakBuku {
    Buku data[MAX];
    int top;
};

// Mengecek apakah stack kosong
bool IsEmpty(RakBuku S) {
    return (S.top == 0);
}

// Mengecek apakah stack penuh
bool IsFull(RakBuku S) {
    return (S.top == MAX);
}

// Menambahkan buku ke atas stack
void Push(RakBuku &S, string judul, string penulis) {
    if (IsFull(S)) {
        cout << "Rak sudah penuh, tidak bisa menambah buku lagi!\n";
    } else {
        S.top++;
        S.data[S.top].judul = judul;
        S.data[S.top].penulis = penulis;
        cout << "Buku \"" << judul << "\" oleh " << penulis << " berhasil ditambahkan.\n";
    }
}

// Menghapus buku teratas dari stack
void Pop(RakBuku &S, string &judul, string &penulis) {
    if (IsEmpty(S)) {
        cout << "Rak kosong, tidak ada buku yang bisa diambil!\n";
    } else {
        judul = S.data[S.top].judul;
        penulis = S.data[S.top].penulis;
        S.top--;
        cout << "Buku \"" << judul << "\" oleh " << penulis << " telah diambil dari rak.\n";
    }
}

// Mengambil buku berdasarkan judul dan mencatat nama penulisnya
void Get(RakBuku &S, string judulDicari, string &namaPenulis) {
    if (IsEmpty(S)) {
        cout << "Rak kosong, tidak ada buku yang bisa dicari!\n";
        return;
    }

    RakBuku temp;
    temp.top = 0;
    bool ditemukan = false;
    string judulTemp, penulisTemp;

    // Pindahkan buku satu per satu sampai ditemukan
    while (!IsEmpty(S)) {
        Pop(S, judulTemp, penulisTemp);
        if (judulTemp == judulDicari) {
            namaPenulis = penulisTemp;
            ditemukan = true;
            cout << "Buku \"" << judulDicari << "\" ditemukan. Penulis: " << namaPenulis << "\n";
            break;
        } else {
            Push(temp, judulTemp, penulisTemp);
        }
    }

    // Kembalikan buku-buku lain ke stack semula
    while (!IsEmpty(temp)) {
        Pop(temp, judulTemp, penulisTemp);
        Push(S, judulTemp, penulisTemp);
    }

    if (!ditemukan) {
        cout << "Buku dengan judul \"" << judulDicari << "\" tidak ditemukan di rak.\n";
    }
}

// Menampilkan semua buku dalam rak
void DisplayRak(RakBuku S) {
    if (IsEmpty(S)) {
        cout << "Rak kosong!\n";
    } else {
        cout << "\nIsi Rak Buku (dari atas ke bawah):\n";
        for (int i = S.top; i >= 1; i--) {
            cout << i << ". " << S.data[i].judul << " - " << S.data[i].penulis << "\n";
        }
    }
}

int main() {
    RakBuku rak;
    rak.top = 0;

    int pilihan;
    string judul, penulis, namaPenulis;

    do {
        cout << "\n=== MENU RAK BUKU ===";
        cout << "\n1. Tambah Buku (Push)";
        cout << "\n2. Ambil Buku Teratas (Pop)";
        cout << "\n3. Cari Buku Tertentu (Get)";
        cout << "\n4. Lihat Isi Rak";
        cout << "\n5. Keluar";
        cout << "\nPilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan judul buku: ";
                getline(cin, judul);
                cout << "Masukkan nama penulis: ";
                getline(cin, penulis);
                Push(rak, judul, penulis);
                break;

            case 2:
                Pop(rak, judul, penulis);
                break;

            case 3:
                cout << "Masukkan judul buku yang ingin dicari: ";
                getline(cin, judul);
                Get(rak, judul, namaPenulis);
                break;

            case 4:
                DisplayRak(rak);
                break;

            case 5:
                cout << "Terima kasih telah menggunakan program rak buku!\n";
                break;

            default:
                cout << "Pilihan tidak valid. Coba lagi!\n";
        }

    } while (pilihan != 5);

    return 0;
}
