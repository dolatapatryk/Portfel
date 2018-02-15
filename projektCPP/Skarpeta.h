#pragma once
#include "SkladnikAktywow.h"
class Skarpeta :
	public SkladnikAktywow
{
public:
	Skarpeta();
	Skarpeta(double n, string s);
	~Skarpeta();
	double getKwota();
	void setKwota(double n);
	string getNazwa();
	void setNazwa(string s);
	int getIdKlasy();
	void setIdKlasy(int n);
	string info();
	double getWplata();
	void setWplata(double n);
private:
	double wplata;
};

