#include "Tests.h"
#include "Service.h"
#include "FileRepository.h"
#include <assert.h>
#include <iostream>

void Tests::runTests()
{
	
	runCalatorieAutobuzTests();
	runCalatorieAvionTests();
	runRepoTests();
	runServiceTests();
	testGetters();
	testSetters();
	testConstructorWithParameters();
	testCopyConstructor();
	testImplicitConstructor();
	testEqualityOperator();
	
	runLab10Tests();
	runLab11Tests();
}

void Tests::runRepoTests()
{
	testFileRepo();
}

void Tests::testFileRepo() {
	FileRepository repo{ "airplaneTest2.txt", "busTest2.txt", "tests2.txt"};
	repo.loadAirplaneTripsFromFile();
	repo.loadBusTripsFromFile();
	std::vector<CalatorieAutobuz>bus = repo.getAllBusTrips();
	assert(bus.size() == 1);
	repo.writeTripsToTxtFile(bus, repo.getAllAirplaneTrips());
	try{
		repo.rezervaLocuri("2", 6);
		assert(true);
	}
	catch(std::exception &e){
		assert(false);
	}
}

void Tests::runServiceTests()
{
	
}

//-----------------------CONSTRUCTOR TESTS------------------------

void Tests::testImplicitConstructor()
{
	CalatorieAutobuz c1;
	assert(c1.getNrLocTotale() == 0);
	assert(c1.getNrLocRezervate() == 0);
	assert(c1.getNrZileDurata() == 0);

	CalatorieAvion a1;
	assert(a1.getNrLocTotale() == 0);
	assert(a1.getNrLocRezervate() == 0);
}

void Tests::testConstructorWithParameters()
{
	CalatorieAutobuz calatorieBus("1", "Bucuresti", "Cluj", "13.04.2019", 2, 55, 30);
	assert(calatorieBus.getCod()=="1");
	assert(calatorieBus.getNrLocTotale() == 55);
	assert(calatorieBus.getNrLocRezervate() == 30);
	assert(calatorieBus.getNrZileDurata() == 2);
	char locPlecare[10];
	strcpy(locPlecare, "Bucuresti");
	assert(strcmp(calatorieBus.getLocalitatePlecare(), locPlecare) == 0);


	CalatorieAvion calatorieAvion("2", "Cluj", "Barcelona", "14.05.2018", 1, 120, 80);
	assert(calatorieAvion.getCod() == "2");
	char locPlecare2[10];
	strcpy(locPlecare2, "Cluj");
	assert(strcmp(calatorieAvion.getLocalitatePlecare(), locPlecare2) == 0);
}

void Tests::testCopyConstructor()
{
	CalatorieAutobuz c1("1", "Bucuresti", "Cluj", "13.04.2019", 2, 55, 30);
	CalatorieAutobuz c2(c1);
	assert(c1.getNrLocTotale() == c2.getNrLocTotale());
	assert(c1.getNrLocRezervate() == c2.getNrLocRezervate());

	CalatorieAvion a1("5", "Cluj", "Barcelona", "14.05.2018", 1, 120, 80);
	CalatorieAvion a2(a1);
	assert(a1.getNrLocRezervate() == a2.getNrLocRezervate());
	assert(a1.getNrLocTotale() == a2.getNrLocTotale());
}

void Tests::testEqualityOperator()
{
	CalatorieAutobuz c1("1", "Bucuresti", "Cluj", "13.04.2019", 2, 55, 30);
	CalatorieAutobuz c2 = c1;
	assert(c2 == c1);

	CalatorieAvion a1("5", "Cluj", "Barcelona", "14.05.2018", 1, 120, 80);
	CalatorieAvion a2 = a1;
	assert(a2 == a1);
}

//------------------------------------------------------------------


void Tests::runCalatorieAutobuzTests()
{

}

void Tests::runCalatorieAvionTests()
{
}

//------------------------------GETTERS TESTS------------------------------------

void Tests::testGetters()
{
	CalatorieAutobuz calatorieBus("1", "Bucuresti", "Cluj", "13.04.2019", 2, 55,30);
	assert(calatorieBus.getCod() == "1");

	char locPlecare[10];
	strcpy(locPlecare, "Bucuresti");
	assert(strcmp(calatorieBus.getLocalitatePlecare(), locPlecare) == 0);

	char locDestinatie[5];
	strcpy(locDestinatie, "Cluj");
	assert(strcmp(calatorieBus.getLocalitateDestinatie(),locDestinatie) == 0);

	char data[11];
	strcpy(data, "13.04.2019");
	assert(strcmp(calatorieBus.getDataPlecarii(), data) == 0);

	assert(calatorieBus.getNrZileDurata() == 2);
	assert(calatorieBus.getNrLocTotale() == 55);
	assert(calatorieBus.getNrLocRezervate() == 30);

	CalatorieAvion calatorieAvion("1", "Cluj", "Barcelona", "14.05.2018", 1, 120, 80);
	assert(calatorieAvion.getEscala() == 1);
	assert(calatorieAvion.getNrLocTotale() == 120);

}

//-------------------------------SETTERS TESTS--------------------------------------------

