#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

struct pole {
    char figura = '.';
    bool dama = 0;
};

pole hraciPole[8][8];
pole simulacniPole[8][8];
bool aktualniHrac=0;                    // 0 - bila, 1 - cerna
bool hracVSimulaci=0;
int bile, cerne;

void vypsatHraciPole() {        // vypise pole do terminalu s teckami jako prazdnymi poli a O/X jako kameny
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++) {
            if (hraciPole[i][j].dama) cout << char(hraciPole[i][j].figura-('a'-'A')) << ' ';
            else std::cout << hraciPole[i][j].figura << ' ';
        }
        std::cout << endl;
        }
}

void zakladniPoziceHracihoPole() {         // nastavi hru do zakladni pozice o 12 kamenech pro každou stranu
    for (int i=0;i<3;i++) {
        for (int j=0;j<8;j++) {
            if (!((i+j)%2)) {
                hraciPole[i][j].figura = 'x';
            }
        }
    }
    for (int i=5;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (!((i+j)%2)) {
                hraciPole[i][j].figura = 'o';
            }
        }
    }
}

vector<string> mozneTahy(pole pole[8][8], bool hrac) {            // zjisti vsechny možné tahy v pozici a vriti je formou vectoru stringů
    vector<string> mozneTahy;
    bool mozneBrani = 0, mozneBraniDamou = 0;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (pole[i][j].dama==0) {
                if (pole[i][j].figura=='x' && hrac == 0) {
                    if (pole[i+1][j-1].figura=='.') {
                        if (!mozneBrani && !mozneBraniDamou) {
                            char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                            char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                            char tahX = i + 1 + 'A';    // pricita 1 - zjisteni dalsiho tahu
                            char tahY = j - 1 + '1';
                            if((i+1) <= 7 && (j-1) >= 0) {
                                string tah = string(1, puvodX)+puvodY+tahX+tahY;
                                mozneTahy.push_back(tah);
                            }
                        }
                    } else if (pole[i+1][j-1].figura=='o' && pole[i+2][j-2].figura=='.') {
                        if (!mozneBraniDamou) {
                            char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                            char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                            char tahX = i + 1 + 'A';    // pricita 1 - zjisteni dalsiho tahu
                            char tahY = j - 1 + '1';
                            if((i+2) <= 7 && (j-2) >= 0) {
                                if (!mozneBrani) mozneTahy = {};
                                mozneBrani = 1;
                                string tah = string(1, puvodX)+puvodY+tahX+tahY;
                                mozneTahy.push_back(tah);
                            }
                        }
                    }
                    if (pole[i+1][j+1].figura=='.') {
                        if (!mozneBrani && !mozneBraniDamou) {
                            char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                            char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                            char tahX = i + 1 + 'A';    // pricita 1 - zjisteni dalsiho tahu
                            char tahY = j + 1 + '1';
                            if((i+1) <= 7 && (j+1) <= 7) {
                                string tah = string(1, puvodX)+puvodY+tahX+tahY;
                                mozneTahy.push_back(tah);
                            }
                        }
                    } else if (pole[i+1][j+1].figura=='o' && pole[i+2][j+2].figura=='.') {
                        if (!mozneBraniDamou) {
                            char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                            char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                            char tahX = i + 1 + 'A';    // pricita 1 - zjisteni dalsiho tahu
                            char tahY = j + 1 + '1';
                            if((i+2) <= 7 && (j+2) <= 7) {
                                if (!mozneBrani) mozneTahy = {};
                                mozneBrani = 1;
                                string tah = string(1, puvodX)+puvodY+tahX+tahY;
                                mozneTahy.push_back(tah);
                            }
                        }
                    }
                }
                if (pole[i][j].figura=='o' && hrac == 1) {
                    if (pole[i-1][j-1].figura=='.') {
                        if (!mozneBrani && !mozneBraniDamou) {
                            char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                            char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                            char tahX = i - 1 + 'A';    // pricita 1 - zjisteni dalsiho tahu
                            char tahY = j - 1 + '1';
                            if((i-1) >= 0 && (j-1) >= 0) {
                                string tah = string(1, puvodX)+puvodY+tahX+tahY;
                                mozneTahy.push_back(tah);
                            }
                        }
                    } else if (pole[i-1][j-1].figura=='x' && pole[i-2][j-2].figura=='.') {
                        if (!mozneBraniDamou) {
                            char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                            char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                            char tahX = i - 1 + 'A';    // pricita 1 - zjisteni dalsiho tahu
                            char tahY = j - 1 + '1';
                            if((i-2) >= 0 && (j-2) >= 0) {
                                string tah = string(1, puvodX)+puvodY+tahX+tahY;
                                mozneTahy = {};
                                mozneTahy.push_back(tah);
                                mozneBrani=1;
                            }
                        }
                    }
                    if (pole[i-1][j+1].figura=='.') {
                        if (!mozneBrani && !mozneBraniDamou) {
                            char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                            char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                            char tahX = i - 1 + 'A';    // pricita 1 - zjisteni dalsiho tahu
                            char tahY = j + 1 + '1';
                            if((i-1) >= 0 && (j+1) <= 7) {
                                string tah = string(1, puvodX)+puvodY+tahX+tahY;
                                mozneTahy.push_back(tah);
                            }
                        }
                    } else if (pole[i-1][j+1].figura=='x' && pole[i-2][j+2].figura=='.') {
                        if (!mozneBraniDamou) {
                            char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                            char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                            char tahX = i - 1 + 'A';    // pricita 1 - zjisteni dalsiho tahu
                            char tahY = j + 1 + '1';
                            if((i-2) >= 0 && (j+2) <= 7) {
                                if (!mozneBrani) mozneTahy = {};
                                mozneBrani = 1;
                                string tah = string(1, puvodX)+puvodY+tahX+tahY;
                                mozneTahy.push_back(tah);
                            }
                        }
                    }
                }
            } else {
                if (pole[i][j].figura=='x' && hrac==0) {
                    char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                    char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                    char tahX = i + 1 + 'A';
                    char tahY = j + 1 + '1';
                    bool preskoceno = 0;
                    while (tahX<='H' && tahY<='8') {
                        if (pole[tahX-'A'][tahY-'1'].figura=='o') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].figura=='x') break;
                        else {
                            if (!(mozneBrani && preskoceno) ^ !mozneBrani) {
                                tahX++;
                                tahY++;
                                continue;
                            }
                            if (preskoceno && !mozneBraniDamou) {
                                mozneTahy = {};
                                mozneBraniDamou=1;
                                mozneBrani = 1;
                            }
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX++;
                            tahY++;
                        }
                    }
                    tahX = i + 1 + 'A';
                    tahY = j - 1 + '1';
                    preskoceno = 0;
                    while (tahX<='H' && tahY>='1') {
                        if (pole[tahX-'A'][tahY-'1'].figura=='o') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY--;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].figura=='x') break;
                        else {
                            if (!(mozneBrani && preskoceno) ^ !mozneBrani) {
                                tahX++;
                                tahY--;
                                continue;
                            }
                            if (preskoceno && !mozneBraniDamou) {
                                mozneTahy = {}; 
                                mozneBraniDamou=1;
                                mozneBrani = 1;
                            }
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX++;
                            tahY--;
                        }
                    }
                    tahX = i - 1 + 'A';
                    tahY = j - 1 + '1';
                    preskoceno = 0;
                    while (tahX>='A' && tahY>='1') {
                        if (pole[tahX-'A'][tahY-'1'].figura=='o') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX--;
                                tahY--;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].figura=='x') break;
                        else {
                            if (!(mozneBrani && preskoceno) ^ !mozneBrani) {
                                tahX--;
                                tahY--;
                                continue;
                            }
                            if (preskoceno && !mozneBraniDamou) {
                                mozneTahy = {}; 
                                mozneBraniDamou=1;
                                mozneBrani = 1;
                            }
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX--;
                            tahY--;
                        }
                    }
                    tahX = i - 1 + 'A';
                    tahY = j + 1 + '1';
                    preskoceno = 0;
                    while (tahX>='A' && tahY<='8') {
                        if (pole[tahX-'A'][tahY-'1'].figura=='o') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX--;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].figura=='x') break;
                        else {
                            if (!(mozneBrani && preskoceno) ^ !mozneBrani) {
                                tahX--;
                                tahY++;
                                continue;
                            }
                            if (preskoceno && !mozneBraniDamou) {
                                mozneTahy = {}; 
                                mozneBraniDamou=1;
                                mozneBrani = 1;
                            }
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX--;
                            tahY++;
                        }
                    }
                } else if (pole[i][j].figura=='o' && hrac==1) {
                    char puvodX = i + 'A';      // pricita 'A' aby bylo pismeno
                    char puvodY = j + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
                    char tahX = i + 1 + 'A';
                    char tahY = j + 1 + '1';
                    bool preskoceno = 0;
                    while (tahX<='H' && tahY<='8') {
                        if (pole[tahX-'A'][tahY-'1'].figura=='x') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].figura=='o') break;
                        else {
                            if (!(mozneBrani && preskoceno) ^ !mozneBrani) {
                                tahX++;
                                tahY++;
                                continue;
                            }
                            if (preskoceno && !mozneBraniDamou) {
                                mozneTahy = {}; 
                                mozneBraniDamou=1;
                                mozneBrani = 1;
                            }
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX++;
                            tahY++;
                        }
                    }
                    tahX = i + 1 + 'A';
                    tahY = j - 1 + '1';
                    preskoceno = 0;
                    while (tahX<='H' && tahY>='1') {
                        if (pole[tahX-'A'][tahY-'1'].figura=='x') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY--;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].figura=='o') break;
                        else {
                            if (!(mozneBrani && preskoceno) ^ !mozneBrani) {
                                tahX++;
                                tahY--;
                                continue;
                            }                            if (preskoceno && !mozneBraniDamou) {
                                mozneTahy = {}; 
                                mozneBraniDamou=1;
                                mozneBrani = 1;
                            }
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX++;
                            tahY--;
                        }
                    }
                    tahX = i - 1 + 'A';
                    tahY = j - 1 + '1';
                    preskoceno = 0;
                    while (tahX>='A' && tahY>='1') {
                        if (pole[tahX-'A'][tahY-'1'].figura=='x') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX--;
                                tahY--;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].figura=='o') break;
                        else {
                            if (!(mozneBrani && preskoceno) ^ !mozneBrani) {
                                tahX--;
                                tahY--;
                                continue;
                            }
                            if (preskoceno && !mozneBraniDamou) {
                                mozneTahy = {}; 
                                mozneBraniDamou=1;
                                mozneBrani = 1;
                            }
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX--;
                            tahY--;
                        }
                    }
                    tahX = i - 1 + 'A';
                    tahY = j + 1 + '1';
                    preskoceno = 0;
                    while (tahX>='A' && tahY<='8') {
                        if (pole[tahX-'A'][tahY-'1'].figura=='x') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX--;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].figura=='o') break;
                        else {
                            if (!(mozneBrani && preskoceno) ^ !mozneBrani) {
                                tahX--;
                                tahY++;
                                continue;
                            }
                            if (preskoceno && !mozneBraniDamou) {
                                mozneTahy = {}; 
                                mozneBraniDamou=1;
                                mozneBrani = 1;
                            }
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX--;
                            tahY++;
                        }
                    }
                }
            }
        }
    }
    return mozneTahy;
}

