#pragma once
#include <exception>
#include <string.h>

class RepoException:public std::exception 
{
private:
	char message[100];
	char error[100];
public:
	RepoException(const char* message);
	const char* what() const noexcept override;
};

