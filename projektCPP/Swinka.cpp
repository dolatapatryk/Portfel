#include "stdafx.h"
#include "Swinka.h"


Swinka::Swinka()
{
}

Swinka::Swinka(double n, string s) :SkladnikAktywow(n,s)
{
	idKlasy = 6;
}


Swinka::~Swinka()
{
}

double Swinka::getKwota()
{
	return kwota;
}

void Swinka::setKwota(double n)
{
	kwota = n;
}

string Swinka::getNazwa()
{
	return nazwa;
}

void Swinka::setNazwa(string s)
{
	nazwa = s;
}

int Swinka::getIdKlasy()
{
	return idKlasy;
}

void Swinka::setIdKlasy(int n)
{
	idKlasy = n;
}

string Swinka::info()
{
	return "Swinka skarbonka " + nazwa;
}

double Swinka::getWplata()
{
	return wplata;
}

void Swinka::setWplata(double n)
{
	wplata = n;
}