vector<string> moznePokracovaniTahu(pole pole[8][8], int zacatecniPoleX, int zacatecniPoleY, bool hrac) {
    vector<string> mozneBraniPoTahu;
    string tah;
    if (!pole[zacatecniPoleX][zacatecniPoleY].dama) {
        if (pole[zacatecniPoleX][zacatecniPoleY].figura=='x') {
            if (pole[zacatecniPoleX+1][zacatecniPoleY-1].figura=='o' && pole[zacatecniPoleX+2][zacatecniPoleY-2].figura=='.' && zacatecniPoleX+2<=7 && zacatecniPoleY-2 >= 0) {
                tah = string(' ', 1)+char(zacatecniPoleX+'A')+char(zacatecniPoleY+'1')+char(zacatecniPoleX+'A'+1)+char(zacatecniPoleY+'1'-1);
                mozneBraniPoTahu.push_back(tah);
            }
            if (pole[zacatecniPoleX+1][zacatecniPoleY+1].figura=='o' && pole[zacatecniPoleX+2][zacatecniPoleY+2].figura=='.' && zacatecniPoleX+2<=7 && zacatecniPoleY+2 <= 7) {
                tah = string(' ', 1)+char(zacatecniPoleX+'A')+char(zacatecniPoleY+'1')+char(zacatecniPoleX+'A'+1)+char(zacatecniPoleY+'1'+1);
                mozneBraniPoTahu.push_back(tah);
            }
        } else if (pole[zacatecniPoleX][zacatecniPoleY].figura=='o') {
            if (pole[zacatecniPoleX-1][zacatecniPoleY-1].figura=='x' && pole[zacatecniPoleX-2][zacatecniPoleY-2].figura=='.' && zacatecniPoleX-2>=0 && zacatecniPoleY-2 >= 0) {
                tah = string(' ', 1)+char(zacatecniPoleX+'A')+char(zacatecniPoleY+'1')+char(zacatecniPoleX+'A'-1)+char(zacatecniPoleY+'1'-1);
                mozneBraniPoTahu.push_back(tah);
            }
            if (pole[zacatecniPoleX-1][zacatecniPoleY+1].figura=='x' && pole[zacatecniPoleX-2][zacatecniPoleY+2].figura=='.' && zacatecniPoleX-2>=0 && zacatecniPoleY+2 <= 7) {
                tah = string(' ', 1)+char(zacatecniPoleX+'A')+char(zacatecniPoleY+'1')+char(zacatecniPoleX+'A'-1)+char(zacatecniPoleY+'1'+1);
                mozneBraniPoTahu.push_back(tah);
            }
        }
    } else if (pole[zacatecniPoleX][zacatecniPoleY].dama) {
        char puvodX = zacatecniPoleX + 'A';      // pricita 'A' aby bylo pismeno
        char puvodY = zacatecniPoleY + '1';      // pricita '1' aby bylo cislo v rozmezi 1-8
        char tahX = zacatecniPoleX + 1 + 'A';
        char tahY = zacatecniPoleY + 1 + '1';
        bool preskoceno = 0;
        while (tahX<='H' && tahY<='8') {
            if (pole[tahX-'A'][tahY-'1'].figura!=pole[zacatecniPoleX][zacatecniPoleY].figura && pole[tahX-'A'][tahY-'1'].figura!='.') {
                if (preskoceno) break;
                else {
                    preskoceno = 1;
                    tahX++;
                    tahY++;
                }
            } else if (pole[tahX-'A'][tahY-'1'].figura==pole[zacatecniPoleX][zacatecniPoleY].figura) break;
            else {
                if (preskoceno) {
                    string tah = string(1, puvodX)+puvodY+tahX+tahY;
                    mozneBraniPoTahu.push_back(tah);
                }
                tahX++;
                tahY++;
            }
        }
        tahX = zacatecniPoleX + 1 + 'A';
        tahY = zacatecniPoleY - 1 + '1';
        preskoceno = 0;
        while (tahX<='H' && tahY>='1') {
            if (pole[tahX-'A'][tahY-'1'].figura!=pole[zacatecniPoleX][zacatecniPoleY].figura && pole[tahX-'A'][tahY-'1'].figura!='.') {
                if (preskoceno) break;
                else {
                    preskoceno = 1;
                    tahX++;
                    tahY--;
                }
            } else if (pole[tahX-'A'][tahY-'1'].figura==pole[zacatecniPoleX][zacatecniPoleY].figura) break;
            else {
                if (preskoceno) {
                    string tah = string(1, puvodX)+puvodY+tahX+tahY;
                    mozneBraniPoTahu.push_back(tah);
                }
                tahX++;
                tahY--;
            }
        }
        tahX = zacatecniPoleX - 1 + 'A';
        tahY = zacatecniPoleY - 1 + '1';
        preskoceno = 0;
        while (tahX>='A' && tahY>='1') {
            if (pole[tahX-'A'][tahY-'1'].figura!=pole[zacatecniPoleX][zacatecniPoleY].figura && pole[tahX-'A'][tahY-'1'].figura!='.') {
                if (preskoceno) break;
                else {
                    preskoceno = 1;
                    tahX--;
                    tahY--;
                }
            } else if (pole[tahX-'A'][tahY-'1'].figura==pole[zacatecniPoleX][zacatecniPoleY].figura) break;
            else {
                if (preskoceno) {
                    string tah = string(1, puvodX)+puvodY+tahX+tahY;
                    mozneBraniPoTahu.push_back(tah);
                }
                tahX--;
                tahY--;
            }
        }
        tahX = zacatecniPoleX - 1 + 'A';
        tahY = zacatecniPoleY + 1 + '1';
        preskoceno = 0;
        while (tahX>='A' && tahY<='8') {
            if (pole[tahX-'A'][tahY-'1'].figura!=pole[zacatecniPoleX][zacatecniPoleY].figura && pole[tahX-'A'][tahY-'1'].figura!='.') {
                if (preskoceno) break;
                else {
                    preskoceno = 1;
                    tahX--;
                    tahY++;
                }
            } else if (pole[tahX-'A'][tahY-'1'].figura==pole[zacatecniPoleX][zacatecniPoleY].figura) break;
            else {
                if (preskoceno) {
                    string tah = string(1, puvodX)+puvodY+tahX+tahY;
                    mozneBraniPoTahu.push_back(tah);
                }
                tahX--;
                tahY++;
            }
        }
    }
    return mozneBraniPoTahu;
}

