#pragma once
#include "tinyxml.h"

class Venue_From_XML
{
public:
	static Venue* Get_Venue_From_XML(TiXmlNode* venue_node);

private:
	static void Add_Seat_Rows(Venue* venue);
	static void Add_Sections(Venue* venue);
};