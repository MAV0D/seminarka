#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct figura {
    char pole = '.';
    char X;
    int Y;
    bool dama = 0;
};

figura pole[8][8];
bool hrac=0;                    // 0 - bílá, 1 - černá
int bile, cerne, soucetFigur;

void vypsatPole() {             // vypíše pole do terminálu s tečkami jako prázdnými poli a O/X jako kameny
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++)
            cout << pole[i][j].pole << ' ';
        cout << endl;
        }
}

void zakladniPozice() {         // nastaví hru do základní pozice o 12 kamenech pro každou stranu
    for (int i=0;i<3;i++) {
        for (int j=0;j<8;j++) {
            if (!((i+j)%2)) {
                pole[i][j].pole = 'x';
            }
        }
    }
    for (int i=5;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (!((i+j)%2)) {
                pole[i][j].pole = 'o';
            }
        }
    }
}

vector<string> mozneTahy() {            // zjistí všechny možné tahy v pozici a vrítí je formou vectoru stringů
    vector<string> mozneTahy;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (pole[i][j].dama==0) {
                if (pole[i][j].pole=='x' && hrac == 0) {
                    if (pole[i+1][j-1].pole=='.') {
                        char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                        char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                        char tahX = i + 1 + 'A';    // přičítá 1 - zjištění dalšího tahu
                        char tahY = j - 1 + '1';    
                        if((i+1) <= 7 && (j-1) >= 0) {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                        }
                    } else if (pole[i+1][j-1].pole=='o' && pole[i+2][j-2].pole=='.') {
                        char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                        char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                        char tahX = i + 1 + 'A';    // přičítá 1 - zjištění dalšího tahu
                        char tahY = j - 1 + '1';    
                        if((i+1) <= 7 && (j-1) >= 0) {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                        }
                    }
                    if (pole[i+1][j+1].pole=='.') {
                        char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                        char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                        char tahX = i + 1 + 'A';    // přičítá 1 - zjištění dalšího tahu
                        char tahY = j + 1 + '1';    
                        if((i+1) <= 7 && (j+1) <= 7) {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                        }
                    } else if (pole[i+1][j+1].pole=='o' && pole[i+2][j+2].pole=='.') {
                        char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                        char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                        char tahX = i + 1 + 'A';    // přičítá 1 - zjištění dalšího tahu
                        char tahY = j + 1 + '1';    
                        if((i+1) <= 7 && (j+1) <= 7) {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                        }
                    }
                }
                if (pole[i][j].pole=='o' && hrac == 1) {
                    if (pole[i-1][j-1].pole=='.') {
                        char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                        char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                        char tahX = i - 1 + 'A';    // přičítá 1 - zjištění dalšího tahu
                        char tahY = j - 1 + '1';    
                        if((i-1) >= 0 && (j-1) >= 0) {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                        }
                    } else if (pole[i-1][j-1].pole=='x' && pole[i-2][j-2].pole=='.') {
                        char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                        char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                        char tahX = i - 1 + 'A';    // přičítá 1 - zjištění dalšího tahu
                        char tahY = j - 1 + '1';
                        if((i-1) >= 0 && (j-1) >= 0) {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                        }
                    }
                    if (pole[i-1][j+1].pole=='.') {
                        char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                        char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                        char tahX = i - 1 + 'A';    // přičítá 1 - zjištění dalšího tahu
                        char tahY = j + 1 + '1';    
                        if((i-1) >= 0 && (j+1) <= 7) {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                        }
                    } else if (pole[i-1][j+1].pole=='x' && pole[i-2][j+2].pole=='.') {
                        char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                        char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                        char tahX = i - 1 + 'A';    // přičítá 1 - zjištění dalšího tahu
                        char tahY = j + 1 + '1';
                        if((i-1) >= 0 && (j+1) <= 7) {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                        }
                    }
                }
            } else {
                if (hrac==0 && pole[i][j].pole=='x') {
                    char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                    char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                    char tahX = i + 1 + 'A';
                    char tahY = j + 1 + '1';
                    bool preskoceno = 0;
                    while (tahX<='H' && tahY<='8') {
                        if (pole[tahX-'A'][tahY-'1'].pole=='o') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].pole=='x') break;
                        else {
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
                        if (pole[tahX-'A'][tahY-'1'].pole=='o') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].pole=='x') break;
                        else {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX++;
                            tahY--;
                        }
                    }
                    tahX = i - 1 + 'A';
                    tahY = j - 1 + '1';
                    preskoceno = 0;
                    while (tahX>='A' && tahY>='0') {
                        if (pole[tahX-'A'][tahY-'1'].pole=='o') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].pole=='x') break;
                        else {
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
                        if (pole[tahX-'A'][tahY-'1'].pole=='o') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].pole=='x') break;
                        else {
                            string tah = string(1, puvodX)+puvodY+tahX+tahY;
                            mozneTahy.push_back(tah);
                            tahX--;
                            tahY++;
                        }
                    }
                } else {

                }
            }
        }
    }
    return mozneTahy;
}

