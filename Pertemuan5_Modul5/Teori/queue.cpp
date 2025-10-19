#include <iostream>
#include <string>
using namespace std;

const int MAX = 12;

struct Queue {
    string data[MAX];
    int front;
    int rear;
};

// Membuat queue kosong
void createQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}

// Mengecek apakah queue kosong
bool isEmpty(Queue Q) {
    return (Q.front == -1);
}

// Mengecek apakah queue penuh
bool isFull(Queue Q) {
    return (Q.rear == MAX - 1);
}

// Menambahkan data ke antrian
void enqueue(Queue &Q, string item) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
    } else {
        if (isEmpty(Q)) {
            Q.front = 0;
        }
        Q.rear++;
        Q.data[Q.rear] = item;
        cout << "Data \"" << item << "\" berhasil ditambahkan ke antrian.\n";
    }
}

// Mengeluarkan data dari antrian
void dequeue(Queue &Q, string &item) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
    } else {
        item = Q.data[Q.front];
        cout << "Data \"" << item << "\" keluar dari antrian.\n";
        if (Q.front == Q.rear) {
            // Reset queue jika sudah kosong
            Q.front = -1;
            Q.rear = -1;
        } else {
            Q.front++;
        }
    }
}

// Menampilkan isi antrian
void displayQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
    } else {
        cout << "Isi antrian:\n";
        for (int i = Q.front; i <= Q.rear; i++) {
            cout << i - Q.front + 1 << ". " << Q.data[i] << endl;
        }
    }
}

// Program utama
int main() {
    Queue Q;
    createQueue(Q);

    string nama, keluar;
    int pilihan;

    do {
        cout << "\n=== MENU QUEUE ===\n";
        cout << "1. Tambah Antrian (Enqueue)\n";
        cout << "2. Keluarkan Antrian (Dequeue)\n";
        cout << "3. Lihat Isi Queue\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                enqueue(Q, nama);
                break;
            case 2:
                dequeue(Q, keluar);
                break;
            case 3:
                displayQueue(Q);
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
