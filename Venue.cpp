#include <string.h>
#include <iostream>
#include <cassert>
#include <iterator>
#include <map>
#include "Venue.h"
#include "Seat_Row.h"
using namespace std;

Venue::Venue(const string& name_,
    const Address address_) :
    name(name_), address(&address_), 
    number_of_seat_rows(0), 
    number_of_sections(0)
{}

void Venue::Add_Seat_Row(const Seat_Row* seat_row)
{
    assert(number_of_seat_rows < MAX_SEAT_ROWS - 1);
    seat_rows[number_of_seat_rows++] = seat_row;
}

void Venue::Add_Section(const Section* section)
{
    assert(number_of_sections < MAX_SECTIONS - 1);
    sections[number_of_sections++] = section;
}

void Venue::Display() const
{
    cout << name << endl;
    address->Display();
    /*for (int i = 0; i < number_of_seat_rows; ++i)
    {
        const Seat_Row* row = seat_rows[i];
        row->Display();
    }*/
}

void Venue::Display_All() const
{
    cout << "The new venue:\n" << venue_name << "\n" << address.street << "\n" 
        << address.city << ", " << address.state << " " << address.zip << "\n";
    for (int i = 0; i < number_of_seat_rows; i++) 
    {
        cout << "Row" << seat_rows[i]->Get_Row_Name() << " Seats 1 - " <<
            seat_rows[i]->Number_of_Seats() << "\n";
    }
    cout << "\n";

    for (int i = 0; i < number_of_sections; i++) 
    {
        cout << "Section " << sections[i]->Get_Section_Name() << "\n";

        // Sort seats by Row, put into a map
        std::map<string, Seat_Row*> rows;
        for (int j = 0, Section* s = sections[i]; j < s->Number_of_Seats(); j++)
        {
            string row_name = s->Get_Seat(j)->Get_Seat_Row()->Get_Row_Name();
            
            // If row is in map, add seat to row
            // Else, add a new row to map
            if (rows.find(row_name) != rows.end) 
            {
                rows[row_name]->Add_Seat(s->Get_Seat(j));
            } 
            else
            {
                rows[row_name] = Seat_Row(row_name);
                rows[row_name]->Add_Seat(s->Get_Seat(j));
            }
        }
        
        // Iterate through map
        map<string, Seat_Row*>::iterator it;
        for (it = rows.begin(); it != rows.end(); it++) 
        {
            cout << "Row " << it->first << "  Seats 1 - " << 
                it->second->Number_of_Seats() << "\n";
        }
        
        // Destroy map
        for (it = rows.begin(); it != rows.end(); it++) 
            delete it->second;

    }
    cout << "\n";

}

// Return number of seats
int Venue::Capacity() const
{
    int count = 0;
    for (int i = 0; i < number_of_seat_rows; ++i)
    {
        count += seat_rows[i]->Number_of_Seats();
    }
    return count;
}

Seat_Row* Venue::Get_Seat_Row(string Row_Name) const {
    for (int i = 0; i < number_of_seat_rows; i++) {
        if (seat_rows[i]->Get_Row_Name() == Row_Name) {
            return seat_rows[i];
        }
    }
    return NULL;
}