string pokracovaniTahu(vector<string> mozneBraniPoTahu, bool hrac) {
    if (mozneBraniPoTahu.size()>1) {
        // string volba;
        // if (!hrac) {
        //     cout << "Jak chcete pokracovat: " << endl;
        //     for (string tah : mozneBraniPoTahu) {
        //         cout << tah << "   ";
        //     }
        //     cout << endl;
        //     cin >> volba;
        //     for (string tah : mozneBraniPoTahu) {
        //         if (volba==tah) {
        //             return volba;
        //         }
        //     }
        // } else {
            int n = rand()%mozneBraniPoTahu.size();
            return mozneBraniPoTahu[n];
        // }
    }
    return mozneBraniPoTahu[0];
}

bool pohyb(string tah, vector<string> mozneTahy, pole pole[8][8], bool hrac) {
    bool brani = 0;
    int vyslednePoleX, vyslednePoleY;
    int velikost = tah.size();
    for (int i=0;i<mozneTahy.size();i++) {
        if (tah==mozneTahy[i]) {
            int puvodX = tah[velikost-4] - 'A';
            int puvodY = tah[velikost-3]- '0' - 1;
            int tahX = tah[velikost-2] - 'A';
            int tahY = tah[velikost-1] - '0' - 1;
            if (pole[tahX][tahY].figura!='.') {
                int posunX = tahX-puvodX;
                int posunY = tahY-puvodY;
                pole[puvodX+2*posunX][puvodY+2*posunY].figura = pole[puvodX][puvodY].figura;
                pole[puvodX+2*posunX][puvodY+2*posunY].dama = pole[puvodX][puvodY].dama;
                pole[tahX][tahY].figura='.';
                pole[tahX][tahY].dama=0;
                brani = 1;
                vyslednePoleX = puvodX+2*posunX;
                vyslednePoleY = puvodY+2*posunY;
            } else {
                pole[tahX][tahY].figura = pole[puvodX][puvodY].figura;
                pole[tahX][tahY].dama = pole[puvodX][puvodY].dama;
            }
            pole[puvodX][puvodY].figura = '.';
            pole[puvodX][puvodY].dama = 0;
            if (abs(puvodX-tahX)>1) {
                int nasX, nasY;             // nasobice pohybu (smeru nahoru/dolu a doleva/doprava)
                nasX = (puvodX-tahX>0) ? -1 : 1;
                nasY = (puvodY-tahY>0) ? -1 : 1;
                for (int j=1;j<abs(puvodX-tahX);j++) {
                    if (pole[puvodX+j*nasX][puvodY+j*nasY].figura=='.') continue;
                    if (pole[puvodX+j*nasX][puvodY+j*nasY].figura!=pole[puvodX][puvodY].figura) {
                        pole[puvodX+j*nasX][puvodY+j*nasY].figura = '.';
                        pole[puvodX+j*nasX][puvodY+j*nasY].dama = 0;
                        brani = 1;
                        vyslednePoleX = tahX;
                        vyslednePoleY = tahY;
                    }
                }
            }
            if (brani) {
                vector<string> vsechnyDalsiTahy = moznePokracovaniTahu(pole, vyslednePoleX, vyslednePoleY, hrac);
                if (vsechnyDalsiTahy.size()>0) {
                    string dalsiTah = pokracovaniTahu(vsechnyDalsiTahy, hrac);
                    pohyb(dalsiTah, vsechnyDalsiTahy, pole, hrac);
                }
            }
            return 1;
        }
    }
    std::cout << "Neplatny tah, hrajte znovu." << endl;
    return 0;
}

