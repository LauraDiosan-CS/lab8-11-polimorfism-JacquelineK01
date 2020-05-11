#pragma once
#include <string.h>
#include <fstream>
#include <vector>
#include "ValidationException.h"
class LogInService
{
private:
	char fileName[100];
public:
	LogInService();
	LogInService(const char* fileName);
	void loginUser(const char* username, const char* password);
};

