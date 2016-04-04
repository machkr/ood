#include <iostream>
#include <sstream>

#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Venue.h"
#include "Section.h"
#include "tinyxml.h"
#include "Venue_From_Xml.h"

using namespace std;

int main()
{
	cout << "This is the Level 0 Ticket Booth program!" << endl;

	string filename = "Venue.xml";
	TiXmlDocument doc(filename);
	bool loadOkay = doc.LoadFile();

	if (!loadOkay)
	{
		cout << "Could not load file " << filename << endl;
		cout << "Error='" << doc.ErrorDesc() << "'. Exiting.\n";
		cin.get();
		exit(1);
	}

	cout << filename << " read from disk " << endl;
	//cout << "Printing via doc.Print \n";
	//doc.Print(stdout);
	
	TiXmlNode* venue_file_node = doc.FirstChild("venue_file");
	assert(venue_file_node != 0);
	cout << venue_file_node->Value() << endl;

	TiXmlNode* venue_node = venue_file_node->FirstChild();
	assert(venue_node != 0);
	cout << venue_node->Value() << endl;

	Venue* venue = Venue_from_XML::Get_Venue_From_XML(venue_node);
	venue->Display_All;

	cin.get();
	return 0;
}
