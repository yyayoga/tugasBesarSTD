#include <iostream>
#include "bidangKeilmuanH.h"
#include "mataKuliahH.h"
#include "relasiH.h"
#include "menuH.h"
#include "globalH.h"
#include <unordered_set>

using namespace std;

bool isEmptyMatkul(listMatkul K) {
    /*
    I.S. List K sudah terdefinisi, bisa kosong atau berisi elemen.
    F.S. Fungsi mengembalikan nilai true jika K.first == NULL (list kosong), dan false jika list memiliki elemen.
    */
    return K.first == NULL;
}

void createListMatkul(listMatkul &M) {
    /*
    I.S: List mata kuliah M belum diinisialisasi.
    F.S: List mata kuliah M terinisialisasi dengan first bernilai NULL.
    */
    M.first = NULL;
}

adrMatkul createElemenMatkul(infotypeChild x) {
    /*
    I.S: Tidak ada elemen mata kuliah.
    F.S: Elemen mata kuliah baru P dibuat dengan informasi x dan pointer next bernilai NULL.
    */
    adrMatkul P = new elemenMatkul;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertFirstMatkul(listMatkul &M, adrMatkul P) {
    /*
    I.S: List mata kuliah M mungkin kosong atau memiliki elemen.
    F.S: Elemen P ditambahkan di awal list M.
    */
    if (M.first == NULL) {
        M.first = P;
    } else {
        P->next = M.first;
        M.first = P;
    }
}

void insertLastMatkul(listMatkul &M, adrMatkul P) {
    /*
    I.S: List mata kuliah M mungkin kosong atau memiliki elemen.
    F.S: Elemen P ditambahkan di akhir list M.
    */
    if (M.first == NULL) {
        M.first = P;
    } else {
        adrMatkul Q = M.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterNamaMatkul(listMatkul &M, string namaMatkul, adrMatkul P) {
    adrMatkul Q = M.first;
    while (Q != NULL && Q->info.nama != namaMatkul) {
        Q = Q->next;
    }
    if (Q != NULL) {
        P->next = Q->next;
        Q->next = P;
    } else {
        cout << "Nama mata kuliah tidak ditemukan." << endl;
    }
}

void mainMatkulFirst(listMatkul &M) {
    int jumMatkul, i;
    infotypeChild dataMatkul;
    cout << "Masukkan jumlah mata kuliah: ";
    cin >> jumMatkul;
    for (i = 1; i <= jumMatkul; i++) {
        cout << "Input data mata kuliah ke-" << i << ":" << endl;
        cout << "Kode mata kuliah: ";
        cin >> dataMatkul.kode;
        cout << "Nama mata kuliah: ";
        cin >> dataMatkul.nama;
        cout << "Jumlah SKS      : ";
        cin >> dataMatkul.jumlahSks;
        cout << "Dosen pengajar  : ";
        cin >> dataMatkul.dosenPengajar;
        adrMatkul newMatkul = createElemenMatkul(dataMatkul);
        insertFirstMatkul(M, newMatkul);
        cout << endl;
    }
}

void mainMatkulLast(listMatkul &M) {
    int jumMatkul, i;
    infotypeChild dataMatkul;
    cout << "Masukkan jumlah mata kuliah: ";
    cin >> jumMatkul;
    for (i = 1; i <= jumMatkul; i++) {
        cout << "Input data mata kuliah ke-" << i << ":" << endl;
        cout << "Kode mata kuliah: ";
        cin >> dataMatkul.kode;
        cout << "Nama mata kuliah: ";
        cin >> dataMatkul.nama;
        cout << "Jumlah SKS      : ";
        cin >> dataMatkul.jumlahSks;
        cout << "Dosen pengajar  : ";
        cin >> dataMatkul.dosenPengajar;
        adrMatkul newMatkul = createElemenMatkul(dataMatkul);
        insertLastMatkul(M, newMatkul);
        cout << endl;
    }
}

void mainMatkulAfterNama(listMatkul &M) {
    string namaTujuan;
    infotypeChild dataMatkul;
    cout << "Masukkan nama tujuan: ";
    cin >> namaTujuan;
    cout << "Kode mata kuliah: ";
    cin >> dataMatkul.kode;
    cout << "Nama mata kuliah: ";
    cin >> dataMatkul.nama;
    cout << "Jumlah SKS      : ";
    cin >> dataMatkul.jumlahSks;
    cout << "Dosen pengajar  : ";
    cin >> dataMatkul.dosenPengajar;
    adrMatkul newMatkul = createElemenMatkul(dataMatkul);
    insertAfterNamaMatkul(M, namaTujuan,newMatkul);
    cout << endl;
}

void deleteFirstMatkul(listMatkul &M, adrMatkul &P, listRelasi &R) {
    /*
    I.S: List mata kuliah M mungkin kosong atau memiliki elemen, dan list relasi R mungkin memiliki relasi terkait elemen pertama.
    F.S: Elemen pertama dari list M dihapus bersama dengan semua relasi terkait di list R.
    */
    if (M.first == NULL) {
        cout << "List Mata Kuliah Kosong." << endl;
    } else {
        P = M.first;
        adrRelasi currentRelasi = R.first;
        adrRelasi prevRelasi = NULL;
        while (currentRelasi != NULL) {
            if (currentRelasi->child == P) {
                if (prevRelasi == NULL) {
                    R.first = currentRelasi->next;
                } else {
                    prevRelasi->next = currentRelasi->next;
                }
                adrRelasi toDelete = currentRelasi;
                currentRelasi = currentRelasi->next;
                toDelete->parent = NULL;
                toDelete->child = NULL;
                delete toDelete;
            } else {
                prevRelasi = currentRelasi;
                currentRelasi = currentRelasi->next;
            }
        }

        M.first = M.first->next;
        delete P;
        cout << "Mata Kuliah berhasil dihapus." << endl;
    }
}

void deleteLastMatkul(listMatkul &M, adrMatkul &P, listRelasi &R) {
    /*
    I.S: List mata kuliah M mungkin kosong atau memiliki elemen, dan list relasi R mungkin memiliki relasi terkait elemen terakhir.
    F.S: Elemen terakhir dari list M dihapus bersama dengan semua relasi terkait di list R.
    */
    if (isEmptyMatkul(M)) {
        cout << "List Mata Kuliah Kosong." << endl;
        return;
    }
    P = M.first;
    while (P->next != NULL) {
        P = P->next;
    }
    adrRelasi relasiP = R.first;
    adrRelasi relasiPrev = NULL;

    while (relasiP != NULL) {
        if (relasiP->child == P) {
            if (relasiPrev == NULL) {
                R.first = relasiP->next;
            } else {
                relasiPrev->next = relasiP->next;
            }
            adrRelasi temp = relasiP;
            relasiP = relasiP->next;
            delete temp;
        } else {
            relasiPrev = relasiP;
            relasiP = relasiP->next;
        }
    }
    if (M.first == P) {
        M.first = NULL;
    } else {
        adrMatkul prevMatkul = M.first;
        while (prevMatkul->next != P) {
            prevMatkul = prevMatkul->next;
        }
        prevMatkul->next = NULL;
    }
    delete P;
    cout << "Mata Kuliah terakhir berhasil dihapus." << endl;
}

void deleteAfterNamaMatkul(listMatkul &M, string namaMatkul, adrMatkul &P, listRelasi &R) {
    /*
    I.S. List mata kuliah M mungkin kosong atau memiliki elemen, dan list relasi R mungkin memiliki relasi terkait elemen setelah elemen dengan nama mata kuliah tertentu.
    F.S. Elemen setelah elemen dengan nama mata kuliah tertentu dihapus bersama dengan semua relasi terkait.
    */
    adrMatkul Q = searchMatkulNama(M, namaMatkul);
    if (Q != NULL && Q->next != NULL) {
        P = Q->next;
        adrRelasi currentRelasi = R.first;
        adrRelasi prevRelasi = NULL;
        while (currentRelasi != NULL) {
            if (currentRelasi->child == P) {
                if (prevRelasi == NULL) {
                    R.first = currentRelasi->next;
                } else {
                    prevRelasi->next = currentRelasi->next;
                }
                adrRelasi toDelete = currentRelasi;
                currentRelasi = currentRelasi->next;
                toDelete->parent = NULL;
                toDelete->child = NULL;
                delete toDelete;
            } else {
                prevRelasi = currentRelasi;
                currentRelasi = currentRelasi->next;
            }
        }
        Q->next = P->next;

        delete P;
        cout << "Elemen setelah " << namaMatkul << " berhasil dihapus." << endl;
    } else {
        cout << "Tidak ditemukan elemen setelah " << namaMatkul << " atau mata kuliah tidak ditemukan." << endl;
    }
}


adrMatkul searchMatkulKode(listMatkul M, string kode) {
    /*
    I.S. List M sudah terdefinisi dan bisa kosong atau berisi elemen. Parameter kode berupa string sudah diberikan.
    F.S. Jika ditemukan elemen dengan info.kode sama dengan kode, fungsi mengembalikan pointer ke elemen tersebut.
         Jika tidak ditemukan, fungsi mengembalikan NULL.
    */
    adrMatkul P = M.first;
    while (P != NULL) {
        if (P->info.kode == kode) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

adrMatkul searchMatkulNama(listMatkul M, string nama) {
    /*
    I.S. List M sudah terdefinisi dan bisa kosong atau berisi elemen. Parameter nama berupa string sudah diberikan.
    F.S. Jika ditemukan elemen dengan info.nama sama dengan nama, fungsi mengembalikan pointer ke elemen tersebut.
         Jika tidak ditemukan, fungsi mengembalikan NULL.
    */
    adrMatkul P = M.first;
    while (P != NULL) {
        if (P->info.nama == nama) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void sortMatkulAscending(listMatkul &M) {
    /*
    I.S: List M terdefinisi, mungkin kosong atau memiliki elemen.
    F.S: List M diurutkan secara ascending berdasarkan SKS.
    */
    if (isEmptyMatkul(M)) {
        cout << "List Mata Kuliah Kosong." << endl;
        return;
    }
    adrMatkul P1 = M.first;
    while (P1 != NULL) {
        adrMatkul min = P1;
        adrMatkul P2 = P1->next;

        while (P2 != NULL) {
            if (P2->info.jumlahSks < min->info.jumlahSks) {
                min = P2;
            }
            P2 = P2->next;
        }

        if (min != P1) {
            // Tukar manual
            infotypeChild temp = P1->info;
            P1->info = min->info;
            min->info = temp;
        }
        P1 = P1->next;
    }

    cout << "List Mata Kuliah berhasil diurutkan secara ascending (SKS)." << endl;
}


void sortMatkulDescending(listMatkul &M) {
    /*
    I.S: List M terdefinisi, mungkin kosong atau memiliki elemen.
    F.S: List M diurutkan secara descending berdasarkan SKS.
    */
    if (isEmptyMatkul(M)) {
        cout << "List Mata Kuliah Kosong." << endl;
        return;
    }

    adrMatkul P1 = M.first;
    while (P1 != NULL) {
        adrMatkul max = P1;
        adrMatkul P2 = P1->next;

        while (P2 != NULL) {
            if (P2->info.jumlahSks > max->info.jumlahSks) {
                max = P2;
            }
            P2 = P2->next;
        }

        if (max != P1) {
            infotypeChild temp = P1->info;
            P1->info = max->info;
            max->info = temp;
        }
        P1 = P1->next;
    }

    cout << "List Mata Kuliah berhasil diurutkan secara descending (SKS)." << endl;
}


void printMatkul(listMatkul M) {
    adrMatkul P = M.first;
    cout << "Isi list Mata Kuliah:" << endl;
    cout << endl;
    while (P != NULL) {
        cout << "Kode Mata Kuliah    : " << P->info.kode << endl;
        cout << "Nama Mata Kuliah    : " << P->info.nama << endl;
        cout << "Dosen Pengajar      : " << P->info.dosenPengajar << endl;
        cout << "Jumlah SKS          : " << P->info.jumlahSks << endl;
        cout << endl;
        P = P->next;
    }
}

void printMataKuliahByBidang(listKeilmuan K, listRelasi R) {
    /*
    I.S: List relasi R sudah terdefinisi, dan nama bidang yang dicari sudah diberikan.
    F.S: Menampilkan mata kuliah yang terkait dengan bidang keilmuan tertentu.
    */
    adrRelasi currentRelasi = R.first;
    string namaBidang;
    cout << "Masukkan nama bidang keilmuan: ";
    cin >> namaBidang;
    cout << endl;
    adrKeilmuan P = searchKeilmuanNama(K, namaBidang);
    if (P != NULL) {
        cout << "=================================================================" << endl;
        cout << "Mata kuliah yang terkait dengan bidang keilmuan: " << namaBidang << endl;
        cout << "=================================================================" << endl;
        while (currentRelasi != NULL) {
            if (currentRelasi->parent->info.nama == namaBidang) {
                cout << "Nama matkul : " << currentRelasi->child->info.nama << endl;
                cout << "Jumlah SKS  : " << currentRelasi->child->info.jumlahSks << endl;
                cout << "Nama dosen  : " << currentRelasi->child->info.dosenPengajar << endl;
                cout << "=================================================================" << endl;
            }
            currentRelasi = currentRelasi->next;
        }
    } else {
        cout << "Bidang keilmuan dengan nama: " << namaBidang << " tidak ditemukan." << endl;
    }
}
