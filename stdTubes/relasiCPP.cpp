#include <iostream>
#include "bidangKeilmuanH.h"
#include "mataKuliahH.h"
#include "relasiH.h"
#include "menuH.h"
#include "globalH.h"
#include <unordered_set>

using namespace std;

void createListRelasi(listRelasi &R) {
    /*
    I.S. List R belum terdefinisi atau dalam keadaan sembarang.
    F.S. List R terdefinisi dengan R.first diatur ke NULL (kosong).
    */
    R.first = NULL;
}

adrRelasi createElemenRelasi(adrKeilmuan parent, adrMatkul child) {
    /*
    I.S. Parameter parent (pointer ke elemen keilmuan) dan child (pointer ke elemen mata kuliah) sudah diberikan.
    F.S. Mengembalikan sebuah elemen relasi baru (adrRelasi) yang berisi koneksi dari parent ke child dengan nilai next diatur ke NULL.
    */
    adrRelasi R = new elemenRelasi;
    R->parent = parent;
    R->child = child;
    R->next = NULL;
    return R;
}

void insertRelasi(listRelasi &L, adrRelasi R) {
    /*
    I.S. List L sudah terdefinisi, bisa kosong atau berisi elemen. Parameter R adalah elemen relasi baru yang valid.
    F.S. Elemen R berhasil dimasukkan ke dalam list L sebagai elemen pertama.
    */
    if (L.first == NULL) {
        L.first = R;
    } else {
        R->next = L.first;
        L.first = R;
    }
}

void connectKeilmuanMatkul(listRelasi &L, listKeilmuan K, listMatkul M) {
    /*
    I.S. List L, pointer parent, dan pointer child sudah terdefinisi.
         parent dan child bisa valid atau tidak.
    F.S. Jika parent dan child valid, elemen relasi baru dibuat dan ditambahkan ke list L, serta atribut jumlahMatKul pada parent bertambah 1.
         Jika salah satu dari parent atau child tidak valid, relasi tidak dibuat, dan pesan kesalahan ditampilkan.
    */
    adrKeilmuan parent;
    adrMatkul child;
    cout << "==============================================" << endl;
    cout << "             B U A T  R E L A S I             " << endl;
    cout << "==============================================" << endl;
    string Namakeilmuan, Namamatkul;
    cout << "Masukkan nama bidang keilmuan: ";
    cin >> Namakeilmuan;
    cout << "Masukkan nama mata kuliah: ";
    cin >> Namamatkul;
    parent = searchKeilmuanNama(K, Namakeilmuan);
    child = searchMatkulNama(M, Namamatkul);
    if (parent != NULL && child != NULL) {
        adrRelasi R = createElemenRelasi(parent, child);
        insertRelasi(L, R);
        parent->info.jumlahMatKul++;
        cout << endl;
        cout << "RELASI BERHASIL DIBUAT." << endl;
    } else {
        cout << endl;
        cout << "PARENT ATAU CHILD TIDAK VALID." << endl;
    }
}

void connectKelimuanMatkulKode(listRelasi &L, listKeilmuan K, listMatkul M) {
    adrKeilmuan parent;
    adrMatkul child;
    cout << "==============================================" << endl;
    cout << "             B U A T  R E L A S I             " << endl;
    cout << "==============================================" << endl;
    string kodeKeilmuan, kodeMatkul;
    cout << "Masukkan kode bidang keilmuan: ";
    cin >> kodeKeilmuan;
    cout << "Masukkan kode mata kuliah: ";
    cin >> kodeMatkul;
    parent = searchKeilmuanKode (K, kodeKeilmuan);
    child = searchMatkulKode(M, kodeMatkul);
    if (parent != NULL && child != NULL) {
        adrRelasi R = createElemenRelasi(parent, child);
        insertRelasi(L, R);
        parent->info.jumlahMatKul++;
        cout << endl;
        cout << "RELASI BERHASIL DIBUAT." << endl;
    } else {
        cout << endl;
        cout << "PARENT ATAU CHILD TIDAK VALID." << endl;
    }
}

