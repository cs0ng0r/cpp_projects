#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int main()
{
	// Guess the word game

	string words[15] = { "fuvola", "csirke", "adatok", "asztal", "fogoly",  "bicska", "farkas", "almafa", "babona", "gerinc",  "dervis", "bagoly", "ecetes", "angyal", "boglya" };

	// Seed the random number generator
	srand(static_cast<unsigned int>(time(0)));

	// Generate a random index to select a word
	int randomIndex = rand() % 15;
	string word = words[randomIndex];

	string talalatok(word.length(), '.'); // Initialize with dots

	while (word != talalatok)
	{
		cout << "A szo: " << word << endl;
		cout << "Talalatok: " << talalatok << endl;
		cout << "Adj meg egy szot: ";
		string inputWord;
		cin >> inputWord;

		

		bool talalt = true;
		for (int i = 0; i < word.size(); i++)
		{
			bool karakterTalalat = false;
			for (int j = 0; j < inputWord.size(); j++)
			{
				if (word[i] == inputWord[j])
				{
					karakterTalalat = true;
					break;
				}
			}
			if (!karakterTalalat)
			{
				talalt = false;
				break;
			}
		}
		if (talalt)
		{
			talalatok = inputWord;
			break;
		}
		else
		{
			cout << "A megadott szo nem tartalmazza az eredeti szo betuit!" << endl;
		}
	}

	if (word == talalatok)
	{
		cout << "Gratulalok, nyertel! A szo: " << talalatok << " volt" << endl;
	}
	else
	{
		cout << "Sajnalom, vesztettel, nem találtad ki a szót! A helyes szó: " << word << endl;
	}

	return 0;
}
