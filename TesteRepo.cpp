//#include "pch.h"
#include "testeRepo.h"
#include "clasaRepo.h"
#include <assert.h>
void testeRepo::test_getLength_valid() {
	Repo r;
	assert(r.getLength() == 10);
}
void testeRepo::test_getLength_invalid() {
	Repo r;
	int testlength = r.getLength();
	assert(r.getLength() != 11);
}

void testeRepo::test_getSize_valid() {
	Repo r;
	assert(r.getSize() == 0);
}
void testeRepo::test_getSize_invalid() {
	Repo r;
	assert(r.getSize() != 1);
}
void testeRepo::runTest() {
	test_getLength_valid();
	test_getLength_invalid();
	test_getSize_valid();
	test_getSize_invalid();
}
