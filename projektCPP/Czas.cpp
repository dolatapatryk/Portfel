#include "stdafx.h"
#include "Czas.h"
#include <ctime> 
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <iomanip>

Czas::Czas()
{
}


Czas::~Czas()
{
}

int Czas::getMiesiac()
{
	return miesiac;
}

void Czas::setMiesiac(int n)
{
	miesiac = n;
}

int Czas::getRok()
{
	return rok;
}

void Czas::setRok(int n)
{
	rok = n;
}



void Czas::dodajMiesiac(vector<SkladnikAktywow*> lista)
{
	if (miesiac == 12) {
		setMiesiac(1);
		setRok(getRok() + 1);
	}
	else {
		setMiesiac(getMiesiac() + 1);
	}
	
	for (int i = 0; i < lista.size(); i++) {
		int temp = lista.at(i)->getIdKlasy();
		if (temp == 1) {
			double kwota = lista.at(i)->getKwota();
			double procent = dynamic_cast<Lokata*>(lista.at(i))->getOprocentowanie() / 100;
			lista.at(i)->setKwota(kwota + (kwota*procent));
		}
		else if (temp == 2) {
			double kwota = lista.at(i)->getKwota();
			double procent = dynamic_cast<Nieruchomosc*>(lista.at(i))->getProcent() / 100;
			lista.at(i)->setKwota(kwota + (kwota*procent));
		}
		else if (temp == 3) {
			double kwota = lista.at(i)->getKwota();
			double procent = dynamic_cast<Ike*>(lista.at(i))->getOprocentowanie() / 100;
			int wplata = rand() % 1000 + 1;
			lista.at(i)->setKwota(kwota + (kwota*procent) + wplata);
		}
		else if (temp == 4) {
			double kwota = lista.at(i)->getKwota();
			double szansa = (rand() % 100 + 1) / 100.0;
			dynamic_cast<ProduktStrukturyzowany*>(lista.at(i))->setSzansaNaZysk(szansa);
			double random = (rand() % 100 + 1) / 100.0;
			if (random <= szansa) {
				double procent = (rand() % 20 + 1) / 100.0;
				dynamic_cast<ProduktStrukturyzowany*>(lista.at(i))->setProcentZysku(procent);
				lista.at(i)->setKwota(kwota + (kwota*procent));
			}
		}
		else if (temp == 5) {
			double kwota = lista.at(i)->getKwota();
			int wplata = rand() % 100 + 1;
			dynamic_cast<Skarpeta*>(lista.at(i))->setWplata(wplata);
			lista.at(i)->setKwota(kwota + wplata);
		}
		else if (temp == 6) {
			double kwota = lista.at(i)->getKwota();
			int wplata = rand() % 100 + 1;
			dynamic_cast<Swinka*>(lista.at(i))->setWplata(wplata);
			lista.at(i)->setKwota(kwota + wplata);
		}
	}


}

double Czas::obliczOszczednosci(vector<SkladnikAktywow*> lista, int n)
{
	srand(time(NULL));
	double *tmpTab = new double[lista.size()];
	for (int i = 0; i < lista.size(); i++) {
		tmpTab[i] = lista.at(i)->getKwota();
	}
	for(int i=0;i<n;i++){
		for (int i = 0; i < lista.size(); i++) {
			int temp = lista.at(i)->getIdKlasy();
			if (temp == 1) {
				double kwota = lista.at(i)->getKwota();
				double procent = dynamic_cast<Lokata*>(lista.at(i))->getOprocentowanie() / 100;
				lista.at(i)->setKwota(kwota + (kwota*procent));
			}
			else if (temp == 2) {
				double kwota = lista.at(i)->getKwota();
				double procent = dynamic_cast<Nieruchomosc*>(lista.at(i))->getProcent() / 100;
				lista.at(i)->setKwota(kwota + (kwota*procent));
			}
			else if (temp == 3) {
				double kwota = lista.at(i)->getKwota();
				double procent = dynamic_cast<Ike*>(lista.at(i))->getOprocentowanie() / 100;
				int wplata = rand() % 1000 + 1;
				lista.at(i)->setKwota(kwota + (kwota*procent) + wplata);
			}
			else if (temp == 4) {
				double kwota = lista.at(i)->getKwota();
				double szansa = (rand() % 100 + 1) / 100.0;
				dynamic_cast<ProduktStrukturyzowany*>(lista.at(i))->setSzansaNaZysk(szansa);
				double random = (rand() % 100 + 1) / 100.0;
				if (random <= szansa) {
					double procent = (rand() % 20 + 1) / 100.0;
					dynamic_cast<ProduktStrukturyzowany*>(lista.at(i))->setProcentZysku(procent);
					lista.at(i)->setKwota(kwota + (kwota*procent));
				}
			}
			else if (temp == 5) {
				double kwota = lista.at(i)->getKwota();
				int wplata = rand() % 100 + 1;
				dynamic_cast<Skarpeta*>(lista.at(i))->setWplata(wplata);
				lista.at(i)->setKwota(kwota + wplata);
			}
			else if (temp == 6) {
				double kwota = lista.at(i)->getKwota();
				int wplata = rand() % 100 + 1;
				dynamic_cast<Swinka*>(lista.at(i))->setWplata(wplata);
				lista.at(i)->setKwota(kwota + wplata);
			}
		}
		
	}
	for (int i = 0; i < lista.size(); i++) {
		cout << (i + 1) << ". " << lista.at(i)->info() << " " << fixed << setprecision(2) << lista.at(i)->getKwota() << " zl" << endl;
	}
	int suma = 0;
	for (int i = 0; i < lista.size(); i++) {
		suma += lista.at(i)->getKwota();
	}
	for (int i = 0; i < lista.size(); i++) {
		lista.at(i)->setKwota(tmpTab[i]);
	}
	return suma;
}
