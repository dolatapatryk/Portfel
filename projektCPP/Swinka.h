#pragma once
#include "SkladnikAktywow.h"
class Swinka :
	public SkladnikAktywow
{
public:
	Swinka();
	Swinka(double n, string s);
	~Swinka();
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

