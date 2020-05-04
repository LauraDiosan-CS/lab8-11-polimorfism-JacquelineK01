#pragma once
#include "Calatorie.h"
class CalatorieAutobuz : public Calatorie{
private:
	int nr_zile_durata;
public:
	CalatorieAutobuz();
	CalatorieAutobuz(std::string cod, const char* localitate_plecare, const char* localitate_destinatie, const char* data_plecarii, int nr_zile_durata, int nr_loc_totale, int nr_loc_rezervate);
	CalatorieAutobuz(const CalatorieAutobuz& b);
	~CalatorieAutobuz();

	int getNrZileDurata();
	void setNrZileDurata(int x);
};

