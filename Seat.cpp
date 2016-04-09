#include "Seat.h"

using namespace std;

Seat::Seat(int Seat_Number, Seat_Row* Row) :
	seat_number(Seat_Number), row(Row), section(NULL)
{}

Seat::Seat(int Seat_Number) :
	seat_number(Seat_Number), section(NULL)
{}

void Seat::Set_Section(Section* new_section)
{
	section = new_section;
}

Section* Seat::Get_Section()
{
	return section;
}

void Seat::Set_Seat_Row(Seat_Row* new_seat_row)
{
	row = new_seat_row;
	row_name = new_seat_row->Row_Name();
}

const Seat_Row* Seat::Get_Seat_Row() const
{
    return row;
}

void Seat::Display() const
{
	cout << "Row " << row->Get_Seat_Row_Name() << " Seat " << 
        seat_number << " Section " << section->Get_Section_Name() << "\n";
}
