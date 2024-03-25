#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 1. Feladat: Beolvasás a felhasználótól
    int hetek_szama;
    double elert_cel;
    cout << "Adja meg a fogyokura hetek szamat: ";
    cin >> hetek_szama;
    cout << "Adja meg a celul tuzott testtomeget (kg-ban): ";
    cin >> elert_cel;

    // 2. Feladat: Adatok tárolása
    vector<double> tomegek(hetek_szama);
    cout << "Adja meg Mari neni tomeget a fogyokura hetekben:\n";
    for (int i = 0; i < hetek_szama; ++i) {
        cout << i + 1 << ". heten: ";
        cin >> tomegek[i];
    }

    // 3. Feladat: Cél elérése
    bool elerte_celt = false;
    int elso_cel_het = -1;
    for (int i = 0; i < hetek_szama; ++i) {
        if (tomegek[i] <= elert_cel) {
            elerte_celt = true;
            elso_cel_het = i + 1;
            break;
        }
    }
    if (elerte_celt) {
        cout << "Mari neni a(z) " << elso_cel_het << ". heten erte el a celul tuzott testtomeget.\n";
    }
    else {
        cout << "Sajnos Mari neni nem erte el a celjat.\n";
    }

    // 4. Feladat: Tömegnövekedés számlálása
    int novekedesek_szama = 0;
    for (int i = 1; i < hetek_szama; ++i) {
        if (tomegek[i] > tomegek[i - 1]) {
            ++novekedesek_szama;
        }
    }
    cout << "A tomege " << novekedesek_szama << " esetben nott egyik hetrol a masikra.\n";

    return 0;
}
