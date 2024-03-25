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

	// V�gezzen N feldob�st a h�rom kock�val �gy, hogy minden feldob�sn�l gener�l h�rom v�letlensz�mot 1 �s 6 k�z�tt!
	//Figyeljen arra, hogy a program futtat�sa sor�n ne mindig ugyanazt a v�letlensz�m - sorozatot kapja!

	srand(time(0));
	for (int i = 0; i < dob; i++) {
		int k1 = rand() % 6 + 1;
		int k2 = rand() % 6 + 1;
		int k3 = rand() % 6 + 1;
	}

	// Minden feldob�s ut�n �rja ki a kock�n l�v� sz�mokat, valamint azok �sszeg�t, �s azt is, hogy ki nyert.A ki�r�s egy sorban t�rt�njen,
	// �s a k�vetkez� form�tumban jelenjen meg : "Dob�s: 4 + 1 + 2 = 7 Nyert: Dob�s: 4 + 1 + 2 = 7 Nyert: Anni

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

	// A feldob�sok ut�n egy mondatban �rja ki, hogy h�ny alkalommal kedvezett az egyik, �s h�ny alkalommal a m�sik j�t�kosnak a szerencse!

	cout << "Panni nyert: " << j1 << " alkalommal, Anni pedig " << j2 << " alkalommal nyert." << endl;

	return 0;
}
