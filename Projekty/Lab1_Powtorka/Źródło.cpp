#include <iostream>
#include "vector.h"
#include "mystring.h"

using namespace std;

int main()
{
	Vector v1(5, 2, 45);
	Vector v2(16, 4, 1);
	
	cout << "v1= ";
	v1.print();
	cout << "v2= ";
	v2.print();
	float mod = v1.module();
	cout << "Modul v1: " << mod << endl;

	Vector V_suma = add(v1, v2);
	cout << "Suma wektorow: ";
	V_suma.print();

	float V_iloczSka = dot(v1, v2);
	cout << "Iloczyn skalarny wektorow: " << V_iloczSka << endl;

	Vector V_iloczWek = cross(v1, v2);
	cout << "Iloczyn wektorowy wektorow: ";
	V_iloczWek.print();
	
	Vector V_dod = v1 + 10;
	cout << "Dodanie do wektora 10: ";
	V_dod.print();


	
}