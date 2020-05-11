#pragma once
#include <exception>
#include <string.h>

class DeleteException :public std::exception
{
private:
	char message[100];
	char error[100];
public:
	DeleteException(const char* message);
	const char* what() const noexcept override;
};