void pocetFigur(pole pole[8][8]) {
    bile = 0;
    cerne = 0;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (pole[i][j].figura != '.') {
                if (pole[i][j].figura == 'x') bile++;
                else cerne++;
            }
        }
    }
}

float vyhodaVPozici(pole pole[8][8]) {
    float vyhoda = 0.0;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            float vyhodaZPole = 0.0;
            if (pole[i][j].figura=='x' && !pole[i][j].dama) {
                vyhodaZPole = 1 + 0.1 * (i+1);
            } else if (pole[i][j].figura=='x' && pole[i][j].dama) {
                vyhodaZPole = 3;
            } else if (pole[i][j].figura=='o' && !pole[i][j].dama) {
                vyhodaZPole = -(1 + 0.1 * (7-i+1));
            } else if (pole[i][j].figura=='o' && pole[i][j].dama) {
                vyhodaZPole = -3;
            }
            vyhodaZPole = round(vyhodaZPole*10)/10.0;
            vyhoda += vyhodaZPole;
        }
    }
    return vyhoda;
}

vector<string> nejlepsiTahyVPozici(pole pole[8][8], int hloubka) {
    vector<string> nejlepsiTahy = {};
    float nejlepsiTah = !aktualniHrac ? -999 : 999;
    vector<string> tahy = mozneTahy(hraciPole, hracVSimulaci);

    for (string tah : tahy) {
        float vyhoda;
        
        for (int i=0;i<8;i++) {
            for (int j=0;j<8;j++) {
                simulacniPole[i][j] = hraciPole[i][j];
            }
        }

        bool platnyPohyb = pohyb(tah, tahy, simulacniPole, hracVSimulaci);

        vyhoda = vyhodaVPozici(simulacniPole);

        if (aktualniHrac) {
            if (vyhoda<nejlepsiTah) {
                nejlepsiTahy = {};
                nejlepsiTahy.push_back(tah);
                nejlepsiTah=vyhoda;
            } else if (vyhoda==nejlepsiTah) {
                nejlepsiTahy.push_back(tah);
            }
        } else {
            if (vyhoda>nejlepsiTah) {
                nejlepsiTahy = {};
                nejlepsiTahy.push_back(tah);
                nejlepsiTah=vyhoda;
            } else if (vyhoda==nejlepsiTah) {
                nejlepsiTahy.push_back(tah);
            }
        }
    }
    return nejlepsiTahy;
}

