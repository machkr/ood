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

	string Street_Address() { return street_address; };
	string City() { return city; };
	string State() { return state; };
	string ZIP_Code() { return zip_code; };

	void Display() const;
};