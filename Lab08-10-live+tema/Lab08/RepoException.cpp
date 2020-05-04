#include "RepoException.h"
#include <iostream>
RepoException::RepoException(const char* message)
{
	strcpy(error, "Repository error: ");
	strcpy(this->message, message);
	strcat(error, message);
}

const char* RepoException::what() const noexcept
{
	return error;
}
