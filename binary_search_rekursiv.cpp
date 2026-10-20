#include <iostream>
using namespace std;

// array yang dicari (HARUS sudah terurut naik)
int binarySearch(int data[], int low, int high, int target) {
    if (low > high) { // Base case: batas kiri melewati batas kanan, artinya area pencarian sudah habis dan target tidak ada
        return -1;
    }
    
    int mid = low + (high - low) / 2;

    if (data[mid] == target) { // target tepat di tengah, ketemu
        return mid; 
    } else if (target < data[mid]) { 
        return binarySearch (data, low, mid-1, target); // target lebih kecil dari nilai tengah, cari lagi di setengah kiri (low sampai mid-1)
    } else { 
        return binarySearch (data, mid+1, high, target); // target lebih besar dari nilai tengah, cari lagi di setengah kanan (mid+1 sampai high)
    }
}

int main() {
    int data[] = {4, 8, 12, 16, 20, 24, 28}; 
    int n = 7;
    int target = 20;

    int hasil = binarySearch(data, 0, n-1, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}