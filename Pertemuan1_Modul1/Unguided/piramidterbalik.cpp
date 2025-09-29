#include <iostream>
using namespace std;

int main() {
    int input;
    
    cout << "Input: ";
    cin >> input;
    
    cout << "output: " << endl;
    
    // Bagian piramid terbalik
    for (int i = input; i >= 1; i--) {
        // Spasi sebelum angka menurun
        for (int j = 0; j < input - i; j++) {
            cout << "  ";
        }
        
        // Angka menurun
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        
        // Bintang
        cout << "* ";
        
        // Angka menaik
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        
        cout << endl;
    }
    
    // Baris terakhir hanya bintang dengan spasi
    for (int j = 0; j < input; j++) {
        cout << "  ";
    }
    cout << "*" << endl;
    
    return 0;
}