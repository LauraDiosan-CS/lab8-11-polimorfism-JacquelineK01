#include "User.h"

User::User(const char* username, const char* password)
{
	strcpy(this->username, username);
	strcpy(this->password, password);
}

User::~User()
{
}

bool User::operator==(const User& b)
{
	return strcmp(username, b.username) == 0 && strcmp(password, b.password) == 0;
}
