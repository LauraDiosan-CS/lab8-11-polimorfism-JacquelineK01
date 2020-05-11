#pragma once
#include "CalatorieAutobuz.h"
#include "CalatorieAvion.h"
#include <vector>
#include <fstream>
#include "RepoException.h"
#include "Repository.h"
/*
class RepositoryFileTxt: public Repository
{
private:
	char airplaneTripsFileName[100];
	char busTripsFileName[100];
	char writeFileName[100];
public:
	RepositoryFileTxt(const char* airplaneTripsFileName, const char* busTripsFileName, const char* writeFileName);
	RepositoryFileTxt();
	~RepositoryFileTxt();
	void loadBusTripsFromFile();
	void loadAirplaneTripsFromFile();

	void writeTripsToFile(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion);


	std::vector<CalatorieAutobuz> getAllBusTrips();
	std::vector<CalatorieAvion> getAllAirplaneTrips();
	void rezervaLocuri(int cod, int nr_locuri);

};

*/