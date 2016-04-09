#include <iostream>

#include "Venue.h"
#include "Venue_From_User.h"
#include "Venue_From_XML.h"

using namespace std;

int main()
{
	cout << "This is the Level 0 Ticket Booth program!" << endl;

	Venue* venue = Venue_From_XML::Get_Venue_From_XML();
	venue->Display_All();

	cin.get();
	return 0;
}
