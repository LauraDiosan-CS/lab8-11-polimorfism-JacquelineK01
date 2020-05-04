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

    void show_menu_1();
    void show_menu_2();
    void option_1();
    void option_2();
};

