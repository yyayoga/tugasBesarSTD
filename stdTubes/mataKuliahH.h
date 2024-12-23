#ifndef MATAKULIAHH_H_INCLUDED
#define MATAKULIAHH_H_INCLUDED
#include <iostream>
#include "bidangKeilmuanH.h"
#include "relasiH.h"
#include "menuH.h"
#include "globalH.h"
#include <unordered_set>

using namespace std;

bool isEmptyMatkul(listMatkul M);
void createListMatkul(listMatkul &M);
adrMatkul createElemenMatkul(infotypeChild x);
void insertFirstMatkul(listMatkul &M, adrMatkul P);
void insertLastMatkul(listMatkul &M, adrMatkul P);
void insertAfterNamaMatkul(listMatkul &M, string namaMatkul, adrMatkul P);
void mainMatkulFirst(listMatkul &M);
void mainMatkulLast(listMatkul &M);
void mainMatkulAfterNama(listMatkul &M);
void deleteFirstMatkul(listMatkul &M, adrMatkul &P, listRelasi &R);
void deleteLastMatkul(listMatkul &M, adrMatkul &P, listRelasi &R);
void deleteAfterNamaMatkul(listMatkul &M, string namaMatkul, adrMatkul &P, listRelasi &R);
void sortMatkulAscending(listMatkul &M);
void sortMatkulDescending(listMatkul &M);
void printMatkul(listMatkul M);
void printMataKuliahByBidang(listKeilmuan K, listRelasi R);
adrMatkul searchMatkulKode(listMatkul M, string kode);
adrMatkul searchMatkulNama(listMatkul M, string nama);

#endif // MATAKULIAHH_H_INCLUDED
