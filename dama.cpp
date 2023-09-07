#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct figura {
    char pole = '.';
    bool dama = 0;
};

figura pole[8][8];
bool hrac=0;                    // 0 - bílá, 1 - černá
int bile, cerne;

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
                        if((i+2) <= 7 && (j-2) >= 0) {
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
                        if((i+2) <= 7 && (j+2) <= 7) {
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
                        if((i-2) >= 0 && (j-2) >= 0) {
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
                        if((i-2) >= 0 && (j+2) <= 7) {
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
                                tahY--;
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
                    while (tahX>='A' && tahY>='1') {
                        if (pole[tahX-'A'][tahY-'1'].pole=='o') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX--;
                                tahY--;
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
                                tahX--;
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
                    char puvodX = i + 'A';      // přičítá 'A' aby bylo písmeno
                    char puvodY = j + '1';      // přičítá '1' aby bylo číslo v rozmezí 1-8
                    char tahX = i + 1 + 'A';
                    char tahY = j + 1 + '1';
                    bool preskoceno = 0;
                    while (tahX<='H' && tahY<='8') {
                        if (pole[tahX-'A'][tahY-'1'].pole=='x') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].pole=='o') break;
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
                        if (pole[tahX-'A'][tahY-'1'].pole=='x') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX++;
                                tahY--;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].pole=='o') break;
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
                    while (tahX>='A' && tahY>='1') {
                        if (pole[tahX-'A'][tahY-'1'].pole=='x') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX--;
                                tahY--;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].pole=='o') break;
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
                        if (pole[tahX-'A'][tahY-'1'].pole=='x') {
                            if (preskoceno) break;
                            else {
                                preskoceno = 1;
                                tahX--;
                                tahY++;
                            }
                        } else if (pole[tahX-'A'][tahY-'1'].pole=='o') break;
                        else {
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

bool pohyb(string tah, vector<string> mozneTahy) {
    for (int i=0;i<mozneTahy.size();i++) {
        if (tah==mozneTahy[i]) {
            int puvodX = tah[0] - 'A';
            int puvodY = tah[1]- '0' - 1;
            int tahX = tah[2] - 'A';
            int tahY = tah[3] - '0' - 1;
            if (pole[tahX][tahY].pole!='.') {
                int posunX = tahX-puvodX;
                int posunY = tahY-puvodY;
                pole[puvodX+2*posunX][puvodY+2*posunY].pole = pole[puvodX][puvodY].pole;
                pole[puvodX+2*posunX][puvodY+2*posunY].dama = pole[puvodX][puvodY].dama;
                pole[tahX][tahY].pole='.';
                pole[tahX][tahY].dama=0;
            } else {
                pole[tahX][tahY].pole = pole[puvodX][puvodY].pole;
                pole[tahX][tahY].dama = pole[puvodX][puvodY].dama;
            }
            pole[puvodX][puvodY].pole = '.';
            if (abs(puvodX-tahX)>1) {
                int nasX, nasY;
                if (puvodX-tahX>0) nasX=-1;
                else nasX=1;
                if (puvodY-tahY>0) nasY=-1;
                else nasY=1;
                for (int j=1;j<abs(puvodX-tahX);j++) {
                    if (pole[puvodX+j*nasX][puvodY+j*nasY].pole=='.') continue;
                    if (pole[puvodX+j*nasX][puvodY+j*nasY].pole!=pole[puvodX][puvodY].pole) pole[puvodX+j*nasX][puvodY+j*nasY].pole = '.';
                }
            }
            hrac = (hrac?0:1);
            return 1;
        }
    }
    cout << "Neplatný tah, hrajte znovu." << endl;
    return 0;
}

void pocetFigur() {
    bile = 0;
    cerne = 0;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (pole[i][j].pole != '.') {
                if (pole[i][j].pole == 'x') bile++;
                else cerne++;
            }
        }
    }
}


int main() {
    srand(time(0));
    // zakladniPozice();
    pole[4][4].pole='x';
    pole[4][4].dama=1;
    pole[6][6].pole='o';
    pole[2][2].pole='o';
    do {
        vector<string> tahy = mozneTahy();

        if (tahy.size()==0) {
            (hrac==0?bile=0:cerne=0);
            break;
        }

        //if (hrac==0)
            for (int i=0;i<tahy.size();i++) {
                cout << tahy[i] << "   ";
            }
        cout << endl;
        vypsatPole();
        
        string tah;
        //if (hrac==0) 
        cin >> tah;
        // else {
        //     int n = rand()%tahy.size();
        //     tah = tahy[n];
        //     cout << tah << endl;
        // }
        if (tah=="REMIZA") {
            cout << "Hra skončila remízou. ";
            return 1;
        }

        pohyb(tah, tahy);
        
        for (int i=0;i<8;i++) {
            if (pole[0][i].pole=='o') pole[0][i].dama=1;
        }
        for (int i=0;i<8;i++) {
            if (pole[7][i].pole=='x') pole[7][i].dama=1;
        }
        
        pocetFigur();
        
    } while (bile > 0 && cerne > 0);
    vypsatPole();
    if (bile == 0) cout << "Vyhrál algoritmus.";
    else if (cerne == 0) cout << "Vyhral hráč. Gratuluji.";
    else cout << "Hra skončila remízou.";
    return 1;
}