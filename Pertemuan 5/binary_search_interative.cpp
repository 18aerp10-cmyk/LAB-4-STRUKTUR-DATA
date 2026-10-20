#include <iostream>
using namespace std;

// tidak memanggil diri ny sndiri, array yang dicari (HARUS sudah terurut naik)
int binarySearch(int data[], int n, int target) {
    int low = 0; // indeks awal
    int high = n-1; // indeks

    while (low <= high) { // Kalau low sudah melewati high, berarti area habis dan target tidak ada
        int mid = low + (high - low) / 2; // menghitung indeks middle = 3

        if (data[mid] == target) {
            return mid;
        } else if (target < data[mid]) { // Target lebih kecil dari nilai tengah, buang setengah kanan, geser batas kanan ke mid - 1
            high = mid - 1; // 3 - 1 = 2 -> high
        } else { // Target lebih besar dari nilai tengah, buang setengah kiri, geser batas kiri ke mid + 1
            low = mid + 1; // 3 + 1 = 4 -> low
        }
    }

    return -1;
}

int main() {
    int data[] = {4, 8, 12, 16, 20, 24, 28};
    int n = 7;
    int target = 20;

    int hasil = binarySearch(data, n, target); // hasil = 4

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