int gameLoop() {
    zakladniPoziceHracihoPole();
    do {
        vector<string> tahy = mozneTahy(hraciPole, aktualniHrac);

        if (tahy.size()==0) {
            (aktualniHrac==0?bile:cerne)=0;
            break;
        }
        cout << "\033[2J\033[H";
        if (aktualniHrac==0) {
            float vyhoda = vyhodaVPozici(hraciPole);
            std::cout << fixed << setprecision(1) << vyhoda << endl;
            for (string tah : tahy) 
                std::cout << tah << "   ";
            std::cout << endl;
            vypsatHraciPole();
        }
        
        string tah;
        if (aktualniHrac==0)
            std::cin >> tah;
        else 
        {
            hracVSimulaci = aktualniHrac;
            vector<string> nejlepsiTahy = nejlepsiTahyVPozici(hraciPole, 1);
            int n = rand()%nejlepsiTahy.size();
            tah = nejlepsiTahy[n];
        }
        if (tah=="REMIZA") {
            std::cout << "Hra skoncila remizou. ";
            return 0;
        }

        bool platnyTah = pohyb(tah, tahy, hraciPole, aktualniHrac);
        if (platnyTah) aktualniHrac = (aktualniHrac?0:1);
        
        for (int i=0;i<8;i++) {
            if (hraciPole[0][i].figura=='o') hraciPole[0][i].dama=1;
            if (hraciPole[7][i].figura=='x') hraciPole[7][i].dama=1;
        }
        
        pocetFigur(hraciPole);
        
    } while (bile > 0 && cerne > 0);
    vypsatHraciPole();
    if (bile == 0) std::cout << "Vyhral algoritmus." << endl;
    else if (cerne == 0) std::cout << "Vyhral hrac. Gratuluji." << endl;
    else std::cout << "Hra skoncila remizou." << endl;
    return 1;
}

