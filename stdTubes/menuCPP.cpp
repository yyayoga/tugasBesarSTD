#include <iostream>
#include "bidangKeilmuanH.h"
#include "mataKuliahH.h"
#include "relasiH.h"
#include "menuH.h"
#include "globalH.h"
#include <unordered_set>

using namespace std;

void welcome() {
    cout << "==============================================" << endl;
    cout << "               W E L C O M E !                " << endl;
    cout << "         BIDANG KEILMUAN MATA KULIAH          " << endl;
    cout << "==============================================" << endl;
}
string start() {
    //SELAMAT DATANG
    string pilih;
    cout << "Pilihan Menu:" << endl;
    cout << "1. Edit data." << endl;
    cout << "2. Edit relasi." << endl;
    cout << "3. Urutkan data." << endl;
    cout << "4. Tampilkan data." << endl;
    cout << "5. Exit." << endl;
    cout << "==============================================" << endl;
    cout << "Pilih 1/2/3/4/5: ";
    cin >> pilih;
    return pilih;
}

void welcomeEdit() {
    cout << "==============================================" << endl;
    cout << "              E D I T  D A T A                " << endl;
    cout << "==============================================" << endl;
}

string editData() {
    //EDIT DATA
    string pilih;
    cout << "1. Tambah data bidang keilmuan." << endl;
    cout << "2. Tambah data mata kuliah." << endl;
    cout << "3. Hapus data bidang keilmuan." << endl;
    cout << "4. Hapus data mata kuliah." << endl;
    cout << "5. Kembali." << endl;
    cout << "==============================================" << endl;
    cout << "Pilih: 1/2/3/4/5: ";
    cin >> pilih;
    return pilih;
}

string editData1() {
    string edit1;
    cout << "1. Insert first." << endl;
    cout << "2. Insert last." << endl;
    cout << "3. Insert setelah nama." << endl;
    cout << "4. Kembali." << endl;
    cout << "==============================================" << endl;
    cout << "Pilih: 1/2/3/4: ";
    cin >> edit1;
    return edit1;
}


string editData2() {
    string edit2;
    cout << "1. Insert first." << endl;
    cout << "2. Insert last." << endl;
    cout << "3. Insert setelah nama." << endl;
    cout << "4. Kembali." << endl;
    cout << "==============================================" << endl;
    cout << "Pilih: 1/2/3/4: ";
    cin >> edit2;
    return edit2;
}

string editData3() {
    string edit3;
    cout << "1. Delete first." << endl;
    cout << "2. Delete last." << endl;
    cout << "3. Delete setelah nama." << endl;
    cout << "4. Kembali." << endl;
    cout << "==============================================" << endl;
    cout << "Pilih: 1/2/3/4: ";
    cin >> edit3;
    return edit3;
}

void editData3_3(listKeilmuan &K, adrKeilmuan &P, listRelasi &R) {
    string namaHapusBidang;
    cout << "Masukkan nama bidang keilmuan: ";
    cin >> namaHapusBidang;
    deleteAfterNamaBidang(K, namaHapusBidang, P, R);
}

string editData4() {
    string edit4;
    cout << "1. Delete first." << endl;
    cout << "2. Delete last." << endl;
    cout << "3. Delete setelah nama." << endl;
    cout << "4. Kembali." << endl;
    cout << "==============================================" << endl;
    cout << "Pilih: 1/2/3/4: ";
    cin >> edit4;
    return edit4;
}

void editData4_3(listMatkul &M, adrMatkul &P, listRelasi &R) {
    string namaHapusMatkul;
    cout << "Masukkan nama mata kuliah: ";
    cin >> namaHapusMatkul;
    deleteAfterNamaMatkul(M, namaHapusMatkul, P, R);
}

string buatRelasi() {
    string relasi;
    cout << "==============================================" << endl;
    cout << "             E D I T  R E L A S I             " << endl;
    cout << "==============================================" << endl;
    cout << "1. Buat relasi berdasarkan nama." << endl;
    cout << "2. Buat relasi berdasarkan kode." << endl;
    cout << "3. Hapus relasi berdasarkan nama." << endl;
    cout << "4. Hapus relasi berdasarkan kode." << endl;
    cout << "5. Kembali." << endl;
    cout << "==============================================" << endl;
    cout << "Pilih: 1/2/3/4/5: ";
    cin >> relasi;
    return relasi;
}

string urutkanData() {
    string urut;
    cout << "==============================================" << endl;
    cout << "            U R U T K A N  D A T A            " << endl;
    cout << "==============================================" << endl;
    cout << "1. Ascending bidang(Jumlah Matkul)." << endl;
    cout << "2. Descending bidang(Jumlah Matkul)." << endl;
    cout << "3. Ascending mata kuliah(SKS)." << endl;
    cout << "4. Descending mata kuliah(SKS)." << endl;
    cout << "5. Kembali." << endl;
    cout << "==============================================" << endl;
    cout << "Pilih: 1/2/3/4/5: ";
    cin >> urut;
    return urut;
}

void urutkanData1(listKeilmuan &K, listRelasi R) {
    sortBidangAscending(K, R);
}

void urutkanData2(listKeilmuan &K, listRelasi R) {
    sortBidangDescending(K, R);
}

void urutkanData3(listMatkul &M) {
    sortMatkulAscending(M);
}

void urutkanData4(listMatkul &M) {
    sortMatkulDescending(M);
}

string tampilkanData() {
    string print;
    cout << "=================================================================" << endl;
    cout << "                   T A M P I L K A N  D A T A                    " << endl;
    cout << "=================================================================" << endl;
    cout << "1. Tampilkan data bidang keilmuan. " << endl;
    cout << "2. Tampilkan data mata kuliah. " << endl;
    cout << "3. Tampilkan relasi. " << endl;
    cout << "4. Mata kuliah dengan bidang keilmuan tertentu. " << endl;
    cout << "5. Bidang keilmuan dengan mata kuliah tertentu. " << endl;
    cout << "6. Mata kuliah dengan bidang keilmuan paling banyak." << endl;
    cout << "7. Mata kuliah dengan bidang keilmuan paling sedikit." << endl;
    cout << "8. kembali. " << endl;
    cout << "=================================================================" << endl;
    cout << "Pilih: 1/2/3/4/5/6/7/8: ";
    cin >> print;
    return print;
}

void clearScreen() {
    system("cls");
}
