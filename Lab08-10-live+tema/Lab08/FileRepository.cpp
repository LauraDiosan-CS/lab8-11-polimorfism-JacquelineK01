#include "FileRepository.h"
#include <iostream>
FileRepository::FileRepository()
{
	strcpy(this->airplaneTripsFileName," ");
	strcpy(this->busTripsFileName, " ");
	strcpy(this->writeFileName, " ");
	this->textOrCSV = 0;
}

FileRepository::~FileRepository()
{
}

void FileRepository::loadBusTripsFromFile()
{	
	this->calatoriiAutobuz = {};
	CalatorieAutobuz calatorie;
	std::string cod;
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
		codes.push_back(cod);
		calatorii.push_back(calatorie);
	}
	sort(codes.begin(), codes.end());
	fin.close();
}

void FileRepository::loadAirplaneTripsFromFile()
{
	this->calatoriiAvion = {};
	CalatorieAvion calatorie;
	std::string cod;
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
		codes.push_back(cod);
		calatorii.push_back(calatorie);
	}
	sort(codes.begin(), codes.end());
	fin.close();
}

void FileRepository::writeTripsToCSVFile(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion)
{
	std::ofstream fout(writeFileName);
	fout << "Cod,Plecare,Destinatie,Data,Durata(zile),Escala,Nr. Locuri totale,Nr. Locuri Rezervate\n";
	for (int i = 0; i < calatoriiAutobuz.size(); ++i) {
		fout << '"' << calatoriiAutobuz[i].getCod() << "\","
			<< '"' << calatoriiAutobuz[i].getLocalitatePlecare() << "\","
			<< '"' << calatoriiAutobuz[i].getLocalitateDestinatie() << "\","
			<< '"' << calatoriiAutobuz[i].getDataPlecarii() << "\","
			<< '"' << calatoriiAutobuz[i].getNrZileDurata() << "\","
			<< '"' << "-" << "\","
			<< '"' << calatoriiAutobuz[i].getNrLocTotale() << "\","
			<< '"' << calatoriiAutobuz[i].getNrLocRezervate() << '"' << '\n';
	}
	for (int i = 0; i < calatoriiAvion.size(); ++i) {
		fout << '"' << calatoriiAvion[i].getCod() << "\","
			<< '"' << calatoriiAvion[i].getLocalitatePlecare() << "\","
			<< '"' << calatoriiAvion[i].getLocalitateDestinatie() << "\","
			<< '"' << calatoriiAvion[i].getDataPlecarii() << "\","
			<< '"' << " " << "\",";
		if (calatoriiAvion[i].getEscala() == 1)
			fout << '"' << "DA" << "\",";
		else
			fout << '"' << "NU" << "\",";
			fout << '"' << calatoriiAvion[i].getNrLocTotale() << "\","
			<< '"' << calatoriiAvion[i].getNrLocRezervate() << '"' << '\n';
	}
}

void FileRepository::changeRepoType(bool textOrCSV)
{
	this->textOrCSV = textOrCSV;
	if (textOrCSV == 1) {
		writeFileName[strlen(writeFileName) - 1] = 'V';
		writeFileName[strlen(writeFileName) - 2] = 'S';
		writeFileName[strlen(writeFileName) - 3] = 'C';
	}
}

void FileRepository::writeTripsToTxtFile(std::vector<CalatorieAutobuz> calatoriiAutobuz, std::vector<CalatorieAvion> calatoriiAvion)
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

std::vector<CalatorieAutobuz> FileRepository::getAllBusTrips()
{
	return calatoriiAutobuz;
}

std::vector<CalatorieAvion> FileRepository::getAllAirplaneTrips()
{
	return calatoriiAvion;
}

void FileRepository::rezervaLocuri(std::string cod, int nr_locuri)
{
	bool gasit = 0;
	for(int i = 0; i < calatoriiAutobuz.size() && !gasit; ++i)
		if (calatoriiAutobuz[i].getCod() == cod)
		{
			gasit = 1;
			if (nr_locuri > calatoriiAutobuz[i].getNrLocTotale() - calatoriiAutobuz[i].getNrLocRezervate())
				throw RepoException("Numar de locuri indisponibil");
			else
				calatoriiAutobuz[i].setNrLocRezervate(nr_locuri + calatoriiAutobuz[i].getNrLocRezervate());
		}
	for (int i = 0; i < calatoriiAvion.size() && !gasit; ++i)
		if (calatoriiAvion[i].getCod() == cod)
		{
			gasit = 1;
			if (nr_locuri > calatoriiAvion[i].getNrLocTotale() - calatoriiAvion[i].getNrLocRezervate())
				throw RepoException("Numar de locuri indisponibil");
			else
				calatoriiAvion[i].setNrLocRezervate(nr_locuri + calatoriiAvion[i].getNrLocRezervate());
		}
	if (!gasit)
		throw RepoException("Cod invalid");
	else
		if (textOrCSV == 0)
			writeTripsToTxtFile(calatoriiAutobuz, calatoriiAvion);
		else
			writeTripsToCSVFile(calatoriiAutobuz, calatoriiAvion);
}

int FileRepository::getSize()
{
	return calatorii.size();
}

Calatorie FileRepository::get(int poz)
{
	return calatorii[poz];
}

void FileRepository::update(Calatorie a, Calatorie b)
{

	for (auto i = calatorii.begin(); i != calatorii.end(); ++i)
		if (*i == a) {
			calatorii.erase(i);
			break;
		}
	calatorii.push_back(b);
}

