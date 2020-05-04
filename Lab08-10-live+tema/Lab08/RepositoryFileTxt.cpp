#include "RepositoryFileTxt.h"
/*
RepositoryFileTxt::RepositoryFileTxt()
{
	strcpy(this->airplaneTripsFileName, " ");
	strcpy(this->busTripsFileName, " ");
	strcpy(this->writeFileName, " ");
	this->textOrCSV = 0;
}

RepositoryFileTxt::~RepositoryFileTxt()
{
}


void RepositoryFileTxt::loadBusTripsFromFile()
{
	
		this->calatoriiAutobuz = {};
		CalatorieAutobuz calatorie;
		int cod;
		char localitate_plecare[100];
		char localitate_destinatie[100];
		char data_plecarii[100];
		int nr_loc_totale;
		int nr_loc_rezervate;
		int nr_zile;
		std::ifstream fin(busTripsFileName);
		while (!fin.eof()) {
			fin >> cod >> localitate_plecare >> localitate_destinatie >> data_plecarii >> nr_zile >> nr_loc_totale >> nr_loc_rezervate;
			calatorie = CalatorieAutobuz{ cod, localitate_plecare, localitate_destinatie, data_plecarii, nr_zile, nr_loc_totale, nr_loc_rezervate };
			calatoriiAutobuz.push_back(calatorie);
		}
		fin.close();
	
}

void RepositoryFileTxt::loadAirplaneTripsFromFile()
{
	this->calatoriiAvion = {};
	CalatorieAvion calatorie;
	int cod;
	char localitate_plecare[100];
	char localitate_destinatie[100];
	char data_plecarii[100];
	int nr_loc_totale;
	int nr_loc_rezervate;
	bool escala;
	std::ifstream fin(airplaneTripsFileName);
	while (!fin.eof()) {
		fin >> cod >> localitate_plecare >> localitate_destinatie >> data_plecarii >> escala >> nr_loc_totale >> nr_loc_rezervate;
		calatorie = CalatorieAvion{ cod, localitate_plecare, localitate_destinatie, data_plecarii, escala, nr_loc_totale, nr_loc_rezervate };
		calatoriiAvion.push_back(calatorie);
	}
	fin.close();
}

void RepositoryFileTxt::writeTripsToFile(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion)
{
	std::ofstream fout(writeFileName);
	for (int i = 0; i < calatoriiAutobuz.size(); ++i)
		fout << "Cod: " << calatoriiAutobuz[i].getCod() << " Plecare: " << calatoriiAutobuz[i].getLocalitatePlecare() << " Destinatie: " << calatoriiAutobuz[i].getLocalitateDestinatie() << " Data: " << calatoriiAutobuz[i].getDataPlecarii() << " Durata(zile): " << calatoriiAutobuz[i].getNrZileDurata() << " Nr.Locuri Totale:" << calatoriiAutobuz[i].getNrLocTotale() << " Nr.Locuri Rezervate: " << calatoriiAutobuz[i].getNrLocRezervate() << '\n';
	for (int i = 0; i < calatoriiAvion.size(); ++i)
	{
		fout << "Cod: " << calatoriiAvion[i].getCod() << " Plecare: " << calatoriiAvion[i].getLocalitatePlecare() << " Destinatie: " << calatoriiAvion[i].getLocalitateDestinatie() << " Data: " << calatoriiAvion[i].getDataPlecarii() << " Escala: ";
		if (calatoriiAvion[i].getEscala() == true)
			fout << "DA";
		else
			fout << "NU";
		fout << " Nr.Locuri Totale:" << calatoriiAvion[i].getNrLocTotale() << " Nr.Locuri Rezervate: " << calatoriiAvion[i].getNrLocRezervate() << '\n';
	}
}
*/