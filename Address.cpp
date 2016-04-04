#include <iostream>
#include <string>

#include "Address.h"

using namespace std;

Address::Address(const string& Street_Address, const string& City, const string& State, const string& ZIP_Code)
{
	street_address = Street_Address;
	city = City;
	state = State;
	zip_code = ZIP_Code;
}

void Address::Display() const
{
	cout << street_address << endl;
	cout << city << ", " << state << " ";
	cout << zip_code << endl;
}