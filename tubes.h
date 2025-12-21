#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

typedef struct elmProgram *adrProgram;
typedef struct elmPendonor *adrPendonor;

struct Program {
    string IDprogram;
    string tanggal;
    string lokasi;
    string jenisDonor; // Darah Penuh / Plasma / Trombosit
};

struct Pendonor {
    string nama;
    string golDarah;
    bool statusHadir;
};

struct elmProgram {
    Program info;
    adrProgram next;
    adrProgram prev;
    adrPendonor firstPendonor;  // head child
    adrPendonor lastPendonor;   // tail child
};

struct elmPendonor {
    Pendonor info;
    adrPendonor next;
    adrPendonor prev;
};

struct ListProgram {
    adrProgram first;
    adrProgram last;
};

void createListProgram(ListProgram &L);
bool isEmptyProgram(ListProgram L);
bool isEmptyPendonor(adrProgram P);
adrProgram createElmProgram(string IDprogram, string tanggal, string lokasi, string jenis);
adrPendonor createElmPendonor(string nama, string gol, bool status);
void addProgramFirst(ListProgram &L, adrProgram P);
void addPendonorLast(adrProgram &P, adrPendonor D);
adrProgram searchProgram(ListProgram L, string IDProgram);
adrPendonor searchPendonor(adrProgram P, string nama);
void showPendonor(adrProgram P);

#endif // TUBES_H_INCLUDED
