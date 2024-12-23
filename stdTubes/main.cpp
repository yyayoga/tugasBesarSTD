#include "bidangKeilmuanH.h"
#include "mataKuliahH.h"
#include "relasiH.h"
#include "menuH.h"
#include "globalH.h"
#include <unordered_set>


int main()
{
    listKeilmuan K;
    listMatkul M;
    listRelasi R;
    adrKeilmuan adrK;
    adrMatkul adrM;
    adrRelasi adrR;
    createListKeilmuan(K);
    createListMatkul(M);
    createListRelasi(R);
    string pilih, edit, edit1, edit2, edit3, edit4, pilihPrint, pilihRelasi;
    string pilihUrut;
    while (true) {
        welcome();
        pilih = start();
        if (pilih == "1") {
            clearScreen();
            while (true) {
                welcomeEdit();
                edit = editData();
                if (edit == "1") {
                    while (true) {
                        edit1 = editData1();
                        if (edit1 == "1") {
                            clearScreen();
                            mainKeilmuanFirst(K);
                        } else if (edit1 == "2") {
                            clearScreen();
                            mainKeilmuanLast(K);
                        } else if (edit1 == "3") {
                            clearScreen();
                            mainKeilmuanAfterNama(K);
                        } else if (edit1 == "4") {
                            clearScreen();
                            break;
                        }
                    }
                } else if (edit == "2") {
                    while (true) {
                        edit2 = editData2();
                        if (edit2 == "1") {
                            clearScreen();
                            mainMatkulFirst(M);
                        } else if (edit2 == "2") {
                            clearScreen();
                            mainMatkulLast(M);
                        } else if (edit2 == "3") {
                            clearScreen();
                            mainMatkulAfterNama(M);
                        } else if (edit2 == "4") {
                            clearScreen();
                            break;
                        }
                    }
                } else if (edit == "3") {
                    while (true) {
                        edit3 = editData3();
                        if (edit3 == "1") {
                            clearScreen();
                            deleteFirstKeilmuan(K, adrK, R);
                        } else if (edit3 == "2") {
                            clearScreen();
                            deleteLastKeilmuan(K, adrK, R);
                        } else if (edit3 == "3") {
                            clearScreen();
                            editData3_3(K, adrK, R);
                        } else if (edit3 == "4") {
                            clearScreen();
                            break;
                        }
                    }
                } else if (edit == "4") {
                    while (true) {
                        edit4 = editData4();
                        if (edit4 == "1") {
                            clearScreen();
                            deleteFirstMatkul(M, adrM, R);
                        } else if (edit4 == "2") {
                            clearScreen();
                            deleteLastMatkul(M, adrM, R);
                        } else if (edit4 == "3") {
                            clearScreen();
                            editData4_3(M, adrM, R);
                        } else if (edit4 == "4") {
                            clearScreen();
                            break;
                        }
                    }
                } else if (edit == "5") {
                    cout << "==============================================" << endl;
                    clearScreen();
                    break;
                }
            }
        } else if (pilih == "2") {
            clearScreen();
            while (true) {
                pilihRelasi = buatRelasi();
                if (pilihRelasi == "1") {
                    clearScreen();
                    connectKeilmuanMatkul(R, K, M);
                } else if (pilihRelasi == "2") {
                    clearScreen();
                    connectKelimuanMatkulKode(R, K, M);
                } else if (pilihRelasi == "3"){
                    clearScreen();
                    putusRelasiNama(R, K, M);
                } else if (pilihRelasi == "4"){
                    clearScreen();
                    putusRelasiKode(R, K, M);
                } else if (pilihRelasi == "5") {
                    clearScreen();
                    break;
                }
            }
        } else if (pilih == "3") {
            clearScreen();
            while (true) {
                pilihUrut = urutkanData();
                if (pilihUrut == "1") {
                    clearScreen();
                    sortBidangAscending(K, R);
                } else if (pilihUrut == "2") {
                    clearScreen();
                    sortBidangDescending(K, R);
                } else if (pilihUrut == "3") {
                    clearScreen();
                    sortMatkulAscending(M);
                } else if (pilihUrut == "4") {
                    clearScreen();
                    sortMatkulDescending(M);
                } else if (pilihUrut == "5") {
                    clearScreen();
                    break;
                }
            }
        } else if (pilih == "4") {
            clearScreen();
            while (true) {
                pilihPrint = tampilkanData();
                if (pilihPrint == "1") {
                    clearScreen();
                    printKeilmuan(K);
                } else if (pilihPrint == "2") {
                    clearScreen();
                    printMatkul(M);
                } else if (pilihPrint == "3") {
                    clearScreen();
                    printRelasi(R);
                } else if (pilihPrint == "4") {
                    clearScreen();
                    printMataKuliahByBidang(K, R);
                } else if (pilihPrint == "5") {
                    clearScreen();
                    printBidangByMatkul(M, R);
                } else if (pilihPrint == "6") {
                    clearScreen();
                    printMatkulDenganBidangKeilmuanTerbanyak(R, M);
                } else if (pilihPrint == "7") {
                    clearScreen();
                    printMatkulDenganBidangKeilmuanTersedikit(R, M);
                } else if (pilihPrint == "8") {
                    clearScreen();
                    break;
                }
            }
        } else if (pilih == "5") {
            clearScreen();
            cout << "Terima kasih telah menggunakan program!" << endl;
            break;
        }
    }
    return 0;
}