void printRelasi(listRelasi R) {
    /*
    I.S: List relasi R mungkin kosong atau memiliki elemen.
    F.S: Semua relasi antara bidang keilmuan (parent) dan mata kuliah (child) dicetak dengan format tertentu.
    */
    if (R.first == NULL) {
        cout << "Tidak ada relasi yang tersimpan." << endl;
        return;
    }

    adrRelasi currentRelasi = R.first;
    unordered_set<adrKeilmuan> printedKeilmuan; // Set untuk melacak bidang keilmuan yang sudah dicetak

    while (currentRelasi != NULL) {
        // Cek apakah bidang keilmuan sudah dicetak
        if (printedKeilmuan.find(currentRelasi->parent) == printedKeilmuan.end()) {
            // Jika belum dicetak, cetak nama bidang keilmuan
            printedKeilmuan.insert(currentRelasi->parent); // Tandai bidang keilmuan sudah dicetak
            cout << "================================" << endl;
            cout << "Nama bidang keilmuan: " << currentRelasi->parent->info.nama << endl;
            cout << "================================" << endl;

            // Cetak semua mata kuliah yang terkait dengan bidang keilmuan ini
            adrRelasi tempRelasi = R.first;
            int index = 1;
            bool hasMataKuliah = false;

            while (tempRelasi != NULL) {
                if (tempRelasi->parent == currentRelasi->parent) {
                    // Ada mata kuliah yang terkait
                    hasMataKuliah = true;
                    cout << index << ". Nama matkul: " << tempRelasi->child->info.nama << endl;
                    cout << "   Jumlah SKS : " << tempRelasi->child->info.jumlahSks << endl;
                    index++;
                }
                tempRelasi = tempRelasi->next; // Pindah ke relasi selanjutnya
            }

            if (!hasMataKuliah) {
                cout << "Tidak ada mata kuliah yang terkait." << endl;
            }

            cout << endl; // Spasi antar bidang keilmuan
        }
        currentRelasi = currentRelasi->next; // Pindah ke relasi berikutnya
    }
}

void printMatkulDenganBidangKeilmuanTersedikit(listRelasi &R, listMatkul M) {
    if (isEmptyMatkul(M)) {
        cout << "List Mata Kuliah Kosong." << endl;
        return;
    }

    int minBidang = INT_MAX;
    adrMatkul P = M.first;
    while (P != NULL) {
        int countBidang = 0;
        adrRelasi Rtemp = R.first;
        while (Rtemp != NULL) {
            if (Rtemp->child == P) {
                countBidang++;
            }
            Rtemp = Rtemp->next;
        }

        if (countBidang < minBidang && countBidang > 0) {
            minBidang = countBidang;
        }
        P = P->next;
    }

    // Mencetak mata kuliah dengan jumlah bidang keilmuan minimal
    bool found = false;
    P = M.first;
    while (P != NULL) {
        int countBidang = 0;
        adrRelasi Rtemp = R.first;
        while (Rtemp != NULL) {
            if (Rtemp->child == P) {
                countBidang++;
            }
            Rtemp = Rtemp->next;
        }

        if (countBidang == minBidang) {
            if (!found) {
                cout << "\nMata Kuliah dengan Bidang Keilmuan Paling Sedikit (" << minBidang << " bidang): " << endl;
                found = true;
            }
            cout << "\nNama Mata Kuliah: " << P->info.nama << endl;
            cout << "Jumlah SKS: " << P->info.jumlahSks << endl;
            cout << "Dosen Pengajar: " << P->info.dosenPengajar << endl;
        }
        P = P->next;
    }

    if (!found) {
        cout << "Tidak ada mata kuliah yang memiliki bidang keilmuan." << endl;
    }
};

