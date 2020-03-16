//#include "pch.h"
#include "UI.h"
#include <iostream>
#include "clasaRepo.h"
#include "clasaTranzactie.h"
#include "Controller.h"
using namespace std;

UI::UI()
{
	this->c1 = new Controller();
}


UI::~UI()
{
	delete this->c1;
	this->c1 = NULL;
}

void UI::printMeniu() {
	cout << "--------------------------------------------" << endl;

	cout << "0. IESIRE" << endl;
	cout << "1. Adauga tranzactie" << endl;
	cout << "2. Inlocuire tranzactie de pe pozitia..." << endl;
	cout << "3. Afisare tranzactii " << endl;
	cout << "4. Afisare tranzactii dupa tip " << endl;
	cout << "5. Afisare tranzactii cu suma mai mare ca..." << endl;
	cout << "6. Afisare tranzactii cu suma egala cu..." << endl;
	cout << "7. Afisare sold pentru ziua..." << endl;
	cout << "8. Eliminare tranzactii din ziua..." << endl;
	cout << "9. Eliminare tranzactii din intervalul..." << endl;
	cout << "10. Eliminare tranzactii de tipul..." << endl;
	cout << "11. Afisare suma totala a tranzactiilor de tipul..." << endl;
	cout << "12. Afisare tranzactie maxima de tipul... din ziua..." << endl;
	cout << "13. Filtreaza tranzactiile in functie de tip si suma" << endl;
	cout << "--------------------------------------------" << endl;

}
void UI::run() {
	int option;
	do {
		printMeniu();
		cin >> option;
		switch (option)
		{
		case 1:
		{
			addTranzactie();
			break;
		}
		case 2:
		{
			updateTranzactie();
			break;
		}
		case 3:
		{
			afisareTranzactii();
			break;
		}
		case 4:
		{
			afisareTip();
			break;
		}
		case 5:
		{
			afisareMaiMareCa();
			break;
		}
		case 6:
		{
			afisareEgalCu();
			break;
		}
		case 7:
		{
			listeazaSold();
			break;
		}
		case 8:
		{
			eliminareDupaZi();
			break;
		}
		case 9:
		{
			eliminareIntervalZi();
			break;
		}
		case 10:
		{
			eliminareTip();
			break;
		}
		case 11:
		{
			sumaTotala();
			break;
		}
		case 12: {
			maximZi();
			break;
		}
		case 13: {
			filtruTipMaiMicDecat();
			break;
		}
		}

	} while (option != 0);
}

void UI::addTranzactie() {
	char* descriere = new char[200];
	Tranzactie t;
	int ziua;
	int suma;
	int tip;
	cout << "Descriere: ";
	cin >> descriere;
	t.setDescriere(descriere);
	cout << "Ziua: ";
	cin >> ziua;
	t.setZiua(ziua);
	cout << "Suma: ";
	cin >> suma;
	t.setSuma(suma);
	cout << "Tipul: 1-In;2-Out";
	cin >> tip;
	if (tip == 1) {
		t.setTip(In);
	}
	else
		t.setTip(Out);

	this->c1->addTranzactie(t);
	delete[] descriere;
}
void UI::updateTranzactie() {
	char* descriere = new char[200];
	Tranzactie t;
	int ziua;
	int suma;
	int tip;
	int pozitie;
	cout << "Descriere: ";
	cin >> descriere;
	t.setDescriere(descriere);
	cout << "Ziua: ";
	cin >> ziua;
	t.setZiua(ziua);
	cout << "Suma: ";
	cin >> suma;
	t.setSuma(suma);
	cout << "Tipul: 1-In;2-Out";
	cin >> tip;
	if (tip == 1) {
		t.setTip(In);
	}
	else
		t.setTip(Out);
	cout << "Pozitia tranzactiei de inlocuit(incepand de la 0)";
	cin >> pozitie;
	this->c1->updateTranzactie(pozitie, t);
	delete[] descriere;
}
void UI::afisareTranzactii() {
	this->c1->afisareTranzactii();
}
void UI::afisareTip() {
	int tip;
	cout << "Tipul: 1-In;2-Out";
	cin >> tip;
	if (tip == 1) {
		this->c1->afisareTip(In);
	}
	else
		this->c1->afisareTip(Out);
}
void UI::afisareMaiMareCa() {
	int suma;
	cout << "Suma: ";
	cin >> suma;
	this->c1->afisareMaiMareCa(suma);
}
void UI::afisareEgalCu() {
	int suma;
	cout << "Suma: ";
	cin >> suma;
	this->c1->afisareEgalCu(suma);
}
void UI::listeazaSold() {
	int zi;
	cout << "Zi: ";
	cin >> zi;
	this->c1->listeazaSold(zi);
}
void UI::eliminareDupaZi() {
	int zi;
	cout << "Zi: ";
	cin >> zi;
	this->c1->eliminareDupaZi(zi);
}
void UI::eliminareIntervalZi() {
	int ziua, ziua1;
	cout << "Ziua de inceput: ";
	cin >> ziua;
	cout << "Ziua de sfarsit: ";
	cin >> ziua1;
	this->c1->eliminareIntervalZi(ziua, ziua1);
}
void UI::eliminareTip() {
	int tip;
	cout << "Tipul: 1-In;2-Out";
	cin >> tip;
	if (tip == 1) {
		this->c1->eliminareTip(In);
	}
	else
		this->c1->eliminareTip(Out);
}
void UI::sumaTotala() {
	int tip;
	cout << "Tipul: 1-In;2-Out";
	cin >> tip;
	if (tip == 1) {
		this->c1->sumaTotala(In);
	}
	else
		this->c1->sumaTotala(Out);
}
void UI::maximZi() {
	int tip;
	int ziua;
	cout << "Ziua:";
	cin >> ziua;
	cout << "Tipul: 1-In;2-Out";
	cin >> tip;
	if (tip == 1) {
		this->c1->maximZi(In, ziua);
	}
	else
		this->c1->maximZi(Out, ziua);
}
void UI::filtruTipMaiMicDecat() {
	int tip;
	int suma;
	cout << "Suma:";
	cin >> suma;
	cout << "Tipul: 1-In;2-Out";
	cin >> tip;
	if (tip == 1) {
		this->c1->filtruTipMaiMicDecat(In, suma);
	}
	else
		this->c1->maximZi(Out, suma);
}