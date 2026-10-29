#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string data[100];
    int n;
 
    cout << "Masukkan jumlah kata : ";
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cout << "Kata ke-" << i + 1 << " : ";
        cin >> data[i];
    }
 
    cout << "\nData awal : ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << "\n\n";
 
    for (int i = 1; i < n; i++) {
        string key = data[i];
        int j = i - 1;
 
        cout << "Langkah " << i << " (key = " << key << ")" << endl;
 
        while (j >= 0 && data[j] > key) {
            cout << "  geser " << data[j] << " dari index " << j << " ke index " << j + 1 << endl;
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
 
        cout << "  taruh " << key << " di index " << j + 1 << endl;
        cout << "  hasil: ";
        for (int k = 0; k < n; k++) {
            cout << data[k] << " ";
        }
        cout << "\n\n";
    }
 
    cout << "Hasil insertion sort : ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
 
    return 0;
}