int gameSimulationLoop() {
    zakladniPoziceHracihoPole();
    do {
        vector<string> tahy = mozneTahy(hraciPole, aktualniHrac);

        if (tahy.size()==0) {
            (aktualniHrac==0?bile=0:cerne=0);
            break;
        }
        
        string tah;
        if (aktualniHrac == 0) {
            int n = rand()%tahy.size();
            tah = tahy[n];
        } else {
            hracVSimulaci = aktualniHrac;
            vector<string> nejlepsiTahy = nejlepsiTahyVPozici(hraciPole, 1);
            int n = rand()%nejlepsiTahy.size();
            tah = nejlepsiTahy[n];
        }

        if ((tah[0]-'A'+tah[1]-'1')%2!=0)  {
            std::cout << "Neplatna pozice. ";
            return -1;
        }

        bool platnyTah = pohyb(tah, tahy, hraciPole, aktualniHrac);
        if (platnyTah) aktualniHrac = (aktualniHrac?0:1);
        
        for (int i=0;i<8;i++) {
            if (hraciPole[0][i].figura=='o') hraciPole[0][i].dama=1;
        }
        for (int i=0;i<8;i++) {
            if (hraciPole[7][i].figura=='x') hraciPole[7][i].dama=1;
        }
        
        pocetFigur(hraciPole);
        
    } while (bile > 0 && cerne > 0);
    if (cerne==0) return 1;
    else if (bile==0) return 2;
    return 1;
}

