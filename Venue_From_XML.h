#pragma once
#include <iostream>
#include "Venue.h"
#include "tinyxml.h"

class Venue_From_XML
{
public:
	void Get_Venue_From_XML();
	int* size() {return &i;};
	Venue** venues() {return venue;};

private:
	static Address* Get_Address(TiXmlNode* address_node);
	//static Seat_Row* Get_Seats(TiXmlNode* seat_row_node);
	static Seat_Row* Get_Seat_Row(TiXmlNode* seat_row_node);
	static Seat* Get_Seat(TiXmlNode* seat_node);
	int i;
	Venue** venue;
};
