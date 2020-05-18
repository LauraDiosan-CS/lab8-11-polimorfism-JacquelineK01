#pragma once
#include "UI.h"

class Tests
{
public:
	void runTests();
private:
	//void runCalatorieTests();
	void runCalatorieAutobuzTests();
	void runCalatorieAvionTests();
	void runRepoTests();
	void runServiceTests();

	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testEqualityOperator();

	void testGetters();
	void testSetters();

	void testFileRepo();

	void runLab10Tests();
	void runLab11Tests();
	void runLab12Tests();
};

