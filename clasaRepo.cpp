//#include "pch.h"
#include <iostream>
#include "clasaRepo.h"
#include "clasaTranzactie.h"

using namespace std;

Repo::Repo()
{
	this->size = 0;
	this->length = 10;
	this->listaTranzactii = new Tranzactie[10];
}

Repo::Repo(Repo& r)
{
	this->size = r.size;
	this->length = r.length;
	this->listaTranzactii = new Tranzactie[r.length];
	this->listaTranzactii = r.listaTranzactii;
}
Repo::~Repo()
{
	if (this->listaTranzactii != NULL) {
		delete[] this->listaTranzactii;
		this->listaTranzactii = NULL;
		this->size = 0;
		this->length = 0;
	}

}

void Repo::addTranzactie(Tranzactie tranz)
{
	if (this->size == this->length)
		resize();
	this->listaTranzactii[this->size] = tranz;
	this->size++;
}
void Repo::updateTranzactie(int x, Tranzactie tranz) {
	if (this->size - 1 >= x) {
		this->listaTranzactii[x] = tranz;
	}
}
void Repo::resize() {
	Tranzactie* newListaTranzactii = new Tranzactie[this->length * 2];
	for (int i = 0; i < this->size; i++) {
		newListaTranzactii[i] = this->listaTranzactii[i];
	}
	delete[] this->listaTranzactii;
	this->listaTranzactii = newListaTranzactii;
	this->length *= 2;
}
int Repo::getSize() {
	return this->size;
}
int Repo::getLength() {
	return this->length;
}

void Repo::afisareTranzactie(Tranzactie t) {
	cout << "Suma:" << t.getSuma() << endl;
	cout << "Ziua:" << t.getZiua() << endl;
	cout << "Tipul: ";
	if (t.getTip() == 0) {
		cout << "In" << endl;
	}
	else {
		cout << "Out" << endl;
	}
	cout << "Descriere " << t.getDescriere() << endl;
	cout << "--------------------------------------------" << endl;
}

void Repo::afisareTranzactii() {
	for (int i = 0; i < size; i++) {
		this->afisareTranzactie(this->listaTranzactii[i]);
	}
}
Tranzactie* Repo::getAll() {
	return this->listaTranzactii;
}
void Repo::eliminareDupaZi(int zi) {
	Tranzactie* newList = new Tranzactie[this->length];
	int j = 0;
	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getZiua() != zi) {
			newList[j] = t;
			j++;
		}
	}
	delete[] this->listaTranzactii;

	this->size = j;
	this->listaTranzactii = newList;
}
void Repo::eliminareIntervalZi(int start, int end) {
	Tranzactie* newList = new Tranzactie[this->length];
	int j = 0;
	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getZiua() < start || t.getZiua() > end) {
			newList[j] = t;
			j++;
		}
	}
	delete[] this->listaTranzactii;

	this->size = j;
	this->listaTranzactii = newList;
}
void Repo::eliminareTip(Types tip) {
	Tranzactie* newList = new Tranzactie[this->length];
	int j = 0;
	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getTip() != tip) {
			newList[j] = t;
			j++;
		}
	}
	delete[] this->listaTranzactii;

	this->size = j;
	this->listaTranzactii = newList;
}
void Repo::inlocuireTranzactie(int zi, Types tip, char* descriere, int salarNou) {
	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		char* chr = t.getDescriere();

		if ((t.getZiua() == zi) && (t.getTip() == tip) && (strcmp(t.getDescriere(), descriere) == 0)) {
			this->listaTranzactii[i].setSuma(salarNou);
		}
	}
}
void Repo::afisareTip(Types tip) {
	cout << "Afisare tranzactiile de tipul ";
	if (tip == 0) {
		cout << "In" << endl;
	}
	else {
		cout << "Out" << endl;
	}
	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getTip() == tip) {
			afisareTranzactie(t);
		}
	}
}
void Repo::afisareMaiMareCa(int suma) {
	cout << "Afisare tranzactii cu suma mai mare decat " << suma << endl;
	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getSuma() > suma) {
			afisareTranzactie(t);
		}
	}
}
void Repo::afisareEgalCu(int suma) {
	cout << "Afisare tranzactii cu suma egala cu " << suma << endl;

	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getSuma() == suma) {
			afisareTranzactie(t);
		}
	}
}
void Repo::listeazaSold(int zi) {
	cout << "Afisare sold pentru ziua " << zi << endl;
	int sold = 700;
	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getTip() == In && t.getZiua() == zi) {
			sold += t.getSuma();
		}
		else if (t.getZiua() == zi) {
			sold -= t.getSuma();
		}
	}
	cout << "Soldul din ziua " << zi << " este: " << sold << endl;
}
void Repo::sumaTotala(Types tip) {
	cout << "Afisare suma totala pentru tranzactiile de tipul ";
	if (tip == 0) {
		cout << "In" << endl;
	}
	else {
		cout << "Out" << endl;
	}
	int total = 0;
	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getTip() == tip) {
			total += t.getSuma();
		}
	}
	cout << "Suma totala este: " << total << endl;
}
void Repo::maximZi(Types tip, int ziua) {
	cout << "Afisare maximul pentru tranzactiile de tipul ";
	if (tip == 0) {
		cout << "In ";
	}
	else {
		cout << "Out ";
	}
	cout << "din ziua " << ziua << endl;
	Tranzactie max;

	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getTip() == tip)
			if (t.getSuma() > max.getSuma()) {
				max = t;
			}
	}
	cout << "Tranzactia maxima este: " << max.getSuma() << endl;
}

void Repo::filtruTipMaiMicDecat(Types tip, int suma) {
	Tranzactie* newList = new Tranzactie[this->length];
	int j = 0;
	for (int i = 0; i < this->size; i++) {
		Tranzactie t = this->listaTranzactii[i];
		if (t.getTip() == tip && t.getSuma() < suma) {
			newList[j] = t;
			j++;
		}
	}
	delete[] this->listaTranzactii;

	this->size = j;
	this->listaTranzactii = newList;
}