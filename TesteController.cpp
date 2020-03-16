//#include "pch.h"
#include "TesteController.h"
#include "Controller.h"
#include <assert.h>

void TesteController::getSize_isSet() {
	Controller* c1 = new Controller();
	int size = c1->getSize();
	assert(size == 0);
}

void TesteController::geSize_isNotSet() {
	Controller* c1 = new Controller();
	int size = c1->getSize();
	assert(size != 5);
}

void TesteController::getLength_isSet() {
	Controller* c1 = new Controller();
	int length = c1->getLength();
	assert(length == 10);
}

void TesteController::getLength_isNotSet() {
	Controller* c1 = new Controller();
	int length = c1->getLength();
	assert(length != 15);
}

void TesteController::run() {
	getSize_isSet();
	geSize_isNotSet();
	getLength_isSet();
	getLength_isNotSet();
}