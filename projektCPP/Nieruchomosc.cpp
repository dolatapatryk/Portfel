#include "stdafx.h"
#include "Nieruchomosc.h"


Nieruchomosc::Nieruchomosc()
{
}

Nieruchomosc::Nieruchomosc(double n, string s, double p) :SkladnikAktywow(n,s)
{
	procent = p;
	idKlasy = 2;
}


Nieruchomosc::~Nieruchomosc()
{
}

double Nieruchomosc::getKwota()
{
	return kwota;
}

void Nieruchomosc::setKwota(double n)
{
	kwota = n;
}

string Nieruchomosc::getNazwa()
{
	return nazwa;
}

void Nieruchomosc::setNazwa(string n)
{
	nazwa = n;
}

int Nieruchomosc::getIdKlasy()
{
	return idKlasy;
}

void Nieruchomosc::setIdKlasy(int n)
{
	idKlasy = n;
}

string Nieruchomosc::info()
{
	return "Nieruchomosc "+nazwa;
}

double Nieruchomosc::getProcent()
{
	return procent;
}

void Nieruchomosc::setProcent(double p)
{
	procent = p;
}
