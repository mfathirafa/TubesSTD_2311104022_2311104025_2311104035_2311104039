#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/* Deklarasi */
const int maksimalQueue = 5;
int front = 0;
int back = 0;

struct Peminjaman {
    string nama;
    string buku;
};

Peminjaman queuePeminjaman[maksimalQueue];
vector<string> listBuku = {"C++ Dasar", "Struktur Data", "Pemrograman Lanjut", "Algoritma", "Database"};

bool isFull() {
    return back == maksimalQueue;
}

bool isEmpty() {
    return back == 0;
}

void tampilkanBuku() {
    cout << "\nList Buku:\n";
    for (int i = 0; i < listBuku.size(); i++) {
        cout << i + 1 << ". " << listBuku[i] << endl;
    }
}