void printMatkulDenganBidangKeilmuanTerbanyak(listRelasi &R, listMatkul M) {
    if (isEmptyMatkul(M)) {
        cout << "List Mata Kuliah Kosong." << endl;
        return;
    }

    int maxBidang = -1;
    adrMatkul P = M.first;
    while (P != NULL) {
        int countBidang = 0;
        adrRelasi Rtemp = R.first;
        while (Rtemp != NULL) {
            if (Rtemp->child == P) {
                countBidang++;
            }
            Rtemp = Rtemp->next;
        }

        if (countBidang > maxBidang) {
            maxBidang = countBidang;
        }
        P = P->next;
    }
    bool found = false;
    P = M.first;
    while (P != NULL) {
        int countBidang = 0;
        adrRelasi Rtemp = R.first;
        while (Rtemp != NULL) {
            if (Rtemp->child == P) {
                countBidang++;
            }
            Rtemp = Rtemp->next;
        }

        if (countBidang == maxBidang) {
            if (!found) {
                cout << "Mata Kuliah dengan Bidang Keilmuan Paling Banyak (" << maxBidang << " bidang): " << endl;
                found = true;
            }
            cout << "\nNama Mata Kuliah: " << P->info.nama << endl;
            cout << "Jumlah SKS: " << P->info.jumlahSks << endl;
            cout << "Dosen Pengajar: " << P->info.dosenPengajar << endl;
        }
        P = P->next;
    }

    if (!found) {
        cout << "Tidak ada mata kuliah yang memiliki bidang keilmuan." << endl;
    }
}

void putusRelasiNama(listRelasi &L, listKeilmuan &K, listMatkul &M) {
    /*
    I.S: List L, K, dan M sudah terdefinisi dan mungkin kosong atau memiliki elemen.
    F.S: Relasi antara bidang keilmuan dan mata kuliah diputus berdasarkan input kode bidang dan kode mata kuliah.
          Jumlah matkul pada bidang keilmuan dikurangi jika relasi berhasil diputus.
    */
    adrRelasi R = L.first;
    adrRelasi PrevR = NULL; // Pointer untuk menyimpan elemen relasi sebelumnya
    string namaBidang, namaMatkul;
    cout << "Masukkan nama bidang keilmuan: ";
    cin >> namaBidang;
    cout << "Masukkan nama mata kuliah: ";
    cin >> namaMatkul;

    adrKeilmuan parent = searchKeilmuanNama(K, namaBidang);
    adrMatkul child = searchMatkulNama(M, namaMatkul);

    if (parent != NULL && child != NULL) {
        while (R != NULL) {
            if (R->parent == parent && R->child == child) {
                if (PrevR == NULL) {
                    L.first = R->next;
                } else {
                    PrevR->next = R->next;
                }
                parent->info.jumlahMatKul--;
                delete R;
                cout << "Relasi berhasil diputus." << endl;
                return;
            }
            PrevR = R;
            R = R->next;
        }
        cout << "Relasi tidak ditemukan." << endl;
    } else {
        cout << "Bidang keilmuan atau mata kuliah tidak valid." << endl;
    }
}

void putusRelasiKode(listRelasi &L, listKeilmuan &K, listMatkul &M) {
    /*
    I.S: List L, K, dan M sudah terdefinisi dan mungkin kosong atau memiliki elemen.
    F.S: Relasi antara bidang keilmuan dan mata kuliah diputus berdasarkan input kode bidang dan kode mata kuliah.
          Jumlah matkul pada bidang keilmuan dikurangi jika relasi berhasil diputus.
    */
    adrRelasi R = L.first;
    adrRelasi PrevR = NULL; // Pointer untuk menyimpan elemen relasi sebelumnya
    string KodeBidang, KodeMatkul;
    cout << "Masukkan kode bidang keilmuan: ";
    cin >> KodeBidang;
    cout << "Masukkan kode mata kuliah: ";
    cin >> KodeMatkul;

    adrKeilmuan parent = searchKeilmuanKode(K, KodeBidang);
    adrMatkul child = searchMatkulKode(M, KodeMatkul);

    if (parent != NULL && child != NULL) {
        while (R != NULL) {
            if (R->parent == parent && R->child == child) {
                if (PrevR == NULL) {
                    L.first = R->next;
                } else {
                    PrevR->next = R->next;
                }
                parent->info.jumlahMatKul--;
                delete R;
                cout << "Relasi berhasil diputus." << endl;
                return;
            }
            PrevR = R;
            R = R->next;
        }
        cout << "Relasi tidak ditemukan." << endl;
    } else {
        cout << "Bidang keilmuan atau mata kuliah tidak valid." << endl;
    }
}
