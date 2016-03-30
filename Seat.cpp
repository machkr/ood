#include "Seat.h"		// NOT FULLY FUNCTIONAL - IN PROGRESS
#include "Seat_Row.h"
#include "Section.h"
using namespace std;

Seat::Seat(int Seat_Number, Seat_Row* Row) :
	seat_number(Seat_Number), row(Row), section(NULL)
{}

void Seat::Set_Section(Section* new_section)
{
	section = new_section;
}

Section* Seat::Get_Section()
{
	return section;
}

const Seat_Row* Seat::Get_Seat_Row() const
{
    return row;
}
/*Seat::~Seat()
{
}*/
void Seat::Display() const
{
	cout << "Row: " <<  "\tSeat: " << seat_number << "\tSection: " << section;
}

