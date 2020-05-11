#include "DeleteException.h"
#include <iostream>
DeleteException::DeleteException(const char* message)
{
	strcpy(error, "Delete error: ");
	strcpy(this->message, message);
	strcat(error, message);
}

const char* DeleteException::what() const noexcept
{
	return error;
}
