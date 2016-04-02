#pragma once
#include <string>

using namespace std;

class Address
{
private:
	string street_address;
	string city;
	string state;
	string zip_code;

public:
	Address(string Street_Address, string City, string State, string ZIP_Code);
	Address() {};

	void Display() const;
};