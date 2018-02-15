#include "stdafx.h"
#include "ProduktStrukturyzowany.h"


ProduktStrukturyzowany::ProduktStrukturyzowany()
{
}

ProduktStrukturyzowany::ProduktStrukturyzowany(double n, string s) :SkladnikAktywow(n,s)
{
	idKlasy = 4;
}


ProduktStrukturyzowany::~ProduktStrukturyzowany()
{
}

double ProduktStrukturyzowany::getKwota()
{
	return kwota;
}

void ProduktStrukturyzowany::setKwota(double n)
{
	kwota = n;
}

string ProduktStrukturyzowany::getNazwa()
{
	return nazwa;
}

void ProduktStrukturyzowany::setNazwa(string n)
{
	nazwa = n;
}

int ProduktStrukturyzowany::getIdKlasy()
{
	return idKlasy;
}

void ProduktStrukturyzowany::setIdKlasy(int n)
{
	idKlasy = n;
}

string ProduktStrukturyzowany::info()
{
	return "Produkt strukturyzowany " + nazwa;
}

double ProduktStrukturyzowany::getSzansaNaZysk()
{
	return szansaNaZysk;
}

void ProduktStrukturyzowany::setSzansaNaZysk(double n)
{
	szansaNaZysk = n;
}

double ProduktStrukturyzowany::getProcentZysku()
{
	return procentZysku;
}

void ProduktStrukturyzowany::setProcentZysku(double n)
{
	procentZysku = n;
}
