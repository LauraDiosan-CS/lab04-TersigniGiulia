//#include "pch.h"
#include <iostream>
#include "clasaRepo.h"
#include "clasaTranzactie.h"
#include "testeTranzactie.h"
#include "testeRepo.h"
#include "TesteController.h"
#include "UI.h"
using namespace std;

int main()
{


	testeRepo t;
	t.runTest();
	testeTranzactie tr;
	tr.runTest();
	TesteController tc;
	tc.run();
	UI userInterface;
	userInterface.run();

	return 0;
}