#include<vector>
#include <fstream>
#include <cstdlib>
#include "Czas.h"
using namespace std;


template <class T>

class Portfel
{
	//przeciazony operator +=
	vector<T*> &operator+=(T* aktywo) {
		lista.push_back(aktywo);
		return list;
	}

	//przeciazony operator -=
	vector<T*> &operator-=(int n) {
		list.erase(list.begin() + (n - 1));
		return list;
	}

public:
	Portfel()
	{
	}

	~Portfel()
	{
	}


	void wyswietlOszczednosci() {
		system("cls");
		double suma = 0,enter;
		for (int i = 0; i < lista.size(); i++) {
			cout << (i + 1) << ". " << lista.at(i)->info() << " " << fixed << setprecision(2) << lista.at(i)->getKwota() << " zl" << endl;
			suma += lista.at(i)->getKwota();
		}
		cout << "Stan oszczednosci: " << suma << " zl" << endl;
		cout << "Nacisnij enter";
		enter = _getch();
		system("cls");
	}


	void dodajAktywo(int wybor1) {
		//lista += aktywo;
		double kwota, oprocentowanie, procent;
		string nazwa;
		switch (wybor1) {
		case 1:
			cout << "Podaj nazwe lokaty: ";
			cin >> nazwa;
			cout << "Podaj kwote: ";
			cin >> kwota;
			cout << "Podaj oprocentowanie w skali miesiaca: ";
			cin >> oprocentowanie;

			lista += new Lokata(kwota, nazwa, oprocentowanie);
			system("cls");
			break;
		case 2:
			cout << "Podaj nazwe nieruchomosci: ";
			cin >> nazwa;
			cout << "Podaj wartosc: ";
			cin >> kwota;
			procent = (rand() % 100 + 1) / 10.0;
			lista += new Nieruchomosc(kwota, nazwa, procent);
			
			system("cls");
			break;
		case 3:
			cout << "Podaj nazwe swojego IKE: ";
			cin >> nazwa;
			cout << "Podaj kwote: ";
			cin >> kwota;
			cout << "Podaj oprocentowanie w skali miesiaca: ";
			cin >> procent;
			lista += new Ike(kwota, nazwa, procent);
			
			system("cls");
			break;
		case 4:
			cout << "Podaj nazwe swojego produktu strukturyzowanego: ";
			cin >> nazwa;
			cout << "Podaj kwote: ";
			cin >> kwota;
			lista += new ProduktStrukturyzowany(kwota, nazwa);
			
			system("cls");
			break;
		case 5:
			cout << "Podaj nazwe swojej skarpety :) : ";
			cin >> nazwa;
			cout << "Podaj kwote: ";
			cin >> kwota;
			lista += new Skarpeta(kwota, nazwa);
			
			system("cls");
			break;
		case 6:
			cout << "Podaj nazwe swojej swinki skarbonki :) : ";
			cin >> nazwa;
			cout << "Podaj kwote: ";
			cin >> kwota;
			lista += new Swinka(kwota, nazwa);
			
			system("cls");
			break;
		}
	}

	void usunAktywo(int n) {
		lista -= n;
	}

	void edytujAktywo(int wybor1) {
		int temp;
		double kwota, oprocentowanie;
		temp = lista.at(wybor1 - 1)->getIdKlasy();
		if (temp == 1) {
			cout << "Edytuj kwote: ";
			cin >> kwota;
			cout << "Edytuj oprocentowanie: ";
			cin >> oprocentowanie;
			dynamic_cast<Lokata*>(lista.at(wybor1 - 1))->setKwota(kwota);
			dynamic_cast<Lokata*>(lista.at(wybor1 - 1))->setOprocentowanie(oprocentowanie);
		}
		else if (temp == 2) {
			cout << "Edytuj wartosc: ";
			cin >> kwota;
			dynamic_cast<Lokata*>(lista.at(wybor1 - 1))->setKwota(kwota);
		}
		else if (temp == 3) {
			cout << "Edytuj kwote: ";
			cin >> kwota;
			cout << "Edytuj oprocentowanie: ";
			cin >> oprocentowanie;
			dynamic_cast<Ike*>(lista.at(wybor1 - 1))->setKwota(kwota);
			dynamic_cast<Ike*>(lista.at(wybor1 - 1))->setOprocentowanie(oprocentowanie);
		}
		else if (temp == 4) {
			cout << "Edytuj kwote: ";
			cin >> kwota;
			dynamic_cast<ProduktStrukturyzowany*>(lista.at(wybor1 - 1))->setKwota(kwota);
		}
		else if (temp == 5) {
			cout << "Edytuj kwote: ";
			cin >> kwota;
			dynamic_cast<Skarpeta*>(lista.at(wybor1 - 1))->setKwota(kwota);
		}
		else if (temp == 6) {
			cout << "Edytuj kwote: ";
			cin >> kwota;
			dynamic_cast<Swinka*>(lista.at(wybor1 - 1))->setKwota(kwota);
		}
		system("cls");
	}

