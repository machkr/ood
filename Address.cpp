#include <iostream>
#include <string>

#include "Address.h"

using namespace std;

Address::Address(string Street_Address, string City, string State, string ZIP_Code)
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