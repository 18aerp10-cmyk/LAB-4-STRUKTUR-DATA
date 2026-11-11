#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int TABLE_SIZE = 10; 

class HashTable {
    private :
    vector<pair<int, string>> table; // pasangan NIM (key) dan nama (value)
    vector<int> status;              // 0 = kosong, 1 = terisi, 2 = dihapus

    // hash pertama ini untuk menentukan indeks awal
    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    // hash kedua ini untuk menentukan langkah (step) saat terjadi collision
    int hash2(int key) {
        return 7 - (key % 7);
    }

    public :
    HashTable() {
        table.resize(TABLE_SIZE);
        status.resize(TABLE_SIZE, 0);
    }

    // memasukkan data mahasiswa
    void insert(int nim, string nama) {
        int index = hash1(nim);
        int step = hash2(nim);
        int initialIndex = index;

        int deletedIndex = -1; 

        while (true) {
            if (status[index] == 1 && table[index].first == nim) {
                table[index].second = nama;
                return;
            }

            // catat slot bekas hapus pertama untuk dipakai ulang
            if (status[index] == 2 && deletedIndex == -1) {
                deletedIndex = index;
            }

            if (status[index] == 0) {
                if (deletedIndex != -1) {
                    index = deletedIndex;
                }

                table[index] = make_pair(nim, nama);
                status[index] = 1;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        if (deletedIndex != -1) {
            table[deletedIndex] = make_pair(nim, nama);
            status[deletedIndex] = 1;
        } else {
            cout << "Tabel penuh" << endl;
        }
    }

    // mencari data berdasarkan NIM
    void search(int nim) {
        int index = hash1(nim);
        int step = hash2(nim);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == nim) {
                cout << "Data ditemukan : " << table[index].first << " - " << table[index].second << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        cout << "Data tidak ditemukan" << endl;
    }

    // untuk menghapus data berdasarkan NIM nya
    void remove(int nim) {
        int index = hash1(nim);
        int step = hash2(nim);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == nim) {
                status[index] = 2; 
                cout << "Data berhasil dihapus" << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        cout << "Data tidak ditemukan" << endl;
    }

    // ini untuk menampilkan isi hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";

            if (status[i] == 1) {
                cout << table[i].first << " - " << table[i].second;
            } else if (status[i] == 2) {
                cout << "DELETED";
            } else {
                cout << "EMPTY";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(240710001, "Andi");
    ht.insert(240710011, "Budi");  
    ht.insert(240710021, "Citra"); 
    ht.insert(240710005, "Dewi");  
    ht.insert(240710015, "Eka");   

    cout << "Mencari NIM 240710011 : " << endl;
    ht.search(240710011);

    cout << "Mencari NIM 240710099 : " << endl;
    ht.search(240710099);

    cout << "Menghapus NIM 240710011 : " << endl;
    ht.remove(240710011);

    cout << "Isi hash table setelah seluruh operasi : " << endl;
    ht.display();

    return 0;
}
