#include <iostream>
#include <string>
#include <sstream>
#include "Address.h"

using namespace std;

Address::Address(const string& Street_Address, const string& City, const string& State, int ZIP_Code)
{
	street_address = Street_Address;
	city = City;
	state = State;
	zip_code = ZIP_Code;
}

void Address::Display() const
{
	cout.fill('0');
	cout << street_address << endl;
	cout << city << ", " << state << " ";
	cout.width(5);
	cout << zip_code << endl;
}