bool moznyTah(string tah)  {                // ověří, zda je zadaný tah platný, pokud ano, provede ho a vrátí 1
    bool moznyTah;
    if (tah.size()==4) {
        int puvodX = tah[0] - 'A';
        int puvodY = tah[1]- '0' - 1;
        int tahX = tah[2] - 'A';
        int tahY = tah[3] - '0' - 1;
        
        if (pole[puvodX][puvodY].pole=='.') moznyTah = 0;
        else if (pole[puvodX][puvodY].pole=='x' && hrac == 0) {
            if (pole[tahX][tahY].pole!='x' && tahX-puvodX==1 && abs(puvodY-tahY)==1 ) {
                if (pole[tahX][tahY].pole=='.') {
                    pole[tahX][tahY].pole = pole[puvodX][puvodY].pole;
                } else {
                    pole[tahX][tahY].pole = '.';
                    pole[tahX+(tahX-puvodX)][tahY+(tahY-puvodY)].pole = pole[puvodX][puvodY].pole;
                }
                pole[puvodX][puvodY].pole = '.';
                hrac = 1;
                moznyTah = 1;
            }
        } else if (pole[puvodX][puvodY].pole=='o' && hrac == 1) {
            if (pole[tahX][tahY].pole!='o' && puvodX-tahX==1 && abs(puvodY-tahY)==1) {
                if (pole[tahX][tahY].pole=='.') {
                    pole[tahX][tahY].pole = pole[puvodX][puvodY].pole;
                    pole[puvodX][puvodY].pole = '.';
                    hrac = (hrac ? 0:1);
                    moznyTah = 1;
                } else if (pole[tahX+(tahX-puvodX)][tahY+(tahY-puvodY)].pole=='.') {
                    pole[tahX][tahY].pole = '.';
                    pole[tahX+(tahX-puvodX)][tahY+(tahY-puvodY)].pole = pole[puvodX][puvodY].pole;
                    pole[puvodX][puvodY].pole = '.';
                    hrac = 0;
                    moznyTah = 1;
                } else {
                    moznyTah = 0;
                }
            }
        } else moznyTah = 0;
    } else {
        moznyTah = 0;
    }
    return moznyTah;
}

int pohyb(string tah, vector<string> mozneTahy) {
    for (int i=0;i<mozneTahy.size();i++) {
        if (tah==mozneTahy[i]) {
            int puvodX = tah[0] - 'A';
            int puvodY = tah[1]- '0' - 1;
            int tahX = tah[2] - 'A';
            int tahY = tah[3] - '0' - 1;
            pole[tahX][tahY].pole = pole[puvodX][puvodY].pole; // malý posun při braní
            pole[puvodX][puvodY].pole = '.';
            if (abs(puvodX-tahX)>1) {
                for (int j=1;j<abs(puvodX-tahX);j++) {
                    if (pole[puvodX+j][puvodY+j].pole=='.') continue;
                    if (pole[puvodX+j][puvodY+j].pole!=pole[puvodX][puvodY].pole) pole[puvodX+j][puvodY+j].pole = '.';
                }
            }
            hrac = (hrac?0:1);
            return 1;
        }
    }
    cout << "Neplatný tah, hrajte znovu.";
    return 0;
}

void pocetFigur() {
    bile = 0;
    cerne = 0;
    soucetFigur = 0;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (pole[i][j].pole != '.' && pole[i][j].dama==0) {
                if (pole[i][j].pole == 'x') bile++;
                else cerne++;
                soucetFigur = bile + cerne;
            }
        }
    }
}


int main() {
    srand(time(0));
    zakladniPozice();
    do {
        vector<string> tahy = mozneTahy();
        if (hrac==0)
            for (int i=0;i<tahy.size();i++) {
                cout << tahy[i] << "   ";
            }
        cout << endl;
        vypsatPole();
        string tah;
        if (hrac==0) cin >> tah;
        else {
            int n = rand()%tahy.size();
            tah = tahy[n];
            cout << tah << endl;
        }

        pohyb(tah, tahy);
        
        for (int i=0;i<8;i++) {
            for (int j=0;j<8;j++) {
                if ((pole[i][j].X=='H' && pole[i][j].pole=='x') || (pole[i][j].X=='A' && pole[i][j].pole=='o')) {
                    pole[i][j].dama=1;
                }
            }
        }
        pocetFigur();
        if (tahy.size()==0) {
            (hrac==0?bile=0:cerne=0);
        }
    } while (soucetFigur > 0 && bile > 0 && cerne > 0);
    if (bile == 0) cout << "Vyhrál černý. Gratuluji.";
    else if (cerne == 0) cout << "Vyhral bílý. Gratuluji.";
    else cout << "Hra skončila remízou. ";
    return 1;
}