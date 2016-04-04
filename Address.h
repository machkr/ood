#pragma once
#include <string>

using namespace std;

class Address
{
private:
	string street_address;
	string city;
	string state;
	int zip_code;

public:
	Address(const string& Street_Address, const string& City, const string& State, int ZIP_Code);
	Address() {};

	const string Street_Address() const { return street_address; };
	const string City() const { return city; };
	const string State() const { return state; };
	int ZIP_Code() const { return zip_code; };

	void Display() const;
};