void Tests::testSetters()
{
	CalatorieAutobuz calatorieBus1("1", "Bucuresti", "Cluj", "13.04.2019", 2, 55, 30);
	calatorieBus1.setNrLocRezervate(35);
	assert(calatorieBus1.getNrLocRezervate() == 35);
	calatorieBus1.setNrZileDurata(3);
	assert(calatorieBus1.getNrZileDurata() == 3);

	char locPlecare1[10];
	strcpy(locPlecare1, "Madrid");
	calatorieBus1.setLocalitatePlecare(locPlecare1);
	assert(strcmp(calatorieBus1.getLocalitatePlecare(), locPlecare1) == 0);

	CalatorieAvion calatorieAvion1("1","Cluj","Barcelona","14.05.2018", 1, 120, 80);
	calatorieAvion1.setEscala(0);
	assert(calatorieAvion1.getEscala() == 0);
	calatorieAvion1.setNrLocTotale(100);
	assert(calatorieAvion1.getNrLocTotale() == 100);

	char locPlecare2[10];
	strcpy(locPlecare2, "Bucuresti");
	calatorieAvion1.setLocalitatePlecare(locPlecare2);
	assert(strcmp(calatorieAvion1.getLocalitatePlecare(), locPlecare2) == 0);
}

//-------------------------TESTE LABORATORUL 10 LIVE--------------------------------

void Tests::runLab10Tests() {
	FileRepository* repo = new FileRepository{ "airplaneTest.txt", "busTest.txt", "tests.csv" };
	CalatorieAvion* c1 = new CalatorieAvion("1x54", "Cluj - Napoca", "Dubai", "14.06.2020", 0, 100, 80);
	CalatorieAutobuz* c2 = new CalatorieAutobuz("39g0", "Constanta", "Brasov", "15.07.2020", 1, 40, 20);
	CalatorieAutobuz* c3 = new CalatorieAutobuz("41kl", "Bucuresti", "Vienna", "11.06.2020", 3, 80, 50);
	assert(repo->getSize() == 3);
	assert(repo->get(0) == *c1);
	assert(repo->get(1) == *c2);
	assert(repo->get(2) == *c3);
	Calatorie* c4 = new CalatorieAvion("h6pd", "Iasi", "Munchen", "20.09.2020", 1, 50, 10);
	repo->update(*c2, *c4);
	assert(repo->get(0) == *c1);
	assert(repo->get(1) == *c3);
	assert(repo->get(2) == *c4);
	repo->update(*c1, *c2);
	assert(repo->get(0) == *c3);
	assert(repo->get(1) == *c4);
	assert(repo->get(2) == *c2);
}


//-------------------------TESTE LABORATORUL 11 LIVE--------------------------------

void Tests::runLab11Tests()
{
	FileRepository* repo = new FileRepository{ "airplaneTest3.txt", "busTest3.txt", "tests3.csv" };
	Service newService{ *repo };
	CalatorieAvion c1("156", "Cluj - Napoca", "Dubai", "14.06.2020", false, 100, 80);
	CalatorieAutobuz c2("873", "Constanta", "Brasov", "15.07.2020", 1, 40, 20);
	CalatorieAutobuz c3("118", "Bucuresti", "Vienna", "11.06.2020", 3, 80, 50);
	newService.addTrip(c1);
	newService.addTrip(c2);
	newService.addTrip(c3);
	try {
		char oras[10];
		strcpy_s(oras, sizeof("Brasov"), "Brasov");
		newService.deleteTrip("873", oras);
		assert(newService.getNumberOfTrips() == 2);
		assert(newService.getTripAtPos(0) == c1);
		assert(newService.getTripAtPos(1) == c3);
	}
	catch(std::exception& e){
		std::cout << e.what() << "****\n";
		assert(false);
	}

	try {
		char oras[10];
		strcpy_s(oras, sizeof("Paris"), "Paris");
		newService.deleteTrip("156", oras);
		assert(false);
	}
	catch (std::exception & e) {
		std::cout << e.what() << "****\n";
		assert(newService.getNumberOfTrips() == 2);
		assert(newService.getTripAtPos(0) == c1);
		assert(newService.getTripAtPos(1) == c3);
	}

	try {
		char oras[10];
		strcpy_s(oras, sizeof("Fagaras"), "Fagaras");
		newService.deleteTrip("667", oras);
		assert(false);
	}
	catch (std::exception & e) {
		std::cout << e.what()<<"****\n";
		assert(newService.getNumberOfTrips() == 2);
		assert(newService.getTripAtPos(0) == c1);
		assert(newService.getTripAtPos(1) == c3);
	}

	try {
		char oras[10];
		strcpy_s(oras, sizeof("Paris"), "Paris");
		newService.deleteTrip("156", oras);
		assert(false);
	}
	catch (std::exception & e) {
		std::cout << e.what() << "****\n";
	}

	try {
		char oras[10];
		strcpy_s(oras, sizeof("Fagaras"), "Fagaras");
		newService.deleteTrip("667", oras);
		assert(false);
	}
	catch (std::exception & e) {
		std::cout << e.what() << '\n';
	}
}