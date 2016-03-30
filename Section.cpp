//Test

#include <iostream>
#include <string>
#include <cassert>
#include "Section.h"

using namespace std;

Section::Section(const string& section_name_) :
        section_name(section_name_),
        number_of_seats(0)
{}

void Section::Add_Seat(const Seat* new_seat)
{
    assert(number_of_seats < MAX_SEATS_PER_SECTION);
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
