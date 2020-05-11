#pragma once
#include "CalatorieAutobuz.h"
#include "CalatorieAvion.h"
#include "Calatorie.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "RepoException.h"
#include "DeleteException.h"

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
	/*void addAirplaneTrip(CalatorieAvion c) {
		this->calatoriiAvion.push_back(c);
	};
	void addBusTrip(CalatorieAutobuz c) {
		this->calatoriiAutobuz.push_back(c);
	};*/
	void addTrip(Calatorie c) {
		for (int i = 0; i < calatorii.size(); ++i)
			if (calatorii[i].getCod() == c.getCod())
				throw RepoException{ "Trip already in the list\n" };
		this->calatorii.push_back(c);
	}
	void deleteTrip(std::string code, char* destination) {
		bool codeFound = 0, destinationFound = 0;
		std::string error="";
		for (int i = 0; i < calatorii.size(); ++i) {
			if (calatorii[i].getCod() == code && strcmp(calatorii[i].getLocalitateDestinatie(), destination) == 0) {
				calatorii.erase(calatorii.begin() + i);
				return;
			}
			if (calatorii[i].getCod() == code)
				codeFound = 1;
			if (strcmp(calatorii[i].getLocalitateDestinatie(), destination) == 0)
				destinationFound = 1;

		}
		
		if (codeFound == 0)
			error = "No trip with this code \n";
		if(destinationFound == 0)
			error += "No trip with this destination \n";
		throw DeleteException{ error.c_str() };
	}
	void changeRepoType(bool textOrCSV);
	std::vector<CalatorieAutobuz> getAllBusTrips();
	std::vector<CalatorieAvion> getAllAirplaneTrips();
	void rezervaLocuri(std::string cod, int nr_locuri);
	int getSize();
	Calatorie get(int poz);
	void update(Calatorie a, Calatorie b);
	void deleteTripByCode(std::string code){
		bool codeFound = 0;
		std::string error = "";
		for (int i = 0; i < calatorii.size(); ++i) {
			if (calatorii[i].getCod() == code) {
				calatorii.erase(calatorii.begin() + i);
				return;
			}
			if (calatorii[i].getCod() == code)
				codeFound = 1;

		}

		if (codeFound == 0)
			error = "No trip with this code \n";
		throw DeleteException{ error.c_str() };
	}

	void scrieCalatoriiDinVectorInFisier(std::vector<Calatorie> calatorii);
	
};

