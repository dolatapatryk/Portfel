#include "stdafx.h"
#include "Ike.h"


Ike::Ike()
{
}

Ike::Ike(double n, string s, double o) :SkladnikAktywow(n,s)
{
	oprocentowanie = o;
	idKlasy = 3;
}


Ike::~Ike()
{
}

double Ike::getKwota()
{
	return kwota;
}

void Ike::setKwota(double n)
{
	kwota = n;
}

string Ike::getNazwa()
{
	return nazwa;
}

void Ike::setNazwa(string n)
{
	nazwa = n;
}

int Ike::getIdKlasy()
{
	return idKlasy;
}

void Ike::setIdKlasy(int n)
{
	idKlasy = n;
}

string Ike::info()
{
	return "IKE "+nazwa;
}

double Ike::getOprocentowanie()
{
	return oprocentowanie;
}

void Ike::setOprocentowanie(double n)
{
	oprocentowanie = n;
}

double Ike::getWplata()
{
	return wplata;
}

void Ike::setWplata(double n)
{
	wplata = n;
}
