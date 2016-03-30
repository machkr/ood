#pragma once
#include <string>
#include "Seat_Row.h"
#include "Section.h"
using namespace std;

class Seat
{
private:
	string seat_row_name;
	int seat_number;
	Seat_Row* row;
	Section* section;


public:
	Seat(string Row_Name, int Seat_Number, Seat_Row* Row);
	void Set_Section(Section* new_section);
	Section* Get_Section();
	
	void Display() const;
};
