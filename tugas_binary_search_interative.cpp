#include <iostream>
#include <vector>       
#include <algorithm>    
using namespace std;

int binarySearch(vector<int>& data, int target) {
    int low = 0;                    
    int high = data.size() - 1;    

    while (low <= high) {
        int mid = low + (high - low) / 2;   

        if (data[mid] == target) {
            return mid;             
        } else if (target < data[mid]) {
            high = mid - 1;         
        } else {
            low = mid + 1;          
        }
    }

    return -1;                      
}

int main() {
    int n;

    cout << "Masukkan jumlah data : "; // Meng-input kan jumlah data yang diinginkan
    cin >> n;

    vector<int> data(n);            

    for (int i = 0; i < n; i++) { 
        cout << "Masukkan nilai ke " << i + 1 << " : ";
        cin >> data[i];
    }

    if (!is_sorted(data.begin(), data.end())) { // Cek dulu, kalau blm terurut ya langsung meng-urutkan nilai otomatis secara ascending
        sort(data.begin(), data.end());

        // Untuk menampilkan data yang sudah terurut
        cout << "\nData setelah diurutkan : ";
        for (int a : data) {
            cout << a << " ";
        }
        cout << endl;
    }

    // Meng-input jumlah target yang ingin dicari
    int jumlahTarget;
    cout << "\nMau cari berapa nilai nihh ? ";
    cin >> jumlahTarget;

    // Untuk cari tiap target
    for (int j = 0; j < jumlahTarget; j++) {
        int target;
        cout << "\nMasukkan nilai yang dicari ke " << j + 1 << " : ";
        cin >> target;

        int hasil = binarySearch(data, target);

        if (hasil != -1) {
            cout << "Data " << target << " ditemukan pada indeks : " << hasil << endl;
        } else {
            cout << "Data " << target << " tidak ditemukan" << endl;
        }
    }

    return 0;
}