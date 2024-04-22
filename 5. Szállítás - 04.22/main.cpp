#include <iostream>

using namespace std;


int main()
{
    int tomeg[15] = {16, 8, 9, 4, 3, 2, 4, 7, 7, 12, 3, 5, 4, 3, 2};
    int osszTomeg = 0;
    for (int i = 0; i < 15; i++)
    {
        osszTomeg += tomeg[i];
    }

    // 2. feladat: Össztömeg kiírása
    cout << "2. feladat: A targyak tomegenek osszege: " << osszTomeg << " kg" << endl;

    // 3. feladat: Dobozok számának és tömegének kiszámítása (20 kg max 1 dobozban, ha több, akkor új dobozba kell tenni)

    int dobozWeight[5] = {0, 0, 0, 0, 0};
    int osszDoboz = 0;
    int db = 0;
    for(int i = 0; i < 15; i++)
    {
        if(dobozWeight[osszDoboz] + tomeg[i] <= 20)
        {
            dobozWeight[osszDoboz] += tomeg[i];
        }
        else
        {
            osszDoboz++;
            dobozWeight[osszDoboz] += tomeg[i];
        }
    }
    

    // 3. feladat: Dobozok tartalmának kiírása
    cout << "3. feladat: Dobozok tartalmanak kiirasa (kg): ";
    for (int i = 0; i <= osszDoboz; i++)
    {
        cout << dobozWeight[i] << "";
        if (i != osszDoboz)
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "4. feladat: A dobozok szama: " << osszDoboz + 1 << endl;
    return 0;
}
