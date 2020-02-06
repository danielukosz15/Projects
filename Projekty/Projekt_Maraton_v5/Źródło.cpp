#include "Proj.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv, string& szInput)
{
	odczytaj_argumenty(argc, argv, szInput);

	Zawodnik* root = nullptr;
	string data, NazwaZ, nazwisko, czas, pozycja, numer;
	/*string* data_W, * NazwaZ_W, * nazwisko_W, * czas_W, * pozycja_W, * numer_W;
	data_W = &data; NazwaZ_W = &NazwaZ; nazwisko_W = &nazwisko;  czas_W = &czas;*/

	for (int i = 2; i <= (argc - 1); i++)
	{
		ifstream InFile;
		InFile.open(argv[i]);

		if (!InFile.is_open())
		{
			cout << "error" << endl;
			return 1;
		}

		//Odczyt z pliku
		getline(InFile, NazwaZ); // I Linia -> nazwa maratonu
		getline(InFile, data);	// II Linia -> data maratonu
	
		while (!InFile.eof())
		{
			getline(InFile, pozycja, ','); InFile.ignore();
			getline(InFile, nazwisko, ','); InFile.ignore();
			getline(InFile, numer, ','); InFile.ignore();
			getline(InFile, czas); //Koniec odczytu

			dodajZawodnika(root, nazwisko); // dodanie wezla
			dodajWynik(root->head, data, NazwaZ, czas); // dodanie wynikow do wezla

		};
		InFile.close();
	};
	int ileWezlow(Zawodnik * node);
			cout << "Ilosc wezlow: " << ileWezlow(root) << endl;

	ofstream Plik;
	utworzPliki(root,root->head,Plik);

	usunListy(root);
	usunDrzewo(root);
}

