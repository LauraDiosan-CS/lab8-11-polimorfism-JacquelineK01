#include "CalatorieAvion.h"

CalatorieAvion::CalatorieAvion() : Calatorie{} {
	this->esteEscala = 0;

}

CalatorieAvion::CalatorieAvion(std::string cod, const char* localitate_plecare, const char* localitate_destinatie, const char* data_plecarii, bool esteEscala, int nr_loc_totale, int nr_loc_rezervate) : Calatorie{ cod, localitate_plecare, localitate_destinatie, data_plecarii, nr_loc_totale, nr_loc_rezervate } {
	this->esteEscala = esteEscala;
}

CalatorieAvion::CalatorieAvion(const CalatorieAvion& b) {
	this->cod = b.cod;

	strcpy_s(this->localitate_plecare, strlen(b.localitate_plecare) + 1, b.localitate_plecare);

	strcpy_s(this->localitate_destinatie, strlen(b.localitate_destinatie) + 1, b.localitate_destinatie);

	strcpy_s(this->data_plecarii, strlen(b.data_plecarii) + 1, b.data_plecarii);

	this->esteEscala = b.esteEscala;

	this->nr_loc_totale = b.nr_loc_totale;

	this->nr_loc_rezervate = b.nr_loc_rezervate;
}

bool CalatorieAvion::getEscala()
{
	return esteEscala;
}

void CalatorieAvion::setEscala(bool x)
{
	this->esteEscala = x;
}

CalatorieAvion::~CalatorieAvion()
{
	
}
