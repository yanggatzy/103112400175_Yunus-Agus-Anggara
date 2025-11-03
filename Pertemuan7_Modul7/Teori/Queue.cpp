#include <iostream>
using namespace std;

// ======== Struktur Data (ADT) ========
struct InfoTugas {
    char Pekerjaan;    // ID pekerjaan
    int waktu;         // waktu total yang dibutuhkan
    int Dikerjakan;    // waktu yang telah dikerjakan
};

struct ElmTugas {
    InfoTugas info;
    ElmTugas* next;
};

struct AntrianTugas {
    ElmTugas* Head;
    ElmTugas* Tail;
};

// ======== Inisialisasi Antrian ========
void createQueue(AntrianTugas &Q) {
    Q.Head = nullptr;
    Q.Tail = nullptr;
}

// ======== TambahTugas (Enqueue) ========
void TambahTugas(AntrianTugas &Q, ElmTugas* P) {
    if (Q.Head == nullptr) {
        // Jika antrian kosong
        Q.Head = P;
        Q.Tail = P;
        P->next = P; // circular
    } else {
        // Jika antrian tidak kosong
        P->next = Q.Head;
        Q.Tail->next = P;
        Q.Tail = P;
    }
}

// ======== HapusTugas (Dequeue) ========
void HapusTugas(AntrianTugas &Q, ElmTugas* &P) {
    if (Q.Head == nullptr) {
        P = nullptr; // antrian kosong
    } else if (Q.Head == Q.Tail) {
        // Hanya satu elemen
        P = Q.Head;
        Q.Head = nullptr;
        Q.Tail = nullptr;
    } else {
        // Lebih dari satu elemen
        P = Q.Head;
        Q.Head = Q.Head->next;
        Q.Tail->next = Q.Head; // tetap circular
    }
}

// ======== Proses Semua Tugas ========
void DailyTask(AntrianTugas &Q) {
    if (Q.Head == nullptr) {
        cout << "Antrian kosong!\n";
        return;
    }

    ElmTugas *P;
    bool selesai = false;
    int total = 0;

    while (!selesai) {
        selesai = true;
        int count = 0; // hitung jumlah elemen
        ElmTugas *temp = Q.Head;

        do {
            count++;
            temp = temp->next;
        } while (temp != Q.Head);

        for (int i = 0; i < count; i++) {
            HapusTugas(Q, P);
            P->info.Dikerjakan++;
            total++;

            if (P->info.Dikerjakan < P->info.waktu) {
                TambahTugas(Q, P);
                selesai = false;
            } 
        }
    }

    cout << "Total = " << total << " jam" << endl;
}

// ======== Program Utama ========
int main() {
    AntrianTugas Q;
    createQueue(Q);

    // Tambahkan contoh data tugas
    ElmTugas *A = new ElmTugas{{'A', 9, 0}, nullptr};
    ElmTugas *B = new ElmTugas{{'B', 7, 0}, nullptr};
    ElmTugas *C = new ElmTugas{{'C', 5, 0}, nullptr};
     ElmTugas *D = new ElmTugas{{'C', 1, 0}, nullptr};

    TambahTugas(Q, A);
    TambahTugas(Q, B);
    TambahTugas(Q, C);
    TambahTugas(Q, D);

    // Jalankan semua tugas
    DailyTask(Q);

    return 0;
}
