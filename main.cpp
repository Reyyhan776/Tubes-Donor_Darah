#include <iostream>
#include "tubes.h"
using namespace std;

int main() {
    ListProgram L;
    adrProgram P;
    adrPendonor D;

    // ===============================
    // Inisialisasi List
    // ===============================
    createListProgram(L);

    cout << "=== SISTEM MANAJEMEN DONOR DARAH ===" << endl;

    // ===============================
    // Tambah Program Donor
    // ===============================
    P = createElmProgram("PD001", "2025-06-10", "Bandung", "Darah Penuh");
    addProgramFirst(L, P);

    cout << "Program donor PD001 berhasil ditambahkan." << endl;

    // ===============================
    // Cari Program Donor
    // ===============================
    adrProgram cariProgram = searchProgram(L, "PD001");

    if (cariProgram != nullptr) {
        cout << "Program donor ditemukan: "
             << cariProgram->info.IDprogram << endl;
    } else {
        cout << "Program donor tidak ditemukan." << endl;
    }

    // ===============================
    // Tambah Pendonor ke Program
    // ===============================
    if (cariProgram != nullptr) {
        D = createElmPendonor("Andi", "O", true);
        addPendonorLast(cariProgram, D);

        D = createElmPendonor("Budi", "A", false);
        addPendonorLast(cariProgram, D);

        cout << "Pendonor berhasil ditambahkan ke program PD001." << endl;
    }

    // ===============================
    // Tampilkan Pendonor berdasarkan Program
    // ===============================
    cout << endl;
    showPendonor(cariProgram);

    cout << endl << "=== PROGRAM SELESAI ===" << endl;

    return 0;
}

