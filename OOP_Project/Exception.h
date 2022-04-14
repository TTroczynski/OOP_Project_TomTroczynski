#pragma once
#include <iostream>
#include <string>

class Exception
{
	std::string message;

public:
	Exception(const std::string& fault);

	std::string getFault();

};

