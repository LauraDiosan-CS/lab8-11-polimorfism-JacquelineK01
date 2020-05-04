#pragma once
#include "CalatorieAutobuz.h"
#include "CalatorieAvion.h"
#include <vector>
#include <fstream>
#include "RepoException.h"
/*
class Repository
{
protected:
	std::vector<CalatorieAutobuz> calatoriiAutobuz;
	std::vector<CalatorieAvion> calatoriiAvion;
	bool textOrCSV;
	char airplaneTripsFileName[100];
	char busTripsFileName[100];
	char writeFileName[100];
public:
	Repository(const char* airplaneTripsFileName, const char* busTripsFileName, const char* writeFileName, bool textOrCSV = 0);
	Repository();
	~Repository();
	virtual void loadBusTripsFromFile()=0;
	virtual void loadAirplaneTripsFromFile()=0;

	virtual void writeTripsToFile(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion)=0;

	//void changeRepoType(bool textOrCSV);

	std::vector<CalatorieAutobuz> getAllBusTrips();
	std::vector<CalatorieAvion> getAllAirplaneTrips();
	void rezervaLocuri(int cod, int nr_locuri);

};
*/

