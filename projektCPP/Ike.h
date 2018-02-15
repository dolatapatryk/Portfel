#pragma once
#include "SkladnikAktywow.h"
class Ike :
	public SkladnikAktywow
{
public:
	Ike();
	Ike(double n, string s, double o);
	~Ike();
	double getKwota();
	void setKwota(double n);
	string getNazwa();
	void setNazwa(string n);
	int getIdKlasy();
	void setIdKlasy(int n);
	string info();
	double getOprocentowanie();
	void setOprocentowanie(double n);
	double getWplata();
	void setWplata(double n);

private:
	double oprocentowanie;
	double wplata;
};

