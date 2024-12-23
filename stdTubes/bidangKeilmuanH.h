#ifndef BIDANGKEILMUANH_H_INCLUDED
#define BIDANGKEILMUANH_H_INCLUDED
#include <iostream>
#include "mataKuliahH.h"
#include "relasiH.h"
#include "menuH.h"
#include "globalH.h"
#include <unordered_set>

using namespace std;

bool isEmptyKeilmuan(listKeilmuan K);
void createListKeilmuan(listKeilmuan &K);
adrKeilmuan createElemenKeilmuan(infotypeParent x);
void insertFirstKeilmuan(listKeilmuan &K, adrKeilmuan P);
void insertLastKeilmuan(listKeilmuan &K, adrKeilmuan P);
void insertAfterNamaBidang(listKeilmuan &K, string namaBidang, adrKeilmuan P);
void mainKeilmuanFirst(listKeilmuan &K);
void mainKeilmuanLast(listKeilmuan &K);
void mainKeilmuanAfterNama(listKeilmuan &K);
void deleteFirstKeilmuan(listKeilmuan &K, adrKeilmuan &P, listRelasi &R);
void deleteLastKeilmuan(listKeilmuan &K, adrKeilmuan &P, listRelasi &R);
void deleteAfterNamaBidang(listKeilmuan &K, string namaBidang, adrKeilmuan &P, listRelasi &R);
void sortBidangAscending(listKeilmuan &K, listRelasi R);
void sortBidangDescending(listKeilmuan &K, listRelasi R);
void printKeilmuan(listKeilmuan K);
void printBidangByMatkul(listMatkul M, listRelasi R);
adrKeilmuan searchKeilmuanKode(listKeilmuan K, string kodeBidang);
adrKeilmuan searchKeilmuanNama(listKeilmuan K, string nama);

#endif // BIDANGKEILMUANH_H_INCLUDED
