#include "stdafx.h"
#include "Lokata.h"
#include <cmath>
#include <iostream>
using namespace std;

Lokata::Lokata()
{
}

Lokata::Lokata(double n, string s, double o) :SkladnikAktywow(n,s)
{
	oprocentowanie = o;
	idKlasy = 1;
}


Lokata::~Lokata()
{
}

double Lokata::getKwota()
{
	return kwota;
}

void Lokata::setKwota(double n)
{
	kwota = n;
}

string Lokata::getNazwa()
{
	return nazwa;
}

void Lokata::setNazwa(string n)
{
	nazwa = n;
}

int Lokata::getIdKlasy()
{
	return idKlasy;
}

void Lokata::setIdKlasy(int n)
{
	idKlasy = n;
}



string Lokata::info()
{
	
	return "Lokata "+ nazwa;
}

double Lokata::getOprocentowanie()
{
	return oprocentowanie;
}

void Lokata::setOprocentowanie(double n)
{
	oprocentowanie = n;
}
