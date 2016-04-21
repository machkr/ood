#pragma once
#include <iostream>
#include <string>
#include "Seat_Row.h"
#include "Section.h"

using namespace std;

// Forward declarations to prevent circular dependency error
// http://stackoverflow.com/a/628079

class Seat_Row;
class Section;

class Seat
{
private:
	int seat_number;
	const Seat_Row* row;
	Section* section;

public:
    Seat(int Seat_Number, Seat_Row* Row);
	Seat(int Seat_Number);
    void Set_Section(Section* new_section);
    Section* Get_Section();
	void Set_Seat_Row(Seat_Row* new_seat_row);
    const Seat_Row* Get_Seat_Row() const;
    void Display() const;
    int Get_Seat_Number() const { return seat_number; };
	void Output_Xml(std::ofstream& outfile) const;
};
