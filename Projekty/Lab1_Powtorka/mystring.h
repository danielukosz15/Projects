#pragma once

class MyString
{
	int dl;
	char* tekst;

	MyString() { dl = 4; tekst = new char[dl]; }


	~MyString() { delete[] tekst; }
	MyString(const MyString& other) {
		tekst = new char[dl];
		strcpy(tekst, other.tekst);
	}

};