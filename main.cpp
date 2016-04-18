#include <iostream>

#include "Venue.h"
#include "Venue_From_User.h"
#include "Venue_From_XML.h"
#include "menu.h"
#include "Command_Processor.h"

using namespace std;

int main()
{
	Venue* venues[999];
	int nr_states = 0;

	cout << "This is the Level 0 Ticket Booth program!" << endl;
	nr_venues
	Venue* venue = Venue_From_XML::Get_Venue_From_XML();
	venue->Display_All();

	cin.get();
	return 0;
}
