//MFatihRafa
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

//rezairawan
void viewAntrian() {
    cout << "\nAntrian Peminjaman:\n";
    if (isEmpty()) {
        cout << "(Kosong)\n";
    } else {
        for (int i = 0; i < back; i++) {
            cout << i + 1 << ". Nama: " << queuePeminjaman[i].nama << ", Buku: " << queuePeminjaman[i].buku << endl;
        }
    }
}

void viewAntrianPerBuku() {
    cout << "\nAntrian Peminjaman per Buku:\n";
    map<string, vector<string>> antrianPerBuku;

    // Mengelompokkan antrian berdasarkan buku
    for (int i = 0; i < back; i++) {
        antrianPerBuku[queuePeminjaman[i].buku].push_back(queuePeminjaman[i].nama);
    }

    // Menampilkan antrian per buku
    for (const string& buku : listBuku) {
        cout << buku << ":\n";
        if (antrianPerBuku[buku].empty()) {
            cout << "  Tidak ada\n";
        } else {
            for (int i = 0; i < antrianPerBuku[buku].size(); i++) {
                cout << "  " << i + 1 << ". " << antrianPerBuku[buku][i] << endl;
            }
        }
    }
}
//FajarBudiawan
int main() {
    string pilihanStr;
    int pilihan;
    do {
        cout << "\n=== Sistem Peminjaman Buku ===\n";
        cout << "1. Tampilkan Buku\n";
        cout << "2. Peminjaman Buku\n";
        cout << "3. Pengembalian Buku\n";
        cout << "4. Tampilkan Antrian per Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihanStr;

        try {
            pilihan = stoi(pilihanStr);
        } catch (...) {
            pilihan = -1; // Set to invalid value if conversion fails
        }

        if (pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4 && pilihan != 5) {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                tampilkanBuku();
                break;
            case 2: {
                cin.ignore();
                string nama, buku;
                do {
                    cout << "Masukkan nama Anda: ";
                    getline(cin, nama);
                    cout << "Masukkan nama buku yang ingin dipinjam: ";
                    getline(cin, buku);

                    bool bukuTersedia = false;
                    for (string b : listBuku) {
                        if (b == buku) {
                            bukuTersedia = true;
                            break;
                        }
                    }

                    if (bukuTersedia) {
                        enqueuePeminjaman(nama, buku);
                        viewAntrian();
                        break;
                    } else {
                        cout << "Buku tidak tersedia dalam daftar.\n";
                        cout << "Ingin melanjutkan peminjaman lain? (y/n): ";
                        char lanjut;
                        cin >> lanjut;
                        cin.ignore();
                        if (lanjut == 'n' || lanjut == 'N') {
                            break;
                        }
                    }
                } while (true);
                break;
            }
            case 3:
                dequeuePeminjaman();
                break;
            case 4:
                viewAntrianPerBuku();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}