#pragma once
#include "clasaRepo.h"
class Controller
{
private:
	Repo* r1;
public:
	Controller();
	~Controller();
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
	void sumaTotala(Types tip);
	void maximZi(Types tip, int ziua);
	void filtruTipMaiMicDecat(Types tip, int suma);
	Tranzactie* getAll();
};

