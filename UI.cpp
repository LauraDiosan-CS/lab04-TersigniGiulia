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
	cout << "John-aplicatie pentru gestionarea conturilor bancare" << endl;

	cout << "1. Adauga o tranzactie (descriere,zi,suma,tip)" << endl;
	cout << "2. Afiseaza tranzactiile mele (suma,zi,tip,descriere)" << endl;
	cout << "3. Inlocuire tranzactie de pe pozitia x" << endl;
	cout << "4. Afiseaza tranzactiile dupa tip (in/out) " << endl;
	cout << "5. Afiseaza tranzactiile cu suma mai mare ca y" << endl;
	cout << "6. Afiseaza tranzactiile cu suma egala cu z" << endl;
	cout << "7. Afiseaza suma totala a tranzactiilor de tipul in/out" << endl;
	cout << "8. Afiseaza tranzactia maxima de tipul (in/out) din ziua aa" << endl;
	cout << "9. Afiseaza sold pentru ziua aa" << endl;
	cout << "10. Elimin tranzactiile din ziua aa" << endl;
	cout << "11. Elimin tranzactiile din intervalul I[zi inceput,zi sfarsit]" << endl;
	cout << "12. Elimin tranzactiile de tipul in/out" << endl;
	cout << "13. Filtreaza tranzactiile in functie de tip (in/out) si suma s" << endl;
	cout << "0. IESIRE" << endl;


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
			afisareTranzactii(); 
			break;
		}
		case 3:
		{
			updateTranzactie();
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
			sumaTotala();
			break;
		}
		case 8: 
		{
			maximZi();
			break;
		}
		case 9:
		{
			listeazaSold();
			break;
		}
		case 10:
		{
			eliminareDupaZi();
			break;
		}
		case 11:
		{
			eliminareIntervalZi();
			break;
		}
		case 12:
		{
			eliminareTip();
			break;
		}
		
		case 13: 
		{
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