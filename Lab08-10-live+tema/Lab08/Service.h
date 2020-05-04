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
	std::vector<CalatorieAvion> calatoriiAvionInData(const char* data);
	void scrieCalatoriiInFisier(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion);
};

