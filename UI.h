#pragma once
#pragma once
#include "Controller.h"
class UI
{
private:
	Controller* c1;

public:
	UI();
	~UI();

	void run();
	void printMeniu();
	void addTranzactie();
	void updateTranzactie();
	void afisareTranzactii();
	void afisareTip();
	void afisareMaiMareCa();
	void afisareEgalCu();
	void listeazaSold();
	void eliminareDupaZi();
	void eliminareIntervalZi();
	void eliminareTip();
	void sumaTotala();
	void maximZi();
	void filtruTipMaiMicDecat();
};

