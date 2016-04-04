#include <iostream>
#include "tinyxml.h"
#include "Venue.h"
#include "Venue_From_XML.h"

using namespace std;

Venue* Venue_From_XML::Get_Venue_From_XML(TiXmlNode* venue_node)
{
	string venue_name;
	string street_address;
	string city;
	string state;
	int zip_code;

	TiXmlNode* name_node = venue_node->FirstChild();					//Name node
	assert(name_node != 0);

	TiXmlNode* name_text_node = name_node->FirstChild();				//Venue name node
	assert(name_text_node != 0);
	venue_name = name_text_node->Value();

	TiXmlNode* address_node = name_node->NextSibling();					//Address node
	assert(address_node != 0);

	TiXmlNode* street_node = address_node->FirstChild();				//Street Address node
	assert(street_node != 0);
	street_address = street_node->FirstChild()->Value();

	TiXmlNode* city_node = street_node->NextSibling();					//City node
	assert(city_node != 0);
	city = city_node->FirstChild()->Value();

	TiXmlNode* state_node = city_node->NextSibling();					//State node
	assert(state_node != 0);
	state = state_node->FirstChild()->Value();

	TiXmlNode* zip_code_node = state_node->NextSibling();				//Zip Code node
	assert(zip_code_node != 0);
	istringstream(zip_code_node->FirstChild()->Value()) >> zip_code;

	Address* address = new Address(street_address, city, state, zip_code);

	TiXmlNode* seat_row_node = address_node->NextSibling();
	assert(seat_row_node != 0);

	Get_Seats(seat_row_node);

	Venue* venue = new Venue(venue_name, *address);
	return venue;
}

Seat_Row* Venue_From_XML::Get_Seat_Row(TiXmlNode* seat_row_node)
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

void Venue_From_XML::Add_Seat_Rows(Venue* venue)
{

}

void Venue_From_XML::Add_Sections(Venue* venue)
{

}

void Venue_From_XML::Get_Seats(TiXmlNode* seat_row_node)
{
	while (seat_row_node != 0)
	{
		Get_Seat_Row(seat_row_node);
		seat_row_node = seat_row_node->NextSibling();
	}
}

Seat* Venue_From_XML::Get_Seat(TiXmlNode* seat_node, Seat_Row* row)
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
