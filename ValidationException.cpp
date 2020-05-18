#include "ValidationException.h"
#include <iostream>

ValidationException::ValidationException(const char* message)
{
	strcpy(error, "Repository error: ");
	strcpy(this->message, message);
	strcat(error,  message);
}

const char* ValidationException::what() const noexcept
{
	return error;
}
