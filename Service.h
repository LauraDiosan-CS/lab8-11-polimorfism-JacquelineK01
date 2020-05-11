#pragma once
#include "FileRepository.h"
class Service
{
private:
	FileRepository repo;
	bool textOrCSV; // 0 txt , 1 CSV
public:
	Service(FileRepository repo) {
		this->repo = repo;
	};
	Service() {
		textOrCSV = 0;
	};
	~Service() {};
	void changeTxtOrCSV(bool textOrCSV);
	void rezervare(std::string cod, int nr_locuri);
	std::vector<CalatorieAutobuz> calatoriiAutobuzInData(const char* data);
	void addTrip(Calatorie c) { this->repo.addTrip(c); };
	void deleteTrip(std::string code, char* destination) { this->repo.deleteTrip(code, destination); };
	std::vector<CalatorieAvion> calatoriiAvionInData(const char* data);
	void scrieCalatoriiInFisier(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion);
	int getNumberOfTrips() { return this->repo.getSize(); };
	Calatorie getTripAtPos(int pos) { return this->repo.get(pos); };
	void deleteTripByCode(std::string cod) { this->repo.deleteTripByCode(cod); };
	std::vector<Calatorie> calatoriiInData(const char* data);
	void scrieCalatoriiDinVectorInFisier(std::vector<Calatorie> calatorii) {
		this->repo.scrieCalatoriiDinVectorInFisier(calatorii);
	};
};

