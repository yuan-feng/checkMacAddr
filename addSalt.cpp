#include <iostream>
#include <string>
#include <functional>

#include "addSalt.hpp"


int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cerr << " Please give 1 argument: " << std::endl;
		std::cerr << "   -- the original mac address without colon" << std::endl;
		return -1 ; 
	}
	std::string macAddr = std::string(argv[1]);

	std::cout << "macAddr = " << macAddr << std::endl;

	addSalt(macAddr) ; 

	std::cout << "saltMacAddr = " << macAddr << std::endl;

	std::hash<std::string> strHash ; 
	auto thisMachineHash = strHash(macAddr) ; 
	std::cout << "thisMachineHash = " << thisMachineHash << std::endl;

	return 0;
}