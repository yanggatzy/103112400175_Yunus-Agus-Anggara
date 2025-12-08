#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

// =========================
//      STRUCT & TYPEDEF
// =========================

struct elm_jual;
struct elm_sales;

typedef elm_jual* adr_jual;
typedef elm_sales* adr_sales;

struct elm_jual {
    int info;
    adr_jual next;
};

struct sales {
    string nama;
    string gol;
};

struct elm_sales {
    sales info;
    adr_sales next;
    adr_jual nextJual;
};

struct mll {
    adr_sales First;
};


// =========================
//      FUNGSI / PROSEDUR
// =========================

void Create_list(mll &List_Sales);

adr_sales new_elm_sales(sales data);
adr_jual new_elm_jual(int penjualan);

void insert_last_Sales(mll &List_Sales, adr_sales S);

adr_sales Search_Sales(mll List_Sales, string nama_sales);

void Insert_new_Penjualan(mll &List_Sales, adr_sales S, adr_jual J);

void Delete_First_Penjualan(mll &List_Sales, adr_sales S, adr_jual &J);
void Delete_Last_Penjualan(mll &List_Sales, adr_sales S, adr_jual &J);
void Delete_after_Penjualan(mll &List_Sales, adr_sales S, adr_jual prec, adr_jual &J);

void Delete_Penjualan(mll &List_Sales);

void Show_data_sales(mll List_Sales);

#endif
