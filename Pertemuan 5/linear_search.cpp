#include <iostream>
using namespace std;

//membuat fungsi
int linearSearch (int data[], int n, int target) {
    for (int i = 0; i < n; i++) { // Cek elemen satu per satu dari indeks 0 sampai n-1
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int data[] = {70, 14, 49, 56, 23, 0, 5, 7, 44, 30};
    int n = 10; // jumlah elemen array
    int target = 49; // angka yg dicari

    int hasil = linearSearch (data, n, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
