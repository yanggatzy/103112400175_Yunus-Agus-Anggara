#ifndef MLL_H
#define MLL_H

#include <string>
using namespace std;

struct ChildNode {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    ChildNode* next;
    ChildNode* prev;
};

struct ParentNode {
    string IDGenre;
    string nameGenre;
    ParentNode* next;
    ParentNode* prev;
    ChildNode* firstChild;
    ChildNode* lastChild;
};

void createListParent(ParentNode* &first, ParentNode* &last);
ParentNode* alokasiParent(string id, string nama);
ChildNode* alokasiChild(string id, string judul, int durasi, int tahun, float rating);
void insertFirstParent(ParentNode* &first, ParentNode* &last, ParentNode* baru);
void insertLastChild(ParentNode* parent, ChildNode* child);
void printAll(ParentNode* first);
void cariRating(ParentNode* first, float minRate, float maxRate);
void hapusParentSetelah(ParentNode* &first, ParentNode* &last, string idPrev);
void hapusChildParent(ParentNode* parent);

#endif