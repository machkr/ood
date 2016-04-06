#include <iostream>
#include <sstream>

#include "Venue.h"
#include "tinyxml.h"
#include "Venue_From_User.h"
#include "Venue_From_XML.h"

using namespace std;

int main()
{
	string filename;

	cout << "This is the Level 0 Ticket Booth program!" << endl;

	cout << "Please enter the XML filename you would like to input: ";
	getline(cin, filename);

	Venue* venue = Venue_From_XML::Get_Venue_From_XML(filename);
	venue->Display_All();

	cin.get();
	return 0;
}
