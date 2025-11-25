#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa stack;
    
    createStack(stack);
    cout << "Stack berhasil dibuat" << endl;
    
    cout << "\n=== INPUT DATA MAHASISWA ===" << endl;
    
    // Data 1
    stack.Top = 0;
    stack.data[0] = {"Venti", "11111", 75.7, 82.1, 65.5};
    cout << "Data 1: Venti" << endl;
    
    // Data 2
    stack.Top = 1;
    stack.data[1] = {"Xiao", "22222", 87.4, 88.9, 81.9};
    cout << "Data 2: Xiao" << endl;
    
    // Data 3
    stack.Top = 2;
    stack.data[2] = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    cout << "Data 3: Kazuha" << endl;
    
    // Data 4
    stack.Top = 3;
    stack.data[3] = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    cout << "Data 4: Wanderer" << endl;
    
    // Data 5
    stack.Top = 4;
    stack.data[4] = {"Lynette", "55555", 77.7, 65.4, 79.9};
    cout << "Data 5: Lynette" << endl;
    
    // Data 6
    stack.Top = 5;
    stack.data[5] = {"Chasca", "66666", 99.9, 93.6, 87.3};
    cout << "Data 6: Chasca" << endl;
    
    // 3) Tampilkan stack
    View(stack);
    
    // 4) Pop 1x
    cout << "\n=== POP 1x ===" << endl;
    Pop(stack);
    
    // 5) Tampilkan setelah pop
    View(stack);
    
    // 6) Update data posisi 3
    cout << "\n=== UPDATE POSISI 3 ===" << endl;
    Update(stack, 3);
    
    // 7) Tampilkan setelah update
    View(stack);
    
    // 8) Searching nilai akhir 85.5 - 95.5
    SearchNilaiAkhir(stack, 85.5, 95.5);
    
    // Bagian B: MaxNilaiAkhir
    MaxNilaiAkhir(stack);
    
    return 0;
}