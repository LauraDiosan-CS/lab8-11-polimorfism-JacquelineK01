#include "UI.h"

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

void UI::show_menu_1()
{
	char username[30], password[30];
	std::cout << "---------------------------------------------------\n";
	std::cout << "         WELCOME! Please Log In or Exit\n";
	std::cout << "         CSV or TXT: ";
	std::cin >> username;
	std::cout << "---------------------------------------------------\n";
	if (strcmp(username, "CSV") == 0) {
		this->textOrCSV = 1;
		service.changeTxtOrCSV(1);
	}
	else {
		this->textOrCSV = 0;
		service.changeTxtOrCSV(0);
	}
	while (isLoggedIn == 0)
	{
		std::cout << "\n";
		std::cout << "Username:";
		std::cin >> username;
		std::cout << "Password:";
		std::cin >> password;
		if (strcmp(username, "exit") == 0)
			break;
		try {
			logInService.loginUser(username, password);
			isLoggedIn = 1;
			show_menu_2();
		}
		catch (std::exception& e) {
			std::cout << e.what() << '\n';
		}
	}
}

void UI::show_menu_2()
{
	std::cout << "\n";
	std::cout << "---------------------------------------------------\n";
	std::cout << "         Welcome! Choose an option:\n\n";
	while (isLoggedIn) {
		std::cout << "       1. Cauta calatorii dint-o data\n";
		std::cout << "       2. Rezerva locuri pentru o calatorie\n";
		std::cout << "       3. Logout (User: exit - Password: exit)\n";
		std::cout << "---------------------------------------------------\n";
		int option;
		std::cout << "Input option:";
		std::cin >> option;
		if (option == 3)
		{
			isLoggedIn = 0;
			break;
		}
		else if (option == 2)
			option_2();
		else if (option == 1)
			option_1();
	}
}

void UI::option_1()
{
	char date[50];
	std::cout << "Input date by this format dd.mm.yyyy: ";
	std::cin >> date;
	std::vector<CalatorieAutobuz> calatoriiBus = service.calatoriiAutobuzInData(date);
	std::vector<CalatorieAvion> calatoriiAvion = service.calatoriiAvionInData(date);
	service.scrieCalatoriiInFisier(calatoriiBus, calatoriiAvion);
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