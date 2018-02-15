#include "stdafx.h"
#include "Skarpeta.h"


Skarpeta::Skarpeta()
{
}

Skarpeta::Skarpeta(double n, string s) :SkladnikAktywow(n,s)
{
	idKlasy = 5;
}


Skarpeta::~Skarpeta()
{
}

double Skarpeta::getKwota()
{
	return kwota;
}

void Skarpeta::setKwota(double n)
{
	kwota = n;
}

string Skarpeta::getNazwa()
{
	return nazwa;
}

void Skarpeta::setNazwa(string s)
{
	nazwa = s;
}

int Skarpeta::getIdKlasy()
{
	return idKlasy;
}

void Skarpeta::setIdKlasy(int n)
{
	idKlasy = n;
}

string Skarpeta::info()
{
	return "Skarpeta "+nazwa;
}

double Skarpeta::getWplata()
{
	return wplata;
}

void Skarpeta::setWplata(double n)
{
	wplata = n;
}