	void zapiszDoPliku(Czas czas) {
		ofstream file("lista.save", ios::out);

		file << czas.getMiesiac() << endl;
		file << czas.getRok() << endl;
		for (int i = 0; i < lista.size();i++) {
			int temp;
			temp = lista.at(i)->getIdKlasy();
			if (temp == 1) {
				file << lista.at(i)->getIdKlasy() << endl;
				file << lista.at(i)->getNazwa() << endl;
				file << lista.at(i)->getKwota() << endl;
				file << dynamic_cast<Lokata*>(lista.at(i))->getOprocentowanie() << endl;
			}
			else if (temp == 2) {
				file << lista.at(i)->getIdKlasy() << endl;
				file << lista.at(i)->getNazwa() << endl;
				file << lista.at(i)->getKwota() << endl;
				file << dynamic_cast<Nieruchomosc*>(lista.at(i))->getProcent() << endl;
			}
			else if (temp == 3) {
				file << lista.at(i)->getIdKlasy() << endl;
				file << lista.at(i)->getNazwa() << endl;
				file << lista.at(i)->getKwota() << endl;
				file << dynamic_cast<Ike*>(lista.at(i))->getOprocentowanie() << endl;
			}
			else if (temp == 4) {
				file << lista.at(i)->getIdKlasy() << endl;
				file << lista.at(i)->getNazwa() << endl;
				file << lista.at(i)->getKwota() << endl;
			}
			else if (temp == 5) {
				file << lista.at(i)->getIdKlasy() << endl;
				file << lista.at(i)->getNazwa() << endl;
				file << lista.at(i)->getKwota() << endl;
			}
			else if (temp == 6) {
				file << lista.at(i)->getIdKlasy() << endl;
				file << lista.at(i)->getNazwa() << endl;
				file << lista.at(i)->getKwota() << endl;
			}
			
		}
		file << "EOF" << endl;

		file.close();
	}

	void wczytajZPliku(Czas *czas) {
		fstream file;
		file.open("lista.save", ios::in);

		string line;
		getline(file, line);
		czas->setMiesiac(atoi(line.c_str()));
		getline(file, line);
		czas->setRok(atoi(line.c_str()));
		getline(file, line);
		while (line != "EOF") {
			if (atoi(line.c_str()) == 1) {
				int id = atoi(line.c_str());
				getline(file, line);
				string nazwa = line;
				getline(file, line);
				double kwota = atof(line.c_str());
				getline(file, line);
				double oprocentowanie = atof(line.c_str());
				lista += new Lokata(kwota, nazwa, oprocentowanie);
			}
			else if (atoi(line.c_str()) == 2) {
				int id = atoi(line.c_str());
				getline(file, line);
				string nazwa = line;
				getline(file, line);
				double kwota = atof(line.c_str());
				getline(file, line);
				double procent = atof(line.c_str());
				lista += new Nieruchomosc(kwota, nazwa, procent);
			}
			else if (atoi(line.c_str()) == 3) {
				int id = atoi(line.c_str());
				getline(file, line);
				string nazwa = line;
				getline(file, line);
				double kwota = atof(line.c_str());
				getline(file, line);
				double oprocentowanie = atof(line.c_str());
				lista += new Ike(kwota, nazwa, oprocentowanie);
			}
			else if (atoi(line.c_str()) == 4) {
				int id = atoi(line.c_str());
				getline(file, line);
				string nazwa = line;
				getline(file, line);
				double kwota = atof(line.c_str());
				lista += new ProduktStrukturyzowany(kwota, nazwa);
			}
			else if (atoi(line.c_str()) == 5) {
				int id = atoi(line.c_str());
				getline(file, line);
				string nazwa = line;
				getline(file, line);
				double kwota = atof(line.c_str());
				lista += new Skarpeta(kwota, nazwa);
			}
			else if (atoi(line.c_str()) == 6) {
				int id = atoi(line.c_str());
				getline(file, line);
				string nazwa = line;
				getline(file, line);
				double kwota = atof(line.c_str());
				lista += new Swinka(kwota, nazwa);
			}
			getline(file, line);
			
		}

		file.close();
	}

	vector <T*> lista;

	
};


