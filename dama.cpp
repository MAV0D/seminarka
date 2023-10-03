#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

struct pole {
    char pole = '.';
    bool dama = 0;
};

pole hraciPole[8][8];
pole simulacniPole[8][8];
bool aktualniHrac=0;                    // 0 - bílá, 1 - černá
bool hracVSimulaci=0;
int bile, cerne;

void vypsatHraciPole() {        // vypíše pole do terminálu s tečkami jako prázdnými poli a O/X jako kameny
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++)
            std::cout << hraciPole[i][j].pole << ' ';
        std::cout << endl;
        }
}

void zakladniPoziceHracihoPole() {         // nastaví hru do základní pozice o 12 kamenech pro každou stranu
    for (int i=0;i<3;i++) {
        for (int j=0;j<8;j++) {
            if (!((i+j)%2)) {
                hraciPole[i][j].pole = 'x';
            }
        }
    }
    for (int i=5;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (!((i+j)%2)) {
                hraciPole[i][j].pole = 'o';
            }
        }
    }
}

vector<string> mozneTahy(pole pole[8][8], bool hrac) {            // zjistí všechny možné tahy v pozici a vrítí je formou vectoru stringů
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
                if (pole[i][j].pole=='x' && hrac==0) {
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
                } else if (pole[i][j].pole=='o' && hrac==1) {
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

bool pohyb(string tah, vector<string> mozneTahy, figura pole[8][8]) {
bool pohyb(string tah, vector<string> mozneTahy, pole pole[8][8]) {
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
            pole[puvodX][puvodY].dama = 0;
            if (abs(puvodX-tahX)>1) {
                int nasX, nasY;             // nasobice pohybu (smeru nahoru/dolu)
                nasX = (puvodX-tahX>0) ? -1 : 1;
                nasY = (puvodY-tahY>0) ? -1 : 1;
                for (int j=1;j<abs(puvodX-tahX);j++) {
                    if (pole[puvodX+j*nasX][puvodY+j*nasY].pole=='.') continue;
                    if (pole[puvodX+j*nasX][puvodY+j*nasY].pole!=pole[puvodX][puvodY].pole) pole[puvodX+j*nasX][puvodY+j*nasY].pole = '.';
                }
            }
            return 1;
        }
    }
    std::cout << "Neplatný tah, hrajte znovu." << endl;
    return 0;
}

void pocetFigur(figura pole[8][8]) {
void pocetFigur(pole pole[8][8]) {
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

float vyhodaVPozici(pole pole[8][8]) {
    float vyhoda = 0.0;
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            float vyhodaZPole = 0.0;
            if (pole[i][j].pole=='x' && !pole[i][j].dama) {
                vyhodaZPole = 1 + 0.1 * (i+1);
            } else if (pole[i][j].pole=='x' && pole[i][j].dama) {
                vyhodaZPole = 3;
            } else if (pole[i][j].pole=='o' && !pole[i][j].dama) {
                vyhodaZPole = -(1 + 0.1 * (7-i+1));
            } else if (pole[i][j].pole=='o' && pole[i][j].dama) {
                vyhodaZPole = -3;
            }
            vyhodaZPole = round(vyhodaZPole*10)/10.0;
            vyhoda += vyhodaZPole;
        }
    }
    return vyhoda;
}

vector<string> nejlepsiTahyVPozici(figura pole[8][8]) {
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

        bool platnyPohyb = pohyb(tah, tahy, simulacniPole);
        if (platnyPohyb) hracVSimulaci = hracVSimulaci ? 0 : 1;

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

        if (aktualniHrac==0) {
            float vyhoda = vyhodaVPozici(hraciPole);
            std::cout << fixed << setprecision(1) << vyhoda << endl;
            for (string tah : tahy) 
                std::cout << tah << "   ";    
            std::cout << endl;
        }
        vypsatHraciPole();
        
        string tah;
        if (aktualniHrac==0)
            std::cin >> tah;
        else 
        {
            hracVSimulaci = aktualniHrac;
            vector<string> nejlepsiTahy = nejlepsiTahyVPozici(hraciPole, 1);
            int n = rand()%nejlepsiTahy.size();
            tah = nejlepsiTahy[n];
            std::cout << tah << endl;
        }
        if (tah=="REMIZA") {
            std::cout << "Hra skončila remízou. ";
            return 0;
        }

        bool platnyTah = pohyb(tah, tahy, hraciPole);
        if (platnyTah) aktualniHrac = (aktualniHrac?0:1);
        
        for (int i=0;i<8;i++) {
            if (hraciPole[0][i].pole=='o') hraciPole[0][i].dama=1;
            if (hraciPole[7][i].pole=='x') hraciPole[7][i].dama=1;
        }
        
        pocetFigur(hraciPole);
        
    } while (bile > 0 && cerne > 0);
    vypsatHraciPole();
    if (bile == 0) std::cout << "Vyhrál algoritmus." << endl;
    else if (cerne == 0) std::cout << "Vyhral hráč. Gratuluji." << endl;
    else std::cout << "Hra skončila remízou." << endl;
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
        int n = rand()%tahy.size();
        tah = tahy[n];

        if ((tah[0]-'A'+tah[1]-'1')%2!=0)  {
            std::cout << "Neplatná pozice. ";
            return -1;
        }

        bool platnyTah = pohyb(tah, tahy, hraciPole);
        if (platnyTah) aktualniHrac = (aktualniHrac?0:1);
        
        for (int i=0;i<8;i++) {
            if (hraciPole[0][i].pole=='o') hraciPole[0][i].dama=1;
        }
        for (int i=0;i<8;i++) {
            if (hraciPole[7][i].pole=='x') hraciPole[7][i].dama=1;
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
            std::cout << reset << pomlcky << tecky << ' ' << procenta << '%';
        }
        predeslaProcenta = procenta;
    }
    string hotovo(100, '-');
    std::cout << reset << hotovo << " 100%" << endl;
    platneHry = vyhryAlgoritmus + vyhryHrac;
    time_t konec = time(0);
    std::cout << konec - zacatek<< " s" << endl;
    std::cout << "Výhry hráče: " << vyhryHrac << endl << "Výhry algoritmu: " << vyhryAlgoritmus << endl << platneHry << endl;
}

int main() {
    srand(time(0));
    std::cout << "Vítejte. Chcete hrát proti algoritmu (1), nebo nechat algoritmy hrát proti sobě (2)? ";
    int volba;
    cin >> volba;
    if (volba==1) gameLoop();
    else if (volba==2) {
        std::cout << "Kolik her chcete simulovat? ";
        int pocetHer;
        cin >> pocetHer;
        std::cout << "Začátek simulace";
        simulaceHer(pocetHer);
    }
    cout << "Program skončil. ";
    return 1;
}