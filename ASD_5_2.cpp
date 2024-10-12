#include <iostream>
#include <vector>
using namespace std;

void scal(vector<vector<double>>& dane, int lewy, int srodek, int prawy, int kolumnaSort) {
    int n1 = srodek - lewy + 1;
    int n2 = prawy - srodek;

    vector<vector<double>> L(n1), P(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = dane[lewy + i];
    }
    for (int j = 0; j < n2; j++) {
        P[j] = dane[srodek + 1 + j];
    }

    int i = 0, j = 0, k = lewy;

    while (i < n1 && j < n2) {
        if (L[i][kolumnaSort] <= P[j][kolumnaSort]) {
            dane[k] = L[i];
            i++;
        } else {
            dane[k] = P[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        dane[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        dane[k] = P[j];
        j++;
        k++;
    }
}

void mergeSort(vector<vector<double>>& dane, int lewy, int prawy, int kolumnaSort) {
    if (lewy >= prawy) return;

    int srodek = lewy + (prawy - lewy) / 2;
    mergeSort(dane, lewy, srodek, kolumnaSort);
    mergeSort(dane, srodek + 1, prawy, kolumnaSort);
    scal(dane, lewy, srodek, prawy, kolumnaSort);
}

void wczytajDane(vector<vector<double>>& dane, vector<int>& listaKolumn, int& n) {
    int m;
    cin >> n >> m;
    listaKolumn.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> listaKolumn[i];
        listaKolumn[i] -= 1;
    }

    vector<double> wiersz(n);
    while (cin) {
        for (int i = 0; i < n; i++) {
            if (!(cin >> wiersz[i])) {
                return;
            }
        }
        dane.push_back(wiersz);
    }
}

void wypiszWynik(const vector<vector<double>>& dane) {
    for (int i = 0; i < dane.size(); i++) {
        for (int j = 0; j < dane[i].size(); j++) {
            double liczba = dane[i][j];
            if (liczba == static_cast<int>(liczba)) {
                cout << static_cast<int>(liczba) << " ";
            } else {
                cout << liczba << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    vector<vector<double>> dane;
    vector<int> listaKolumn;

    wczytajDane(dane, listaKolumn, n);

    for (int i = 0; i < listaKolumn.size(); i++) {
        mergeSort(dane, 0, dane.size() - 1, listaKolumn[i]);
    }

    wypiszWynik(dane);

    return 0;
}
