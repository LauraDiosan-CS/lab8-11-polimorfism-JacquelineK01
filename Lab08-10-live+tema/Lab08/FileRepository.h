#pragma once
#include "CalatorieAutobuz.h"
#include "CalatorieAvion.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "RepoException.h"

class FileRepository
{
private:
	std::vector<CalatorieAutobuz> calatoriiAutobuz;
	std::vector<CalatorieAvion> calatoriiAvion;
	std::vector<Calatorie> calatorii;
	std::vector<std::string>codes;
	bool textOrCSV;
	char airplaneTripsFileName[100];
	char busTripsFileName[100];
	char writeFileName[100];
public:
	FileRepository(const char* airplaneTripsFileName, const char* busTripsFileName, const char* writeFileName, bool textOrCSV = 0)
	{
		strcpy(this->airplaneTripsFileName, airplaneTripsFileName);
		strcpy(this->busTripsFileName, busTripsFileName);
		strcpy(this->writeFileName, writeFileName);
		loadAirplaneTripsFromFile();
		loadBusTripsFromFile();
		this->textOrCSV = textOrCSV;
	}
	FileRepository();
	~FileRepository();
	void loadBusTripsFromFile();
	void loadAirplaneTripsFromFile();
	void writeTripsToTxtFile(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion);
	void writeTripsToCSVFile(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion);
	void changeRepoType(bool textOrCSV);
	std::vector<CalatorieAutobuz> getAllBusTrips();
	std::vector<CalatorieAvion> getAllAirplaneTrips();
	void rezervaLocuri(std::string cod, int nr_locuri);
	int getSize();
	Calatorie get(int poz);
	void update(Calatorie a, Calatorie b);
};

