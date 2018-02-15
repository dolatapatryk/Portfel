#pragma once
#include "SkladnikAktywow.h"
class Nieruchomosc :
	public SkladnikAktywow
{
public:
	Nieruchomosc();
	Nieruchomosc(double n, string s, double p);
	~Nieruchomosc();
	double getKwota();
	void setKwota(double n);
	string getNazwa();
	void setNazwa(string n);
	int getIdKlasy();
	void setIdKlasy(int n);
	string info();
	double getProcent();
	void setProcent(double p);
private:
	double procent;
	
};

