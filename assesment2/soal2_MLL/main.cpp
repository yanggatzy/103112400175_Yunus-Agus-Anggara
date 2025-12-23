#include <iostream>
#include "MLL.h"
using namespace std;

int main() {
    ParentNode* firstParent = NULL;
    ParentNode* lastParent = NULL;
    
    createListParent(firstParent, lastParent);
    
    ParentNode* parent1 = alokasiParent("G001", "Action");
    ParentNode* parent2 = alokasiParent("G002", "Comedy");
    ParentNode* parent3 = alokasiParent("G003", "Horror");
    ParentNode* parent4 = alokasiParent("G004", "Romance");
    
    insertFirstParent(firstParent, lastParent, parent4);
    insertFirstParent(firstParent, lastParent, parent3);
    insertFirstParent(firstParent, lastParent, parent2);
    insertFirstParent(firstParent, lastParent, parent1);
    
    ChildNode* child1 = alokasiChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(parent1, child1);
    
    ChildNode* child2 = alokasiChild("FC001", "Agak Laen", 119, 2024, 8.0);
    ChildNode* child3 = alokasiChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    insertLastChild(parent2, child2);
    insertLastChild(parent2, child3);
    
    ChildNode* child4 = alokasiChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(parent3, child4);
    
    ChildNode* child5 = alokasiChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    ChildNode* child6 = alokasiChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(parent4, child5);
    insertLastChild(parent4, child6);
    
    cout << "=== Print Struktur MLL ===" << endl;
    printAll(firstParent);
    
    cout << "\n=== Cari Rating 8.0 - 8.5 ===" << endl;
    cariRating(firstParent, 8.0, 8.5);
    
    cout << "\n=== Hapus Parent Setelah G001 ===" << endl;
    hapusParentSetelah(firstParent, lastParent, "G001");
    
    cout << "\n=== Print Setelah Hapus ===" << endl;
    printAll(firstParent);
    
    return 0;
}