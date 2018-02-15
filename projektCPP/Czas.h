#pragma once
#include <windows.h>
#include "SkladnikAktywow.h"
#include "Lokata.h"
#include "Ike.h"
#include "Nieruchomosc.h"
#include "ProduktStrukturyzowany.h"
#include "Skarpeta.h"
#include "Swinka.h"
#include <vector>
class Czas
{
public:
	Czas();
	~Czas();
	int getMiesiac();
	void setMiesiac(int n);
	int getRok();
	void setRok(int n);
	void dodajMiesiac(vector<SkladnikAktywow*> lista);
	double obliczOszczednosci(vector<SkladnikAktywow*> lista, int n);
private:
	int miesiac;
	int rok;
};

