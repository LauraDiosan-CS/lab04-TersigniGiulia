#pragma once
#ifndef CLASAREPO_H_
#define CLASAREPO_H_

#include "clasaTranzactie.h"

class Repo
{
private:
	int size;
	int length;
	Tranzactie* listaTranzactii;
public:
	Repo();
	Repo(Repo& r);
	~Repo();
	void resize();
	void addTranzactie(Tranzactie tranz);
	void updateTranzactie(int x, Tranzactie tranz);
	int getSize();
	int getLength();
	void afisareTranzactii();
	void afisareTranzactie(Tranzactie t);
	void afisareTip(Types tip);
	void afisareMaiMareCa(int suma);
	void afisareEgalCu(int suma);
	void listeazaSold(int zi);
	void eliminareDupaZi(int zi);
	void eliminareIntervalZi(int start, int end);
	void eliminareTip(Types tip);
	void inlocuireTranzactie(int zi, Types tip, char* descriere, int salarNou);
	void sumaTotala(Types tip);
	void maximZi(Types tip, int ziua);
	void filtruTipMaiMicDecat(Types tip, int suma);
	Tranzactie* getAll();
};

#endif