// feldobasok.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int dob;
	cout << "Add meg a dobasok szamat: ";
	cin >> dob;

	// Végezzen N feldobást a három kockával úgy, hogy minden feldobásnál generál három véletlenszámot 1 és 6 között!
	//Figyeljen arra, hogy a program futtatása során ne mindig ugyanazt a véletlenszám - sorozatot kapja!

	srand(time(0));
	for (int i = 0; i < dob; i++) {
		int k1 = rand() % 6 + 1;
		int k2 = rand() % 6 + 1;
		int k3 = rand() % 6 + 1;
	}

	// Minden feldobás után írja ki a kockán lévõ számokat, valamint azok összegét, és azt is, hogy ki nyert.A kiírás egy sorban történjen,
	// és a következõ formátumban jelenjen meg : "Dobás: 4 + 1 + 2 = 7 Nyert: Dobás: 4 + 1 + 2 = 7 Nyert: Anni

	int j1 = 0;
	int j2 = 0;


	for (int i = 0; i < dob; i++) {
		int k1 = rand() % 6 + 1;
		int k2 = rand() % 6 + 1;
		int k3 = rand() % 6 + 1;
		int osszeg = k1 + k2 + k3;
		cout << "Dobas: " << k1 << " + " << k2 << " + " << k3 << " = " << osszeg << " Nyert: ";
		if (osszeg >= 10) {
			cout << "Panni" << endl;
			j1++;
		}
		else {
			cout << "Anni" << endl;
			j2++;
		}
	}

	// A feldobások után egy mondatban írja ki, hogy hány alkalommal kedvezett az egyik, és hány alkalommal a másik játékosnak a szerencse!

	cout << "Panni nyert: " << j1 << " alkalommal, Anni pedig " << j2 << " alkalommal nyert." << endl;

	return 0;
}
