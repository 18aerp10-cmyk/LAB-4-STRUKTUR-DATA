#include<iostream>
#include<vector>
using namespace std;

const int TABLE_SIZE = 10; // ukuran tabel hash tetap 10 slot (indeks 0-9)

class HashTable {
    private:
        vector<int> table;

        // fungsi hash: menentukan indeks awal dari sisa bagi key
        int hashFunction(int key) {
            return key % TABLE_SIZE; // contoh: 23 % 10 = 3
        }

    public:
        // constructor: otomatis jalan saat objek dibuat
        HashTable() {
            table.resize(TABLE_SIZE, -1);
        } 

        // fungsi untuk memasukkan data ke tabel
        void insert(int key) {
            int index = hashFunction(key);

            // linear probing: selama slot terisi (bukan -1), cek slot berikutnya
            while (table[index] != -1) {
                index = (index + 1) % TABLE_SIZE;
            }

            table[index] = key;
        }

        // fungsi untuk menampilkan isi tabel
        void display() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << i << ": " << table[i] << endl; // cetak indeks dan isinya (-1 = kosong)
            }
        }
};

int main() {
    HashTable ht;

    ht.insert(23); // masuk di indeks 3
    ht.insert(43); // collision di 3, geser ke indeks 4
    ht.insert(13); // collision di 3 dan 4, masuk di indeks 5
    ht.insert(35); // collision di 5, geser ke indeks 6

    ht.display();

    return 0;
}