//#include "pch.h"
#include <iostream>
#include "clasaTranzactie.h"


using namespace std;
Tranzactie::Tranzactie()
{
	this->ziua = 0;
	this->suma = 0;
	this->tip = In;
	this->descriere = NULL;
}
// constructor cu parametrii
Tranzactie::Tranzactie(int ziua, int suma, Types tip, char* descriere)
{
	this->ziua = ziua;
	this->suma = suma;
	this->tip = tip;
	this->descriere = new char[strlen(descriere) + 1];
	strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
}
// constructor de copiere
Tranzactie::Tranzactie(const Tranzactie& t) {

	/*this->descriere = new char[strlen(t.descriere) + 1];
	strcpy_s(this->descriere, strlen(t.descriere) + 1, t.descriere);
	this->ziua = t.ziua;
	this->suma = t.suma;
	this->tip = t.tip;*/
	if (this != &t) {
		*this = t;
	}
}
// destructor
Tranzactie::~Tranzactie()
{
	if (this->descriere != NULL) {
		delete[] this->descriere;
		this->descriere = NULL;
	}

}
Tranzactie& Tranzactie::operator=(const Tranzactie& tranz) {
	this->ziua = tranz.ziua;
	this->suma = tranz.suma;
	this->tip = tranz.tip;
	this->descriere = new char[strlen(tranz.descriere) + 1];
	strcpy_s(this->descriere, strlen(tranz.descriere) + 1, tranz.descriere);
	return *this;
}
// setteri si getteri pentru toate proprietatiile clasei
int Tranzactie::getZiua()
{
	return this->ziua;
}
void Tranzactie::setZiua(int ziua)
{
	this->ziua = ziua;
}
int Tranzactie::getSuma() {
	return this->suma;
}
void Tranzactie::setSuma(int suma) {
	this->suma = suma;
}
// va returna 0 sau 1 deoarece intr-un enum valoare elementelor e data de ordinea lor : Ex:  {In,Out}
//																							   0  1
Types Tranzactie::getTip() {
	return this->tip;
}
void Tranzactie::setTip(Types tip) {
	this->tip = tip;
}
void Tranzactie::setDescriere(char* descriere) {
	this->descriere = new char[strlen(descriere) + 1];
	strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
}
char* const Tranzactie::getDescriere() const {
	return this->descriere;
}