#ifndef MENUH_H_INCLUDED
#define MENUH_H_INCLUDED
#include <iostream>
#include "bidangKeilmuanH.h"
#include "mataKuliahH.h"
#include "relasiH.h"
#include "menuH.h"
#include "globalH.h"
#include <unordered_set>

using namespace std;

void welcome();
string start();
void welcomeEdit();
string editData();
string editData1();
string editData2();
string editData3();
void editData3_3(listKeilmuan &K, adrKeilmuan &P, listRelasi &R);
string editData4();
void editData4_3(listMatkul &M, adrMatkul &P, listRelasi &R);
string buatRelasi();
string urutkanData();
void urutkanData1(listKeilmuan &K, listRelasi R);
void urutkanData2(listKeilmuan &K, listRelasi R);
void urutkanData3(listMatkul &M);
void urutkanData4(listMatkul &M);
string tampilkanData();
void clearScreen();

#endif // MENUH_H_INCLUDED
