// projektCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SkladnikAktywow.h"
#include "Lokata.h"
#include "Portfel.h"
#include "Ike.h"
#include "Nieruchomosc.h"
#include "ProduktStrukturyzowany.h"
#include "Skarpeta.h"
#include "Swinka.h"
#include "Czas.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime> 
#include <cstdlib>
#include <conio.h>



//przeciazony operator +=
vector<SkladnikAktywow*> &operator+=(vector<SkladnikAktywow*> &list, SkladnikAktywow* aktywo) {
	list.push_back(aktywo);
	return list;
}


//przeciazony operator -=
vector<SkladnikAktywow*> &operator-=(vector<SkladnikAktywow*> &list, int n) {
	list.erase(list.begin() + (n-1));
	return list;
}

using namespace std; 
int main()
{
	Czas czas;
	srand(time(NULL));
	
	Portfel<SkladnikAktywow> p;
	p.wczytajZPliku(&czas);
	int wybor, wybor1 = 0, enter;
	string nazwa;
	double suma;
	do {
		cout << "Data: " << czas.getMiesiac() << " - " << czas.getRok() << endl;
		cout << "Witaj!\nWybierz opcje z menu:\n1.Dodaj skladnik aktywow\n2.Usun skladnik\n3.Edytuj skladnik\n4.Wyswietl stan oszczednosci\n5.Przewin miesiac\n6.Symulacja oszczednosci\n7.Wyjdz\n";
		cout << "Twoj wybor: ";
		cin >> wybor;
		switch (wybor) {
		case 1:
			system("cls");
			cout << "1. Lokata\n";
			cout << "2. Nieruchomosc\n";
			cout << "3. IKE w postaci lokaty\n";
			cout << "4. Produkt strukturyzowany\n";
			cout << "5. Chowaj do skarpety\n";
			cout << "6. Chowaj do swinki skarbonki\n";
			cout << "Twoj wybor: ";
			cin >> wybor1;
			p.dodajAktywo(wybor1);
			p.zapiszDoPliku(czas);
			break;
		case 2:
			system("cls");
			cout << "Wybierz skladnik do usuniecia: " << endl;
			for (int i = 0; i < p.lista.size(); i++) {
				cout << (i + 1) << ". " << p.lista.at(i)->info() << " " << fixed << setprecision(2) << p.lista.at(i)->getKwota() << " zl" << endl;
			}
			cout << "Twoj wybor: ";
			cin >> wybor1;
			p.usunAktywo(wybor1);
			p.zapiszDoPliku(czas);
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "Wybierz skladnik do edycji: " << endl;
			for (int i = 0; i < p.lista.size(); i++) {
				cout << (i + 1) << ". " << p.lista.at(i)->info() << " " << fixed << setprecision(2) << p.lista.at(i)->getKwota() << " zl" << endl;
			}
			cout << "Twoj wybor: ";
			cin >> wybor1;
			p.edytujAktywo(wybor1);
			p.zapiszDoPliku(czas);
			system("cls");
			break;
		case 4:
			p.wyswietlOszczednosci();
			break;
		case 5:
			czas.dodajMiesiac(p.lista);
			p.zapiszDoPliku(czas);
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "Zobacz ile pieniedzy bedziesz mial za X miesiecy!" << endl;
			cout << "Podaj ilosc miesiecy: ";
			cin >> wybor1;
			system("cls");
			suma = czas.obliczOszczednosci(p.lista, wybor1);
			cout << "Przyblizony stan oszczednosci za "<<wybor1 <<" miesiecy: "<< suma << " zl" << endl;
			cout << "Nacisnij enter";
			enter = _getch();
			system("cls");
			break;
		case 7:
			p.zapiszDoPliku(czas);
			exit(1);
			break;
		}
	} while (wybor != 7);
	return 0;
	
   
}





