//#include "pch.h"
#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	this->r1 = new Repo();
}


Controller::~Controller()
{
	delete this->r1;
	this->r1 = NULL;
}
void Controller::addTranzactie(Tranzactie tranz) {
	this->r1->addTranzactie(tranz);
}
void Controller::updateTranzactie(int x, Tranzactie tranz) {
	this->r1->updateTranzactie(x, tranz);
}
int Controller::getSize() {
	return this->r1->getSize();
}
int Controller::getLength() {
	return this->r1->getLength();
}
void Controller::afisareTranzactii() {
	this->r1->afisareTranzactii();
}
void Controller::afisareTranzactie(Tranzactie t) {
	this->r1->afisareTranzactie(t);
}
void Controller::afisareTip(Types tip) {
	this->r1->afisareTip(tip);
}
void Controller::afisareMaiMareCa(int suma) {
	this->r1->afisareMaiMareCa(suma);
}
void Controller::afisareEgalCu(int suma) {
	this->r1->afisareEgalCu(suma);
}
void Controller::listeazaSold(int zi) {
	this->r1->listeazaSold(zi);
}
void Controller::eliminareDupaZi(int zi) {
	this->r1->eliminareDupaZi(zi);
}
void Controller::eliminareIntervalZi(int start, int end) {
	this->r1->eliminareIntervalZi(start, end);
}
void Controller::eliminareTip(Types tip) {
	this->r1->eliminareTip(tip);
}
void Controller::sumaTotala(Types tip) {
	this->r1->sumaTotala(tip);
}
void Controller::maximZi(Types tip, int ziua) {
	this->r1->maximZi(tip, ziua);
}
void Controller::filtruTipMaiMicDecat(Types tip, int suma) {
	this->r1->filtruTipMaiMicDecat(tip, suma);
}
Tranzactie* Controller::getAll() {
	return this->r1->getAll();
}

