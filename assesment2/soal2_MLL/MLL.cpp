#include "MLL.h"
#include <iostream>

void createListParent(ParentNode* &first, ParentNode* &last) {
    first = NULL;
    last = NULL;
}

ParentNode* alokasiParent(string id, string nama) {
    ParentNode* baru = new ParentNode;
    baru->IDGenre = id;
    baru->nameGenre = nama;
    baru->next = NULL;
    baru->prev = NULL;
    baru->firstChild = NULL;
    baru->lastChild = NULL;
    return baru;
}

ChildNode* alokasiChild(string id, string judul, int durasi, int tahun, float rating) {
    ChildNode* baru = new ChildNode;
    baru->IDFilm = id;
    baru->judulFilm = judul;
    baru->durasiFilm = durasi;
    baru->tahunTayang = tahun;
    baru->ratingFilm = rating;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

void insertFirstParent(ParentNode* &first, ParentNode* &last, ParentNode* baru) {
    if(first == NULL) {
        first = baru;
        last = baru;
    } else {
        baru->next = first;
        first->prev = baru;
        first = baru;
    }
}

void insertLastChild(ParentNode* parent, ChildNode* child) {
    if(parent->firstChild == NULL) {
        parent->firstChild = child;
        parent->lastChild = child;
    } else {
        parent->lastChild->next = child;
        child->prev = parent->lastChild;
        parent->lastChild = child;
    }
}

void printAll(ParentNode* first) {
    ParentNode* tempParent = first;
    int noParent = 1;
    
    while(tempParent != NULL) {
        cout << "=== Parent " << noParent << " ===" << endl;
        cout << "ID Genre : " << tempParent->IDGenre << endl;
        cout << "Name Genre : " << tempParent->nameGenre << endl;
        
        ChildNode* tempChild = tempParent->firstChild;
        int noChild = 1;
        
        while(tempChild != NULL) {
            cout << "  - Child " << noChild << endl;
            cout << "    ID Film : " << tempChild->IDFilm << endl;
            cout << "    Judul Film : " << tempChild->judulFilm << endl;
            cout << "    Durasi Film : " << tempChild->durasiFilm << " menit" << endl;
            cout << "    Tahun Tayang : " << tempChild->tahunTayang << endl;
            cout << "    Rating Film : " << tempChild->ratingFilm << endl;
            cout << endl;
            
            tempChild = tempChild->next;
            noChild++;
        }
        
        cout << "---" << endl;
        tempParent = tempParent->next;
        noParent++;
    }
}

void cariRating(ParentNode* first, float minRate, float maxRate) {
    ParentNode* tempParent = first;
    int posParent = 1;
    
    while(tempParent != NULL) {
        ChildNode* tempChild = tempParent->firstChild;
        int posChild = 1;
        
        while(tempChild != NULL) {
            if(tempChild->ratingFilm >= minRate && tempChild->ratingFilm <= maxRate) {
                cout << "Data Film ditemukan pada list child dari node parent "
                     << tempParent->nameGenre << " pada posisi ke-" << posChild << endl;
                cout << "--- Data Film (child) ---" << endl;
                cout << "Judul Film : " << tempChild->judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << posChild << endl;
                cout << "ID Film : " << tempChild->IDFilm << endl;
                cout << "Durasi Film : " << tempChild->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << tempChild->tahunTayang << endl;
                cout << "Rating Film : " << tempChild->ratingFilm << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << tempParent->IDGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posParent << endl;
                cout << "Nama Genre : " << tempParent->nameGenre << endl;
                cout << "===============" << endl << endl;
            }
            tempChild = tempChild->next;
            posChild++;
        }
        
        tempParent = tempParent->next;
        posParent++;
    }
}

void hapusChildParent(ParentNode* parent) {
    ChildNode* temp = parent->firstChild;
    
    while(temp != NULL) {
        ChildNode* hapus = temp;
        temp = temp->next;
        delete hapus;
    }
    
    parent->firstChild = NULL;
    parent->lastChild = NULL;
}

void hapusParentSetelah(ParentNode* &first, ParentNode* &last, string idPrev) {
    ParentNode* temp = first;
    
    while(temp != NULL && temp->IDGenre != idPrev) {
        temp = temp->next;
    }
    
    if(temp == NULL || temp->next == NULL) {
        cout << "Tidak ada parent setelah " << idPrev << endl;
        return;
    }
    
    ParentNode* hapus = temp->next;
    
    hapusChildParent(hapus);
    
    if(hapus->next == NULL) {
        temp->next = NULL;
        last = temp;
    } else {
        temp->next = hapus->next;
        hapus->next->prev = temp;
    }
    
    delete hapus;
}