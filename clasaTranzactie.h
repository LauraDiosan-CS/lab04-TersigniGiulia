#pragma once
#ifndef CLASATranzactie_H_
#define CLASATranzactie_H_

enum Types { In, Out };

class Tranzactie
{
private:
	int ziua;
	int suma;
	char* descriere;
	Types tip;
public:
	Tranzactie();		//constructor fara parametru
	Tranzactie(int ziua, int suma, Types tip, char* descriere);		//constructor cu parametrii
	Tranzactie(const Tranzactie& t); // constructor de copiere
	~Tranzactie();		//destructor
	Tranzactie& operator=(const Tranzactie& tranz);
	void setZiua(int ziua);
	int getZiua();

	void setSuma(int suma);
	int getSuma();

	void setTip(Types tip);
	Types getTip();

	void setDescriere(char* descriere);
	char* const getDescriere() const;
};

#endif