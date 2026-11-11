#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int TABLE_SIZE = 10; // ukuran tabel hash tetap 10 slot (indeks 0-9)

class HashTable {
private:
    vector<list<int>> table;  // array of linked list: tiap slot berisi sebuah linked list (chaining)

    // fungsi hash: menentukan indeks slot dari sisa bagi key
    int hashFunction(int key) {
        return key % TABLE_SIZE; // contoh: 23 % 10 = 3
    }

public:
    // constructor: otomatis jalan saat objek dibuat
    HashTable() {
        table.resize(TABLE_SIZE); // buat 10 slot, tiap slot berisi list kosong
    }

    // fungsi untuk memasukkan data ke tabel
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // fungsi untuk menampilkan isi tabel
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " ";

            for (int data : table[i]) {
                cout << data << " -> ";
            }

            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(23); // 23 % 10 = 3, masuk list di indeks 3
    ht.insert(43); // 43 % 10 = 3, collision, disambung setelah 23
    ht.insert(13); // 13 % 10 = 3, collision lagi, disambung setelah 43
    ht.insert(35); // 35 % 10 = 5, masuk list di indeks 5

    ht.display();

    return 0;
}
