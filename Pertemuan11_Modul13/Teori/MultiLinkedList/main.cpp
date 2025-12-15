#include "mll.h"

int main() {
    mll List_Sales;
    Create_list(List_Sales);

    // Tambah sales
    sales s1 = {"Siska", "A"};
    sales s2 = {"Affan", "C"};
    sales s3 = {"Cahya", "A"};
    sales s4 = {"Lia", "C"};
    sales s5 = {"Hafidz", "B"};

    insert_last_Sales(List_Sales, new_elm_sales(s1));
    insert_last_Sales(List_Sales, new_elm_sales(s2));
    insert_last_Sales(List_Sales, new_elm_sales(s3));
    insert_last_Sales(List_Sales, new_elm_sales(s4));
    insert_last_Sales(List_Sales, new_elm_sales(s5));

    // Tambah penjualan
    adr_sales P;

    P = Search_Sales(List_Sales, "Siska");
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(5));
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(3)); 
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(4));
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(2)); // akan dihapus

    P = Search_Sales(List_Sales, "Affan");
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(4)); 
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(3)); 

    P = Search_Sales(List_Sales, "Cahya");
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(5));
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(0)); // akan dihapus
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(2)); // akan dihapus

    P = Search_Sales(List_Sales, "Hafidz");
    Insert_new_Penjualan(List_Sales, P, new_elm_jual(7)); 

    cout << "=== DATA SEBELUM DELETE (<3) ===\n";
    Show_data_sales(List_Sales);

    Delete_Penjualan(List_Sales);

    cout << "=== DATA SETELAH DELETE (<3) ===\n";
    Show_data_sales(List_Sales);

    return 0;
}
