#include "UI.h"
#include <string>
UI::UI()
{
	isLoggedIn = 0;
	textOrCSV = 0;
}

UI::UI(const Service& service, LogInService& logInService)
{
	this->service = service;
	this->logInService = logInService;
	this->isLoggedIn = 0;
	this->textOrCSV = 0;
}

UI::~UI()
{
}

void UI::show_menu_2()
{
	std::cout << "\n";
	std::cout << "---------------------------------------------------\n";
	std::cout << "         Welcome! Choose an option:\n\n";
	while (isLoggedIn) {
		std::cout << "       1. Cauta calatorii dint-o data\n";
		std::cout << "       2. Rezerva locuri pentru o calatorie\n";
		std::cout << "       3. Adauga calatorie autobuz\n";
		std::cout << "       4. Adauga calatorie avion\n";
		std::cout << "       5. Sterge calatorie\n";
		std::cout << "       6. Update calatorie autobuz\n";
		std::cout << "       7. Update calatorie avion\n";
		std::cout << "       8. Logout (User: exit - Password: exit)\n";
		std::cout << "---------------------------------------------------\n";
		int option;
		std::cout << "Input option:";
		std::cin >> option;
		if (option == 8)
		{
			isLoggedIn = 0;
			break;
		}
		else if (option == 2)
			option_2();
		else if (option == 1)
			option_1();
		else if (option == 3)
			option_3();
		else if (option == 4)
			option_4();
		else if (option == 5)
			option_5();
		else if (option == 6)
			option_6();
		else if (option == 7)
			option_7();

	}
}

void UI::option_1()
{
	char date[50];
	std::cout << "Input date by this format dd.mm.yyyy: ";
	std::cin >> date;
	std::vector<CalatorieAutobuz> calatoriiBus = service.calatoriiAutobuzInData(date);
	std::vector<CalatorieAvion> calatoriiAvion = service.calatoriiAvionInData(date);
	std::vector<Calatorie> calatorii = service.calatoriiInData(date);
	service.scrieCalatoriiInFisier(calatoriiBus, calatoriiAvion);
	service.scrieCalatoriiDinVectorInFisier(calatorii);
}

void UI::option_2()
{
	std::string cod;
	int nrLocuri;
	std::cout << "Code:";
	std::cin >> cod;
	std::cout << "Number of persons:";
	std::cin >> nrLocuri;
	try {
		service.rezervare(cod, nrLocuri);
		std::cout << "Booking successfully created!\n";
	}
	catch (std::exception & e) {
		std::cout << e.what()<<'\n';
	}
}

void UI::option_4()
{
	std::string escala;
	bool escalaSauNu = 0;
	std::string cod;
	char localitate_plecare[100];
	char localitate_destinatie[100];
	char data_plecarii[100];
	int nr_loc_totale;
	int nr_loc_rezervate;
	std::cout << "Cod:";
	std::cin >> cod;
	std::cout << "Plecare:";
	std::cin >> localitate_plecare;
	std::cout << "Destinatie:";
	std::cin >> localitate_destinatie;
	std::cout << "Data plecarii:";
	std::cin >> data_plecarii;
	std::cout << "Escala:";
	std::cin >> escala;
	if (escala == "da")
		escalaSauNu = 1;
	std::cout << "Nr. locuri totale:";
	std::cin >> nr_loc_totale;
	std::cout << "Nr. locuri rezervare:";
	std::cin >> nr_loc_rezervate;

	CalatorieAvion c{ cod, localitate_plecare, localitate_destinatie, data_plecarii,escalaSauNu, nr_loc_totale, nr_loc_rezervate };
	try {
		service.addTrip(c);
	}
	catch (std::exception & e) {
		std::cout << e.what() << '\n';
	}
}

void UI::option_5()
{
	std::string cod;
	char localitate_destinatie[100];
	std::cout << "Cod:";
	std::cin >> cod;
	std::cout << "Destinatie:";
	std::cin >> localitate_destinatie;
	try {
		service.deleteTrip(cod, localitate_destinatie);
	}
	catch (std::exception & e) {
		std::cout << e.what() << '\n';
	}
}

void UI::option_6()
{
	int nr_zile_durata;
	std::string cod;
	char localitate_plecare[100];
	char localitate_destinatie[100];
	char data_plecarii[100];
	int nr_loc_totale;
	int nr_loc_rezervate;
	std::cout << "Cod:";
	std::cin >> cod;
	std::cout << "Plecare:";
	std::cin >> localitate_plecare;
	std::cout << "Destinatie:";
	std::cin >> localitate_destinatie;
	std::cout << "Data plecarii:";
	std::cin >> data_plecarii;
	std::cout << "Durata calatorie:";
	std::cin >> nr_zile_durata;
	std::cout << "Nr. locuri totale:";
	std::cin >> nr_loc_totale;
	std::cout << "Nr. locuri rezervare:";
	std::cin >> nr_loc_rezervate;

	CalatorieAutobuz c{ cod, localitate_plecare, localitate_destinatie, data_plecarii, nr_zile_durata, nr_loc_totale, nr_loc_rezervate };
	try {
		service.deleteTripByCode(cod);
		service.addTrip(c);
	}
	catch (std::exception & e) {
		std::cout << e.what() << '\n';
	}
}

void UI::option_7()
{
	std::string escala;
	bool escalaSauNu = 0;
	std::string cod;
	char localitate_plecare[100];
	char localitate_destinatie[100];
	char data_plecarii[100];
	int nr_loc_totale;
	int nr_loc_rezervate;
	std::cout << "Cod:";
	std::cin >> cod;
	std::cout << "Plecare:";
	std::cin >> localitate_plecare;
	std::cout << "Destinatie:";
	std::cin >> localitate_destinatie;
	std::cout << "Data plecarii:";
	std::cin >> data_plecarii;
	std::cout << "Escala:";
	std::cin >> escala;
	if (escala == "da")
		escalaSauNu = 1;
	std::cout << "Nr. locuri totale:";
	std::cin >> nr_loc_totale;
	std::cout << "Nr. locuri rezervare:";
	std::cin >> nr_loc_rezervate;

	CalatorieAvion c{ cod, localitate_plecare, localitate_destinatie, data_plecarii,escalaSauNu, nr_loc_totale, nr_loc_rezervate };
	try {
		service.deleteTripByCode(cod);
		service.addTrip(c);
	}
	catch (std::exception & e) {
		std::cout << e.what() << '\n';
	}
}

