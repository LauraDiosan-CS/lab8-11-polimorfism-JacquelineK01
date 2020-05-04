#pragma once
#include <string.h>
class User
{
private:
	char username[100];
	char password[100];
public:
	User(const char* username, const char* password);
	~User();
	bool operator==(const User& b);
};

