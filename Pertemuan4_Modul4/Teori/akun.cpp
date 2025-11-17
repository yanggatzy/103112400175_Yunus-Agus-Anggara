#include <iostream>
#include <string>
using namespace std;

struct Akun {
    string username;
    string password;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    Akun info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// === PROSEDUR DASAR ===
void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address createNewElm(Akun akun) {
    address p = new ElmList;
    if (p != NULL) {
        p->info = akun;
        p->next = NULL;
        p->prev = NULL;
    }
    return p;
}

void insertLast(List &L, address p) {
    if (L.first == NULL) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

address findAkun(string username, List L) {
    address p = L.first;
    while (p != NULL) {
        if (p->info.username == username) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// === SIGN UP ===
void signUp(Akun akun, List &L) {
    if (findAkun(akun.username, L) != NULL) {
        cout << "Account has been registered.\n";
    } else {
        address p = createNewElm(akun);
        insertLast(L, p);
        cout << "Account successfully registered.\n";
    }
}

// === DELETE FUNCTIONS ===
void deleteFirst(List &L, address &p) {
    p = L.first;
    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.first = p->next;
        L.first->prev = NULL;
        p->next = NULL;
    }
}

void deleteAfter(address q, address &p) {
    p = q->next;
    q->next = p->next;
    if (p->next != NULL) {
        p->next->prev = q;
    }
    p->next = NULL;
    p->prev = NULL;
}

void deleteLast(List &L, address &p) {
    p = L.last;
    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.last = p->prev;
        L.last->next = NULL;
        p->prev = NULL;
    }
}

void removeAkun(string username, List &L) {
    address p = findAkun(username, L);
    if (p == NULL) {
        cout << "Account not found.\n";
        return;
    }

    if (p == L.first) {
        deleteFirst(L, p);
    } else if (p == L.last) {
        deleteLast(L, p);
    } else {
        address q = p->prev;
        deleteAfter(q, p);
    }

    delete p;
    cout << "Account removed successfully.\n";
}

// === PRINT ALL ===
void printAll(List L) {
    address p = L.first;
    cout << "\n=== Daftar Akun Terdaftar ===\n";
    while (p != NULL) {
        cout << "Username : " << p->info.username << endl;
        cout << "Password : " << p->info.password << endl << endl;
        p = p->next;
    }
}

// === MAIN PROGRAM ===
int main() {
    List L;
    createList(L);

    int n;
    cout << "Masukkan jumlah akun yang ingin diregistrasi: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Akun akunBaru;
        cout << "\nMasukkan username: ";
        cin >> akunBaru.username;
        cout << "Masukkan password: ";
        cin >> akunBaru.password;
        signUp(akunBaru, L);
    }

    printAll(L);

    string hapus;
    cout << "\nMasukkan username yang ingin dihapus: ";
    cin >> hapus;
    removeAkun(hapus, L);

    printAll(L);

    return 0;
}
