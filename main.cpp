#include <iostream>#include <iostream>
#include "tubes.h"

using namespace std;

int main() {
    ListProgram L;
    adrProgram P;
    string idProgram, tanggal, lokasi, jenis;
    string nama, gol;
    bool status;
    int pilihan;

    createListProgram(L);

    do {
        cout << endl;
        cout << "===== SISTEM MANAJEMEN DONOR DARAH =====" << endl;
        cout << "1. Tambah Program Donor" << endl;
        cout << "2. Tambah Pendonor ke Program" << endl;
        cout << "3. Tampilkan Pendonor Berdasarkan Program" << endl;
        cout << "4. Tampilkan Semua Program dan Pendonornya" << endl;
        cout << "5. Hapus Pendonor dari Program" << endl;
        cout << "6. Hapus Program Donor" << endl;
        cout << "7. Program dengan Pendonor Terbanyak" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "ID Program   : ";
            cin >> idProgram;
            cout << "Tanggal      : ";
            cin >> tanggal;
            cout << "Lokasi       : ";
            cin >> lokasi;
            cout << "Jenis Donor  : ";
            cin >> jenis;

            P = createElmProgram(idProgram, tanggal, lokasi, jenis);
            addProgramFirst(L, P);

            cout << "Program donor berhasil ditambahkan." << endl;
        }

        else if (pilihan == 2) {
            cout << "Masukkan ID Program: ";
            cin >> idProgram;

            P = searchProgram(L, idProgram);

            if (P != nullptr) {
                cout << "Nama Pendonor : ";
                cin >> nama;
                cout << "Gol Darah     : ";
                cin >> gol;
                cout << "Status Hadir (1=Hadir, 0=Tidak): ";
                cin >> status;

                adrPendonor D = createElmPendonor(nama, gol, status);
                addPendonorLast(P, D);

                cout << "Pendonor berhasil ditambahkan." << endl;
            } else {
                cout << "Program donor tidak ditemukan." << endl;
            }
        }

        else if (pilihan == 3) {
            cout << "Masukkan ID Program: ";
            cin >> idProgram;

            P = searchProgram(L, idProgram);
            showPendonor(P);
        }

        else if (pilihan == 4) {
            showAllPrograms(L);
        }

        else if (pilihan == 5) {
            cout << "Masukkan ID Program: ";
            cin >> idProgram;
            P = searchProgram(L, idProgram);

            if (P != nullptr) {
                cout << "Nama Pendonor yang dihapus: ";
                cin >> nama;
                deletePendonor(P, nama);
                cout << "Pendonor berhasil dihapus." << endl;
            } else {
                cout << "Program donor tidak ditemukan." << endl;
            }
        }

        else if (pilihan == 6) {
            cout << "Masukkan ID Program yang dihapus: ";
            cin >> idProgram;
            deleteProgram(L, idProgram);
            cout << "Program donor berhasil dihapus." << endl;
        }

        else if (pilihan == 7) {
            programTerbanyak(L);
        }

    } while (pilihan != 0);

    cout << "Program selesai. Terima kasih." << endl;

    return 0;
}


