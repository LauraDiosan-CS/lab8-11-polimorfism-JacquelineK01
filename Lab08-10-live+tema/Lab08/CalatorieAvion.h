#pragma once
#include "Calatorie.h"
class CalatorieAvion : public Calatorie {
private:
	bool esteEscala;
public:
	CalatorieAvion();
	CalatorieAvion(std::string cod, const char* localitate_plecare, const char* localitate_destinatie, const char* data_plecarii, bool esteEscala, int nr_loc_totale, int nr_loc_rezervate);
	CalatorieAvion(const CalatorieAvion& b);
	~CalatorieAvion();

	bool getEscala();
	void setEscala(bool x);
};

