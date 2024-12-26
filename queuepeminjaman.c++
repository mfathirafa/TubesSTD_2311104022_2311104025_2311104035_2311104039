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
//eduardobagus
void enqueuePeminjaman(string nama, string buku) {
    if (isFull()) {
        cout << "Antrian penuh, silakan tunggu beberapa saat.\n";
    } else {
        queuePeminjaman[back].nama = nama;
        queuePeminjaman[back].buku = buku;
        back++;
        cout << "Berhasil ditambahkan ke antrian peminjaman.\n";
    }
}

void dequeuePeminjaman() {
    if (isEmpty()) {
        cout << "Antrian kosong, tidak ada peminjaman yang sedang diproses.\n";
    } else {
        cin.ignore();
        string nama, buku;
        cout << "\nMasukkan nama Anda: ";
        getline(cin, nama);
        cout << "Masukkan buku yang ingin dikembalikan: ";
        getline(cin, buku);

        bool ditemukan = false;
        for (int i = 0; i < back; i++) {
            if (queuePeminjaman[i].nama == nama && queuePeminjaman[i].buku == buku) {
                cout << "\nPengembalian Buku:\n";
                cout << "Nama: " << queuePeminjaman[i].nama << ", Buku: " << queuePeminjaman[i].buku << " telah dikembalikan.\n";
                for (int j = i; j < back - 1; j++) {
                    queuePeminjaman[j] = queuePeminjaman[j + 1];
                }
                back--;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Data tidak ditemukan dalam antrian.\n";
        }
    }
}