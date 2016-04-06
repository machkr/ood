#include <iostream>
#include "tinyxml.h"
#include "Venue.h"
#include "Venue_From_XML.h"

using namespace std;

Venue* Venue_From_XML::Get_Venue_From_XML(string filename)
{
	TiXmlDocument doc(filename);
	bool loadOkay = doc.LoadFile();

	if (!loadOkay)
	{
		cout << "Could not load " << filename << "." << endl;
		cout << "Error='" << doc.ErrorDesc() << "'. Exiting.\n";
		cin.get();
		exit(1);
	}

	cout << filename << " has been loaded successfully." << endl;

	TiXmlNode* venue_file_node = doc.FirstChild("venue_file");						//Node - Venue File
	assert(venue_file_node != 0);

	TiXmlNode* venue_node = venue_file_node->FirstChild();							//Node - Venue
	assert(venue_node != 0);

	TiXmlNode* name_node = venue_node->FirstChild();								//Node - Name
	assert(name_node != 0);

	TiXmlNode* name_text_node = name_node->FirstChild();							//Node - Venue Name
	assert(name_text_node != 0);
	string venue_name = name_text_node->Value();									//Get venue name

	TiXmlNode* address_node = name_node->NextSibling();								//Node - Address
	assert(address_node != 0);
	Address* address = Get_Address(address_node);									//Get address

	Venue* venue = new Venue(venue_name, *address);									//Create new venue

	TiXmlNode* seat_row_node = address_node->NextSibling();							//Node - Seat Row
	assert(seat_row_node != 0);
	//Seat_Row* seat_rows = Get_Seats(seat_row_node);

	return venue;																	//Return new venue
}

Address* Venue_From_XML::Get_Address(TiXmlNode* address_node)
{
	string venue_name;
	string street_address;
	string city;
	string state;
	int zip_code;

	TiXmlNode* street_node = address_node->FirstChild();							//Street Address node
	assert(street_node != 0);
	street_address = street_node->FirstChild()->Value();							//Get street address

	TiXmlNode* city_node = street_node->NextSibling();								//City node
	assert(city_node != 0);
	city = city_node->FirstChild()->Value();										//Get city

	TiXmlNode* state_node = city_node->NextSibling();								//State node
	assert(state_node != 0);
	state = state_node->FirstChild()->Value();										//Get state

	TiXmlNode* zip_code_node = state_node->NextSibling();							//Zip Code node
	assert(zip_code_node != 0);
	istringstream(zip_code_node->FirstChild()->Value()) >> zip_code;				//Get zip code

	Address* address = new Address(street_address, city, state, zip_code);			//Create new address
	return address;																	//Return new address
}

Seat_Row* Venue_From_XML::Get_Seats(TiXmlNode* seat_row_node)
{
	Seat_Row* seat_rows = NULL;

	while (seat_row_node != 0)
	{
		Get_Seat_Row(seat_row_node);
		seat_row_node = seat_row_node->NextSibling();
	}

	return seat_rows;
}

Seat_Row* Venue_From_XML::Get_Seat_Row(TiXmlNode* seat_row_node)
{
	string row_name;
	int number_of_seats;

	TiXmlNode* name_node = seat_row_node->FirstChild("name");						//Node - Row Name
	assert(name_node != 0);
	row_name = name_node->FirstChild()->Value();									//Get row name

	Seat_Row* row = new Seat_Row(row_name);

	TiXmlNode* seat_node = seat_row_node->FirstChild("seat");						//Node - Seat
	for (number_of_seats = 0; seat_node != 0; number_of_seats++)
	{
		Seat* seat = Get_Seat(seat_node);											//Create new seat
		seat->Set_Seat_Row(row);													//Set new seat row
		row->Add_Seat(seat);														//Add seat to row
		seat_node = seat_node->NextSibling();										//Iterate
	}

	number_of_seats = row->Number_of_Seats();
	return row;
}

Seat* Venue_From_XML::Get_Seat(TiXmlNode* seat_node)
{
	int seat_number;
	string section_name;

	TiXmlNode* number_node = seat_node->FirstChild("number");						//Node - Seat Number
	assert(number_node != 0);
	istringstream(number_node->FirstChild()->Value()) >> seat_number;				//Get seat number

	TiXmlNode* section_node = seat_node->FirstChild("section");						//Node - Seat Section
	assert(section_node != 0);
	section_name = section_node->FirstChild()->Value();								//Get seat section name

	Seat* new_seat = new Seat(seat_number);											//Create new seat
	return new_seat;																//Return new seat
}
