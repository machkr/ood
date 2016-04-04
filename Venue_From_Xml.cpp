#include <iostream>
#include "tinyxml.h"
#include "Venue.h"
#include "Venue_from_XML.h"

using namespace std;

Venue* Venue_from_XML::Get_Venue_From_XML(TiXmlNode* venue_node)
{
	string venue_name;

	TiXmlNode* name_node = venue_node->FirstChild();
	assert(name_node != 0);
	//cout << name_node->Value() << endl;

	TiXmlNode* name_text_node = name_node->FirstChild();
	assert(name_text_node != 0);
	venue_name = name_text_node->Value();

	TiXmlNode* address_node = name_node->NextSibling();
	assert(address_node != 0);
	//cout << address_node->Value() << endl;

	Address* address = Get_Address(address_node);

	TiXmlNode* seat_row_node = address_node->NextSibling();
	assert(seat_row_node != 0);

	Get_Seats(seat_row_node);

	Venue* venue = new Venue(venue_name, *address);
	return venue;
}

Address* Venue_from_XML::Get_Address(TiXmlNode* address_node)
{
	string street_address;
	string city;
	string state;
	string zip_code;

	TiXmlNode* street_node = address_node->FirstChild();
	assert(street_node != 0);
	street_address = street_node->FirstChild()->Value();
	
	TiXmlNode* city_node = street_node->NextSibling();
	assert(city_node != 0);
	city = city_node->FirstChild()->Value();
	
	TiXmlNode* state_node = city_node->NextSibling();
	assert(state_node != 0);
	state = state_node->FirstChild()->Value();
	
	TiXmlNode* zip_code_node = state_node->NextSibling();
	assert(zip_code_node != 0);
	zip_code = zip_code_node->FirstChild()->Value();

	Address* address = new Address(street_address, city, state, zip_code);

	return address;
}

Seat_Row* Venue_from_XML::Get_Seat_Row(TiXmlNode* seat_row_node)
{
	string row_name;

	//cout << seat_row_node->Value() << endl;
	TiXmlNode* name_node = seat_row_node->FirstChild("name");
	assert(name_node != 0);
	//cout << name_node->Value() << ": ";
	row_name = name_node->FirstChild()->Value();

	Seat_Row* row = new Seat_Row(row_name);

	TiXmlNode* seat_node = seat_row_node->FirstChild("seat");
	while (seat_node != 0)
	{
		//cout << seat_node->Value() << " ";
		Seat* new_seat = Get_Seat(seat_node, row_name);
		row->Add_Seat(new_seat);
		seat_node = seat_node->NextSibling();
	}

	return row;
}

/*void Venue_from_XML::Get_Seats(TiXmlNode* seat_row_node)
{
	while (seat_row_node != 0)
	{
		Get_Seat_Row(seat_row_node);
		seat_row_node = seat_row_node->NextSibling();
	}
}*/

Seat* Venue_from_XML::Get_Seat(TiXmlNode* seat_node, Seat_Row* row)
{
	string seat_number;
	string section_name;

	TiXmlNode* number_node = seat_node->FirstChild("number");
	//cout << number_node->Value() << ": ";
	seat_number = number_node->FirstChild()->Value();

	TiXmlNode* section_node = seat_node->FirstChild("section");
	//cout << section_node->Value() << ": ";
	section_name = section_node->FirstChild()->Value();
	Seat* seat = new Seat(stoi(seat_number), row);
	return seat;
}