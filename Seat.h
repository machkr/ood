#pragma once
#include <iostream>
#include <string>
#include "Seat_Row.h"
#include "Section.h"
using namespace std;

// Forward declarations to prevent circular dependecny error
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
    void Set_Section(Section* new_section);
    Section* Get_Section();
    const Seat_Row* Get_Seat_Row() const;
    void Display() const;
    int Get_Seat_Number() const { return seat_number; };
};
