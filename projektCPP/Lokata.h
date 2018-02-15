#pragma once
#include "SkladnikAktywow.h"
#include <string>
using namespace std;
class Lokata :
	public SkladnikAktywow
{
public:
	Lokata();
	Lokata(double n, string s, double o);
	~Lokata();
	double getKwota();
	void setKwota(double n);
	string getNazwa();
	void setNazwa(string n);
	int getIdKlasy();
	void setIdKlasy(int n);
	string info();
	double getOprocentowanie();
	void setOprocentowanie(double n);
private:
	double oprocentowanie;
};

