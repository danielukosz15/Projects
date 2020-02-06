#ifndef Proj
#define Proj
#include <string>

using namespace std;

struct Wynik // elem. listy
{
	string data;
	string NazwaZ;
	string czas;
	Wynik* Next;
};

struct Zawodnik // wezel
{
	string nazwisko;
	Zawodnik* lewy, * prawy;
	Wynik* head;
};

Zawodnik* dodajZawodnika(Zawodnik*& root, string& Nazwisko);
void dodajWynik(Wynik*& head, const string& data, const string& NazwaZ, const string& czas);
bool odczytaj_argumenty(int ile, char** argumenty, string& szInput);
void usunListy(Zawodnik*& root);
bool usunDrzewo(Zawodnik*& root);
int ileWezlow(Zawodnik* node);
void utworzPliki(Zawodnik* root, Wynik*& head, ofstream& OutFile);

#endif