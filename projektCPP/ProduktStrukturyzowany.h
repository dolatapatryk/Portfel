#pragma once
#include "SkladnikAktywow.h"
class ProduktStrukturyzowany :
	public SkladnikAktywow
{
public:
	ProduktStrukturyzowany();
	ProduktStrukturyzowany(double n, string s);
	~ProduktStrukturyzowany();
	double getKwota();
	void setKwota(double n);
	string getNazwa();
	void setNazwa(string n);
	int getIdKlasy();
	void setIdKlasy(int n);
	string info();
	double getSzansaNaZysk();
	void setSzansaNaZysk(double n);
	double getProcentZysku();
	void setProcentZysku(double n);

private:
	double szansaNaZysk;
	double procentZysku;
};

