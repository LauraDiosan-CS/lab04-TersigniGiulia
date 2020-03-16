//#include "pch.h"
#include <iostream>
#include "testeTranzactie.h"
#include "clasaTranzactie.h"
#include <assert.h>

using namespace std;

void testeTranzactie::test_setSuma_isSet()
{
	Tranzactie t = Tranzactie(15, 100, In, (char*)"Depunere");
	t.setSuma(15);
	int suma = t.getSuma();
	assert(t.getSuma() == 15);
}

void testeTranzactie::test_setSuma_isNotSet()
{
	Tranzactie t = Tranzactie(15, 100, In, (char*)"Depunere");
	t.setSuma(15);
	assert(t.getSuma() != 16);
}

void testeTranzactie::test_setTip_isSet()
{
	Tranzactie t = Tranzactie(15, 100, In, (char*)"Depunere");
	t.setTip(Out);
	assert(t.getTip() == Out);
}

void testeTranzactie::test_setTip_isNotSet()
{
	Tranzactie t = Tranzactie(15, 100, In, (char*)"Depunere");
	t.setTip(Out);
	assert(t.getTip() != In);
}

void testeTranzactie::test_setZiua_isSet()
{
	Tranzactie t = Tranzactie(15, 100, In, (char*)"Depunere");
	t.setZiua(23);
	assert(t.getZiua() == 23);
}
void testeTranzactie::test_setZiua_isNotSet()
{
	Tranzactie t = Tranzactie(15, 100, In, (char*)"Depunere");
	t.setZiua(17);
	assert(t.getZiua() != 19);
}

void testeTranzactie::test_setDescriere_isSet()
{
	Tranzactie t = Tranzactie(15, 100, In, (char*)"Depunere");
	t.setDescriere((char*)"Retragere");
	assert(strcmp(t.getDescriere(), "Retragere") == 0);
}

void testeTranzactie::test_setDescriere_isNotSet()
{
	Tranzactie t = Tranzactie(15, 100, In, (char*)"Depunere");
	t.setDescriere((char*)"Retragere");
	assert(strcmp(t.getDescriere(), "Retragere") == 0);
}

void testeTranzactie::runTest()
{
	test_setSuma_isSet();
	test_setSuma_isNotSet();

	test_setTip_isSet();
	test_setTip_isNotSet();

	test_setZiua_isSet();
	test_setZiua_isNotSet();

	test_setDescriere_isSet();
	test_setDescriere_isNotSet();
}