#include "mll.h"

void Create_list(mll &List_Sales) {
    List_Sales.First = NULL;
}

adr_sales new_elm_sales(sales data) {
    adr_sales S = new elm_sales;
    S->info = data;
    S->next = NULL;
    S->nextJual = NULL;
    return S;
}

adr_jual new_elm_jual(int penjualan) {
    adr_jual J = new elm_jual;
    J->info = penjualan;
    J->next = NULL;
    return J;
}

void insert_last_Sales(mll &List_Sales, adr_sales S) {
    if (List_Sales.First == NULL) {
        List_Sales.First = S;
    } else {
        adr_sales P = List_Sales.First;
        while (P->next != NULL) {
            P = P->next;
        }
        P->next = S;
    }
}

adr_sales Search_Sales(mll List_Sales, string nama_sales) {
    adr_sales P = List_Sales.First;
    while (P != NULL) {
        if (P->info.nama == nama_sales) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void Insert_new_Penjualan(mll &List_Sales, adr_sales S, adr_jual J) {
    if (S->nextJual == NULL) {
        S->nextJual = J;
    } else {
        adr_jual P = S->nextJual;
        while (P->next != NULL) {
            P = P->next;
        }
        P->next = J;
    }
}

void Delete_First_Penjualan(mll &List_Sales, adr_sales S, adr_jual &J) {
    if (S->nextJual != NULL) {
        J = S->nextJual;
        S->nextJual = J->next;
        J->next = NULL;
    }
}

void Delete_Last_Penjualan(mll &List_Sales, adr_sales S, adr_jual &J) {
    adr_jual P = S->nextJual;

    if (P->next == NULL) {   // hanya 1 elemen
        S->nextJual = NULL;
        J = P;
        return;
    }

    adr_jual Q;
    while (P->next != NULL) {
        Q = P;
        P = P->next;
    }
    Q->next = NULL;
    J = P;
}

void Delete_after_Penjualan(mll &List_Sales, adr_sales S, adr_jual prec, adr_jual &J) {
    if (prec->next != NULL) {
        J = prec->next;
        prec->next = J->next;
        J->next = NULL;
    }
}

void Delete_Penjualan(mll &List_Sales) {
    adr_sales P = List_Sales.First;

    while (P != NULL) {
        adr_jual Q = P->nextJual;
        adr_jual Prec = NULL;
        adr_jual J;

        while (Q != NULL) {

            if (Q->info < 3) {

                if (Q == P->nextJual) {
                    Delete_First_Penjualan(List_Sales, P, J);
                    Q = P->nextJual;
                }
                else if (Q->next == NULL) {
                    Delete_Last_Penjualan(List_Sales, P, J);
                    Q = NULL;
                }
                else {
                    Delete_after_Penjualan(List_Sales, P, Prec, J);
                    Q = Prec->next;
                }

            } else {
                Prec = Q;
                Q = Q->next;
            }
        }

        P = P->next;
    }
}

void Show_data_sales(mll List_Sales) {
    adr_sales P = List_Sales.First;

    while (P != NULL) {
        cout << P->info.nama << endl;

        adr_jual Q = P->nextJual;
        while (Q != NULL) {
            cout << Q->info << " ";
            Q = Q->next;
        }

        cout << "\n\n";
        P = P->next;
    }
}
