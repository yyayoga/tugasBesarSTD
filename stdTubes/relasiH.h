#ifndef RELASIH_H_INCLUDED
#define RELASIH_H_INCLUDED
#include <iostream>
#include "bidangKeilmuanH.h"
#include "mataKuliahH.h"
#include "menuH.h"
#include "globalH.h"
#include <unordered_set>

using namespace std;

void createListRelasi(listRelasi &R);
adrRelasi createElemenRelasi(adrKeilmuan parent, adrMatkul child);
void insertRelasi(listRelasi &L, adrRelasi R);
void connectKeilmuanMatkul(listRelasi &L, listKeilmuan K, listMatkul M);
void connectKelimuanMatkulKode(listRelasi &L, listKeilmuan K, listMatkul M);
void putusRelasiKode(listRelasi &L, listKeilmuan &K, listMatkul &M);
void putusRelasiNama(listRelasi &L, listKeilmuan &K, listMatkul &M);
void printRelasi(listRelasi R);
void printMatkulDenganBidangKeilmuanTerbanyak(listRelasi &R, listMatkul M);
void printMatkulDenganBidangKeilmuanTersedikit(listRelasi &R, listMatkul M);

#endif // RELASIH_H_INCLUDED
