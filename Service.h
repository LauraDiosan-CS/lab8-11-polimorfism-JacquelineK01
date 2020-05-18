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
	void deleteTrip2(Calatorie c) { 
		//for (int i = 0; i < repo.getSize(); ++i)
			//std::cout << repo.get(0).getCod() << '\n';
		char data[100];
		char destinatie[100]; 
		char plecare[100];

		int size = repo.getSize();
		std::string cod = c.getCod();
		strcpy(data, c.getDataPlecarii());
		strcpy(destinatie, c.getLocalitateDestinatie());
		strcpy(plecare, c.getLocalitatePlecare());
		for (int i = 0; i < size; ++i)
		{
			//std:: cout << repo.get(i).getCod() << " " << cod <<" "<< strcmp(repo.get(i).getLocalitatePlecare(), destinatie)<<'\n';
			//std::cout << repo.get(i).getLocalitateDestinatie() << ":" << destinatie<<'\n';
			if (compareDates(repo.get(i).getDataPlecarii(), data) == 0 && (strcmp(repo.get(i).getLocalitateDestinatie(), plecare) == 0 || strcmp(repo.get(i).getLocalitatePlecare(), destinatie) == 0))
			{
				std::cout << repo.get(i).getCod() << " " << cod << '\n';
				this->repo.deleteTripByCode(repo.get(i).getCod());
				i = 0;
				size--;
			}
			if (repo.get(i).getCod() == cod) {
				std::cout << repo.get(i).getCod() << " " << cod << '\n';
				this->repo.deleteTripByCode(repo.get(i).getCod());
				i = 0;
				size--;

			}
		}
		std::cout << "******:" << getSize() << '\n';
	}
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
	void emptyTrips() { repo.emptyTrips(); }
	int getSize() { return repo.getSize(); }
	Calatorie getElementAtPosition(int poz) { return repo.get(poz); }
	
	int compareDates(char* d1, char* d2) {
		int y1 = d1[strlen(d1) - 1] - '0' + (d1[strlen(d1) - 2] - '0') * 10 + (d1[strlen(d1) - 3] - '0') * 100 + (d1[strlen(d1) - 4] - '0') * 1000;
		int y2 = (d2[strlen(d2) - 1] - '0') + (d2[strlen(d2) - 2] - '0') * 10 +( d2[strlen(d2) - 3] - '0') * 100 + (d2[strlen(d2) - 4] - '0') * 1000;

		int m1 = (d1[strlen(d1) - 6] - '0') + (d1[strlen(d1) - 7] - '0') * 10;
		int m2 = (d2[strlen(d2) - 6] - '0') + (d2[strlen(d2) - 7] - '0') * 10;


		int day1 = (d1[strlen(d1) - 9] - '0') + (d1[strlen(d1) - 10] - '0') * 10;
		int day2 = (d2[strlen(d2) - 9] - '0') + (d2[strlen(d2) - 10] - '0') * 10;

		//std::cout << day1 << " " << m1 << " " << y1 << '\n';
		//std::cout << day2 << " " << m2 << " " << y2 << '\n';

		if (y1 < y2)
			return 1;
		if (y1 > y2)
			return -1;
		if (m1 < m2)
			return 1;
		if (m1 > m2)
			return -1;

		if (day1 < day2)
			return 1;
		if (day1 > day2)
			return -1;
		return 0;

	}
};

