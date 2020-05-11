#include "LogInService.h"
#include "User.h"
#include <iostream>
LogInService::LogInService()
{
	strcpy(this->fileName, " ");
}

LogInService::LogInService(const char* fileName)
{
	strcpy(this->fileName,fileName);

}

void LogInService::loginUser(const char* username, const char* password)
{
	User userNou = User{ username, password };
	std::ifstream fin(fileName);
	bool gasit = 0;
	char user[100];
	char pass[100];
	while (!fin.eof()) {
		fin >> user >> pass;
		User user2 = User{ user, pass };
		if (user2 == userNou)
			gasit = 1;
	}
	fin.close();
	if (!gasit)
		throw ValidationException("Wrong username or password!");
}
