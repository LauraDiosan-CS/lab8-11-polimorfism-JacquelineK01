#pragma once
#include "Service.h"
#include "LogInService.h"
#include <iostream>
class UI
{
private:
    Service service;
    LogInService logInService;
    bool isLoggedIn, textOrCSV;
public:
    UI();
    UI(const Service& service, LogInService& logInService);
    ~UI();

	void show_menu_1()
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
			catch (std::exception & e) {
				std::cout << e.what() << '\n';
			}
		}
	}
    void show_menu_2();
    void option_1();
    void option_2();
	void option_3()
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
			service.addTrip(c);
		}
		catch (std::exception & e) {
			std::cout << e.what() << '\n';
		}

	}
    void option_4();
    void option_5();
    void option_6();
    void option_7();
};

