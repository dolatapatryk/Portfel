#pragma once
#include <string>
using namespace std;
class SkladnikAktywow
{
public:
	SkladnikAktywow();
	SkladnikAktywow(double n, string s);
	~SkladnikAktywow();
	virtual double getKwota() = 0;
	virtual void setKwota(double n) = 0;
	virtual string getNazwa() = 0;
	virtual void setNazwa(string n) = 0;
	virtual string info() = 0;
	virtual int getIdKlasy() = 0;
	virtual void setIdKlasy(int n) = 0;
protected:
	double kwota;
	string nazwa;
	int idKlasy;
};

