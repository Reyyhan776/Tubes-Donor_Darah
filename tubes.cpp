#include "tubes.h"
#include <iostream>
#include <string>

using namespace std;

void createListProgram(ListProgram &L){
    L.first = nullptr;
    L.last = nullptr;
};

bool isEmptyProgram(ListProgram L){
    return L.first == nullptr;
};

bool isEmptyPendonor(adrProgram P){
    return (P == nullptr || P->firstPendonor == nullptr);
};

adrProgram createElmProgram(string IDprogram, string tanggal, string lokasi, string jenis){
    adrProgram P = new elmProgram;

    P->info.IDprogram = IDprogram;
    P->info.tanggal = tanggal;
    P->info.lokasi = lokasi;
    P->info.jenisDonor = jenis;

    P->next = nullptr;
    P->prev = nullptr;

    P->firstPendonor = nullptr;
    P->lastPendonor = nullptr;

    return P;
};

adrPendonor createElmPendonor(string nama, string gol, bool status){
    adrPendonor D = new elmPendonor;

    D->info.nama = nama;
    D->info.golDarah = gol;
    D->info.statusHadir = status;

    D->next = nullptr;
    D->prev = nullptr;

    return D;
};

void addProgramFirst(ListProgram &L, adrProgram P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        // Insert di depan (DLL)
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void addPendonorLast(adrProgram &P, adrPendonor D) {
    if (P == nullptr) {
        return;
    }

    if (P->firstPendonor == nullptr) {
        P->firstPendonor = D;
        P->lastPendonor = D;
    } else {
        // Insert di belakang (DLL)
        P->lastPendonor->next = D;
        D->prev = P->lastPendonor;
        P->lastPendonor = D;
    }
}

adrProgram searchProgram(ListProgram L, string IDprogram) {
    adrProgram P = L.first;
    adrProgram hasil = nullptr;

    while (P != nullptr && hasil == nullptr) {
        if (P->info.IDprogram == IDprogram) {
            hasil = P;
        } else {
            P = P->next;
        }
    }
    return hasil;
}

adrPendonor searchPendonor(adrProgram P, string nama) {
    adrPendonor D = nullptr;
    adrPendonor Q = nullptr;

    if (P != nullptr) {
        Q = P->firstPendonor;

        while (Q != nullptr && D == nullptr) {
            if (Q->info.nama == nama) {
                D = Q;
            } else {
                Q = Q->next;
            }
        }
    }
    return D;
}

void showPendonor(adrProgram P) {
    adrPendonor D;
    int i = 1;

    if (P != nullptr) {
        D = P->firstPendonor;

        if (D == nullptr) {
            cout << "Program donor " << P->info.IDprogram
                 << " belum memiliki pendonor." << endl;
        } else {
            cout << "Daftar Pendonor Program " << P->info.IDprogram << endl;
            cout << "----------------------------------" << endl;

            while (D != nullptr) {
                cout << i << ". ";
                cout << "Nama        : " << D->info.nama << endl;
                cout << "   GolDarah : " << D->info.golDarah << endl;
                cout << "   Status   : ";
                if (D->info.statusHadir == true) {
                    cout << "Hadir" << endl;
                } else {
                    cout << "Tidak Hadir" << endl;
                }
                cout << endl;

                i++;
                D = D->next;
            }
        }
    } else {
        cout << "Program donor tidak ditemukan." << endl;
    }
}