void simulaceHer(int hry) {
    int pocetSimulaci = hry; 

    time_t zacatek = time(0);
    srand(time(0));
    int platneHry = 0;
    int vyhryHrac = 0;
    int vyhryAlgoritmus = 0;

    int procenta, predeslaProcenta;
    string reset(104, '\b');

    for (int i=0;i<pocetSimulaci;i++) {
        int vysledek = gameSimulationLoop();
        if (vysledek==1) vyhryHrac++;
        else if (vysledek==2) vyhryAlgoritmus++;
        procenta = i/float(pocetSimulaci/100);
        if (procenta!=predeslaProcenta) {
            string pomlcky(procenta, '-');
            string tecky(100-procenta, '.');
            std::cout << reset << pomlcky << tecky << ' ' << procenta << " %";
        }
        predeslaProcenta = procenta;
    }
    string hotovo(100, '-');
    std::cout << reset << hotovo << " 100 %" << endl;
    platneHry = vyhryAlgoritmus + vyhryHrac;
    time_t konec = time(0);
    std::cout << konec - zacatek<< " s" << endl;
    std::cout << "Vyhry hrace: " << vyhryHrac << endl << "Vyhry algoritmu: " << vyhryAlgoritmus << endl << platneHry << endl;
}

int main() {

    /*
    srand(time(0));
    std::cout << "Vitejte. Chcete hrat proti algoritmu (1), nebo nechat algoritmy hrat proti sobe (2)? ";
    int volba;
    cin >> volba;
    if (volba==1) gameLoop();
    else if (volba==2) {
        std::cout << "Kolik her chcete simulovat? ";
        int pocetHer;
        cin >> pocetHer;
        std::cout << "Zacatek simulace";
        simulaceHer(pocetHer);
    };
    */
    hraciPole[0][0].figura = 'x';
    hraciPole[0][0].dama = 1;
    vypsatHraciPole();
    cout << "Program skoncil. ";
    
    return 1;
}