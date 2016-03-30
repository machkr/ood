#include "Seat.h"		// NOT FULLY FUNCTIONAL - IN PROGRESS
#include "Seat_Row.h"
#include "Section.h"
#include <iostream>
#include <cassert>
using namespace std;

Seat::Seat(string Row_Name, int Seat_Number, Seat_Row* Row) :
	seat_row_name(Row_Name), seat_number(Seat_Number), row(Row), section(NULL)
{}

void Seat::Set_Section(Section* new_section)
{
	this->section = new_section;
}

Section* Seat::Get_Section()
{
	return section;
}

Seat::~Seat()
{
}
void Seat::Display() const
{
	cout << "Row: " << seat_row_name << "\tSeat: " << seat_number << "\tSection: " << section;
}

