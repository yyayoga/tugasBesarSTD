#ifndef GLOBALH_H_INCLUDED
#define GLOBALH_H_INCLUDED
#include "bidangKeilmuanH.h"
#include "mataKuliahH.h"
#include "relasiH.h"
#include "menuH.h"
#include <unordered_set>

using namespace std;

struct mataKuliah {
    string kode;
    string nama;
    int jumlahSks;
    string dosenPengajar;
};

struct bidangKeilmuan {
    string kodeBidang;
    string nama;
    int jumlahMatKul = 0;
};

typedef struct elemenKeilmuan *adrKeilmuan;
typedef struct elemenMatkul *adrMatkul;
typedef struct elemenRelasi *adrRelasi;

typedef mataKuliah infotypeChild;
typedef bidangKeilmuan infotypeParent;

struct elemenKeilmuan {
    infotypeParent info;
    adrKeilmuan next, prev;
};

struct elemenMatkul {
    infotypeChild info;
    adrMatkul next;
};

struct elemenRelasi {
    adrKeilmuan parent;
    adrMatkul child;
    adrRelasi next;
};

struct listKeilmuan {
    adrKeilmuan first;
    adrKeilmuan last;
};

struct listMatkul {
    adrMatkul first;
};

struct listRelasi {
    adrRelasi first;
};

#endif // GLOBALH_H_INCLUDED
