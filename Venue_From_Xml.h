#pragma once
#include "tinyxml.h"

class Venue_from_XML
{
public:
	static Venue* Get_Venue_From_XML(TiXmlNode* venue_node);

private:
	static Address* Get_Address(TiXmlNode* address_node);
	static Seat_Row* Get_Seat_Row(TiXmlNode* seat_row_node);
	static void Get_Seats(TiXmlNode* seat_row_node);
	static Seat* Get_Seat(TiXmlNode* seat_node, Seat_Row* row);
};