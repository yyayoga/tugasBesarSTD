#include <iostream>
#include "bidangKeilmuanH.h"
#include "mataKuliahH.h"
#include "relasiH.h"
#include "menuH.h"
#include "globalH.h"
#include <unordered_set>

using namespace std;

bool isEmptyKeilmuan(listKeilmuan K) {
    /*
    I.S: List K sudah terdefinisi, dengan pointer first dan last dari list K bisa saja menunjuk ke NULL (jika kosong) atau ke elemen tertentu (jika tidak kosong).
    F.S: Tidak ada perubahan pada list K. Fungsi mengembalikan nilai true jika K.first dan K.last bernilai NULL (list kosong), atau false jika sebaliknya (list tidak kosong).
    */
    return K.first == NULL && K.last == NULL;
}

void createListKeilmuan(listKeilmuan &K) {
    /*
    I.S: List keilmuan K belum diinisialisasi.
    F.S: List keilmuan K terinisialisasi dengan first dan last bernilai NULL.
    */
    K.first = NULL;
    K.last = NULL;
}

adrKeilmuan createElemenKeilmuan(infotypeParent x) {
    /*
    I.S: Tidak ada elemen bidang keilmuan.
    F.S: Elemen bidang keilmuan baru P dibuat dengan informasi x, pointer next dan prev bernilai NULL.
    */
    adrKeilmuan P = new elemenKeilmuan;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirstKeilmuan(listKeilmuan &K, adrKeilmuan P) {
    /*
    I.S: List keilmuan K mungkin kosong atau memiliki elemen.
    F.S: Elemen P ditambahkan di awal list K.
    */
    if (isEmptyKeilmuan(K)) {
        K.first = P;
        K.last = P;
    } else {
        P->next = K.first;
        K.first->prev = P;
        K.first = P;
    }
}

void insertLastKeilmuan(listKeilmuan &K, adrKeilmuan P) {
    /*
    I.S: List keilmuan K mungkin kosong atau memiliki elemen.
    F.S: Elemen P ditambahkan di akhir list K.
    */
    if (isEmptyKeilmuan(K)) {
        K.first = P;
        K.last = P;
    } else {
        P->prev = K.last;
        K.last->next = P;
        K.last = P;
    }
}

void insertAfterNamaBidang(listKeilmuan &K, string namaBidang, adrKeilmuan P) {
    adrKeilmuan Q = K.first;
    while (Q != NULL && Q->info.nama != namaBidang) {
        Q = Q->next;
    }
    if (Q != NULL) {
        P->next = Q->next;
        P->prev = Q;
        if (Q->next != NULL) {
            Q->next->prev = P;
        } else {
            K.last = P;
        }
        Q->next = P;
    } else {
        cout << "Nama bidang tidak ditemukan." << endl;
    }
}

void mainKeilmuanLast(listKeilmuan &K) {
    int jumBidang, i;
    infotypeParent dataBidang;
    cout << "Masukkan jumlah bidang keilmuan: ";
    cin >> jumBidang;
    for (i = 1; i <= jumBidang; i++) {
        cout << "Input data bidang keilmuan ke-" << i << ":" << endl;
        cout << "Kode Bidang  : ";
        cin >> dataBidang.kodeBidang;
        cout << "Nama Bidang  : ";
        cin >> dataBidang.nama;
        cout << "Jumlah matkul: " << dataBidang.jumlahMatKul << endl;
        adrKeilmuan newBidang = createElemenKeilmuan(dataBidang);
        insertLastKeilmuan(K, newBidang);
        cout << endl;
    }
}

void mainKeilmuanFirst(listKeilmuan &K) {
    int jumBidang, i;
    infotypeParent dataBidang;
    cout << "Masukkan jumlah bidang keilmuan: ";
    cin >> jumBidang;
    for (i = 1; i <= jumBidang; i++) {
        cout << "Input data bidang keilmuan ke-" << i << ":" << endl;
        cout << "Kode Bidang  : ";
        cin >> dataBidang.kodeBidang;
        cout << "Nama Bidang  : ";
        cin >> dataBidang.nama;
        cout << "Jumlah matkul: " << dataBidang.jumlahMatKul << endl;
        adrKeilmuan newBidang = createElemenKeilmuan(dataBidang);
        insertFirstKeilmuan(K, newBidang);
        cout << endl;
    }
}

void mainKeilmuanAfterNama(listKeilmuan &K) {
    string namaTujuan;
    infotypeParent dataBidang;
    cout << "Masukkan nama tujuan: ";
    cin >> namaTujuan;
    cout << "Kode Bidang  : ";
    cin >> dataBidang.kodeBidang;
    cout << "Nama Bidang  : ";
    cin >> dataBidang.nama;
    cout << "Jumlah matkul: " << dataBidang.jumlahMatKul << endl;
    adrKeilmuan newBidang = createElemenKeilmuan(dataBidang);
    insertAfterNamaBidang(K, namaTujuan,newBidang);
    cout << endl;
}

void deleteFirstKeilmuan(listKeilmuan &K, adrKeilmuan &P, listRelasi &R) {
    /*
    I.S: List keilmuan K mungkin kosong atau memiliki elemen, dan list relasi R mungkin memiliki relasi terkait elemen pertama.
    F.S: Elemen pertama dari list K dihapus bersama dengan semua relasi terkait di list R.
    */
    if (isEmptyKeilmuan(K)) {
        cout << "List Bidang Keilmuan Kosong." << endl;
        return;
    }
    P = K.first;
    adrRelasi relasiP = R.first;
    adrRelasi relasiPrev = NULL;
    while (relasiP != NULL) {
        if (relasiP->parent == P) {
            if (relasiPrev == NULL) {
                R.first = relasiP->next;
            } else {
                relasiPrev->next = relasiP->next;
            }
            adrRelasi temp = relasiP;
            relasiP = relasiP->next;
            temp->parent = NULL;
            temp->child = NULL;
            delete temp;
        } else {
            relasiPrev = relasiP;
            relasiP = relasiP->next;
        }
    }
    if (K.first == K.last) {
        K.first = NULL;
        K.last = NULL;
    } else {
        K.first = K.first->next;
        K.first->prev = NULL;
    }
    delete P;
    cout << "Bidang Keilmuan berhasil dihapus." << endl;
}

void deleteLastKeilmuan(listKeilmuan &K, adrKeilmuan &P, listRelasi &R) {
    /*
    I.S: List keilmuan K mungkin kosong atau memiliki elemen, dan list relasi R mungkin memiliki relasi terkait elemen terakhir.
    F.S: Elemen terakhir dari list K dihapus bersama dengan semua relasi terkait di list R.
    */
    if (isEmptyKeilmuan(K)) {
        cout << "List Bidang Keilmuan Kosong." << endl;
        return;
    }
    P = K.last;
    adrRelasi relasiP = R.first;
    adrRelasi relasiPrev = NULL;

    while (relasiP != NULL) {
        if (relasiP->parent == P) {
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
    if (K.first == K.last) {
        K.first = NULL;
        K.last = NULL;
    } else {
        K.last = K.last->prev;
        K.last->next = NULL;
    }
    delete P;
    cout << "Bidang Keilmuan terakhir berhasil dihapus." << endl;
}

void deleteAfterNamaBidang(listKeilmuan &K, string namaBidang, adrKeilmuan &P, listRelasi &R) {
    /*
    I.S. List keilmuan K mungkin kosong atau memiliki elemen, dan list relasi R mungkin memiliki relasi terkait elemen setelah elemen dengan nama bidang tertentu.
    F.S. Elemen setelah elemen dengan nama bidang tertentu dihapus bersama dengan semua relasi terkait.
    */
    adrKeilmuan Q = searchKeilmuanNama(K, namaBidang);
    if (Q != NULL && Q->next != NULL) {
        P = Q->next;
        adrRelasi currentRelasi = R.first;
        adrRelasi prevRelasi = NULL;
        while (currentRelasi != NULL) {
            if (currentRelasi->parent == P) {
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
        if (P->next != NULL) {
            P->next->prev = Q;
        } else {
            K.last = Q;
        }
        delete P;
        cout << "Elemen setelah " << namaBidang << " berhasil dihapus." << endl;
    } else {
        cout << "Tidak ditemukan elemen setelah " << namaBidang << " atau bidang tidak ditemukan." << endl;
    }
}


adrKeilmuan searchKeilmuanKode(listKeilmuan K, string kodeBidang) {
    /*
    I.S. List K sudah terdefinisi dan bisa kosong atau berisi elemen. Parameter kodeBidang berupa string sudah diberikan sebagai nilai yang akan dicari.
    F.S. Jika ditemukan elemen dengan info.kodeBidang sama dengan kodeBidang, fungsi mengembalikan pointer ke elemen tersebut.
         Jika tidak ditemukan, fungsi mengembalikan NULL.
    */
    adrKeilmuan P = K.first;
    while (P != NULL) {
        if (P->info.kodeBidang == kodeBidang) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

adrKeilmuan searchKeilmuanNama(listKeilmuan K, string nama) {
    /*
    I.S. List K sudah terdefinisi dan bisa kosong atau berisi elemen. Parameter nama berupa string sudah diberikan sebagai nilai yang akan dicari.
    F.S. Jika ditemukan elemen dengan info.nama sama dengan nama, fungsi mengembalikan pointer ke elemen tersebut.
         Jika tidak ditemukan, fungsi mengembalikan NULL.
    */
    adrKeilmuan P = K.first;
    while (P != NULL) {
        if (P->info.nama == nama) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void sortBidangAscending(listKeilmuan &K, listRelasi R) {
    /*
    I.S: List K dan R terdefinisi, mungkin kosong atau memiliki elemen.
    F.S: List K diurutkan secara ascending berdasarkan jumlah mata kuliah yang terkait di R.
    */
    if (isEmptyKeilmuan(K)) {
        cout << "List Bidang Keilmuan Kosong." << endl;
        return;
    }
    adrKeilmuan P1 = K.first;
    while (P1 != NULL) {
        adrKeilmuan minim = P1;
        adrKeilmuan P2 = P1->next;
        while (P2 != NULL) {
            if (P2->info.jumlahMatKul < minim->info.jumlahMatKul) {
                minim = P2;
            }
            P2 = P2->next;
        }
        if (minim != P1) {
            infotypeParent tempInfo = P1->info;
            P1->info = minim->info;
            minim->info = tempInfo;
        }
        P1 = P1->next;
    }
    cout << "List Bidang Keilmuan berhasil diurutkan secara ascending (Jumlah Mata Kuliah)." << endl;
}

void sortBidangDescending(listKeilmuan &K, listRelasi R) {
    /*
    I.S: List K dan R terdefinisi, mungkin kosong atau memiliki elemen.
    F.S: List K diurutkan secara descending berdasarkan jumlah mata kuliah yang terkait di R.
    */
    if (isEmptyKeilmuan(K)) {
        cout << "List Bidang Keilmuan Kosong." << endl;
        return;
    }
    adrKeilmuan P1 = K.first;
    while (P1 != NULL) {
        adrKeilmuan maxim = P1;
        adrKeilmuan P2 = P1->next;
        while (P2 != NULL) {
            if (P2->info.jumlahMatKul > maxim->info.jumlahMatKul) {
                maxim = P2;
            }
            P2 = P2->next;
        }
        if (maxim != P1) {
            infotypeParent tempInfo = P1->info;
            P1->info = maxim->info;
            maxim->info = tempInfo;
        }
        P1 = P1->next;
    }
    cout << "List Bidang Keilmuan berhasil diurutkan secara descending (Jumlah Mata Kuliah)." << endl;
}

void printKeilmuan(listKeilmuan K) {
    adrKeilmuan P = K.first;
    cout << "Isi list bidang keilmuan:" << endl;
    cout << endl;
    while (P != NULL) {
        cout << "Kode bidang keilmuan    : " << P->info.kodeBidang << endl;
        cout << "Nama bidang keilmuan    : " << P->info.nama << endl;
        cout << "Jumlah Mata Kuliah      : " << P->info.jumlahMatKul << endl;
        cout << endl;
        P = P->next;
    }
}

void printBidangByMatkul(listMatkul M, listRelasi R) {
    /*
    I.S: List relasi R sudah terdefinisi, dan nama mata kuliah yang dicari sudah diberikan.
    F.S: Menampilkan bidang keilmuan yang terkait dengan mata kuliah tertentu.
    */
    adrRelasi currentRelasi = R.first;
    string namaMatkul;
    cout << "Masukkan nama mata kuliah: ";
    cin >> namaMatkul;
    cout << endl;
    adrMatkul P = searchMatkulNama(M, namaMatkul);
    if (P != NULL) {
        cout << "=================================================================" << endl;
        cout << "Bidang keilmuan yang terkait dengan mata kuliah: " << namaMatkul << endl;
        cout << "=================================================================" << endl;
        while (currentRelasi != NULL) {
            if (currentRelasi->child->info.nama == namaMatkul) {
                cout << "Kode bidang keilmuan: " << currentRelasi->parent->info.kodeBidang << endl;
                cout << "Nama bidang keilmuan: " << currentRelasi->parent->info.nama << endl;
                cout << "Jumlah mata kuliah  : " << currentRelasi->parent->info.jumlahMatKul << endl;
                cout << "=================================================================" << endl;
            }
            currentRelasi = currentRelasi->next;
        }
    } else {
        cout << "Mata kuliah dengan nama: " << namaMatkul << " tidak ditemukan." << endl;
    }
}
