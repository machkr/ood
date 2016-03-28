//Test

#include <iostream>
#include <string>
#include <cassert>
#include "Section.h"

using namespace std;

Section::Section(section_name)
{}

void Add_Seat(const Seat* new_seat)
{
    assert(number_of_seats < MAX_SEATS_PER_ROW);
    seats[number_of_seats++] = new_seat;
}

void Section::Display() const
{
    cout << "Section " << section_name << " has "
        << number_of_seats << " seats" << endl;
    for (int i = 0; i < number_of_seats; ++i)
    {
        cout << "\t";		// Indent the Seat description
        seats[i]->Display();
    }
}
