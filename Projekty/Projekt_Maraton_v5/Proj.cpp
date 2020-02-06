#include "Proj.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool odczytaj_argumenty(int ile, char** argumenty, string& szInput)
{
	const string ETYKIETA_INPUT("-i");
	const int    FLAGA_INPUT = 1;
	const int    POPRAWNY_WYNIK = FLAGA_INPUT;
	int wynik = 0;

	for (int i = 1; i < ile - 1; i++)
	{
		string arg(argumenty[i]);
		if (arg == ETYKIETA_INPUT)
		{
			szInput = argumenty[i + 1];
			wynik |= FLAGA_INPUT;
		}
	}

	if (wynik == POPRAWNY_WYNIK)
		return true;
	else
		return false;
}

Zawodnik* dodajZawodnika(Zawodnik*& root, string& Nazwisko) // dodawanie nowego wêz³a
{
	if (!root)
	{
		root = new Zawodnik{ Nazwisko, nullptr, nullptr,nullptr };
		return root;
	}
	if (root->nazwisko == Nazwisko)
		return root;
	if (Nazwisko < root->nazwisko)
		return dodajZawodnika(root->lewy, Nazwisko);
	else
		return dodajZawodnika(root->prawy, Nazwisko);
}

void dodajWynik(Wynik*& head, const string& data, const string& NazwaZ, const string& czas) // dodawanie wraz z posortowaniem nowych elementów listy
{
	if (!head || data >= head->data)
	{
		head = new Wynik{ data, NazwaZ,czas, head };
		return;
	}
	Wynik* tmp = head;
	while (tmp->Next && tmp->Next->data > data)
	{
		tmp = tmp->Next;
	}

	tmp->Next = new Wynik{ data, NazwaZ,czas, tmp->Next };
}

int ileWezlow(Zawodnik* node)
{
	if (node == NULL)
		return 0;
	else
		return(ileWezlow(node->lewy) + 1 + ileWezlow(node->prawy));
}

void utworzPliki(Zawodnik* root, Wynik*& head, ofstream& OutFile)
{
	if (root != nullptr)
	{
		utworzPliki(root->prawy, root->head, OutFile);
		OutFile.open(root->nazwisko);
		cout << root->nazwisko << " otwarty" << endl;
		OutFile << root->nazwisko << endl << endl;
		do
		{
			cout << "Nazwisko " << root->nazwisko << endl;

			if (!OutFile.is_open())
			{
				cout << "Problem z otwarciem pliku";
				exit(1);
			}												// dobrze chyba do tego miejsca
			while (root)
			{
				OutFile << head->data << "  " << head->NazwaZ << "  " << head->czas << endl;
				cout << "czas " << head->czas << endl;
				head = head->Next;
			}

		} while (root != nullptr);
		cout << "do zamkniecia" << endl;
		OutFile.close();
		utworzPliki(root->lewy, root->head, OutFile);
	}
}

void usunListy(Zawodnik*& root)
{
	while (root)
	{
		usunListy(root->lewy);
		usunListy(root->prawy);
		Wynik* tmp = root->head->Next;
		delete root->head;
		root->head = tmp;
	}
}

bool usunDrzewo(Zawodnik*& root)
{
	if (root)
	{
		usunDrzewo(root->lewy);
		usunDrzewo(root->prawy);
		delete root;
		return 0;
	}
		return 0;
}