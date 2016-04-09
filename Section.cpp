#include "Section.h"

using namespace std;

Section::Section(const string& section_name_) :
        section_name(section_name_),
        number_of_seats(0)
{}

void Section::Add_Seat(Seat* new_seat)
{
    assert(number_of_seats < MAX_SEATS_PER_SECTION);
    new_seat->Set_Section(this);
    seats[number_of_seats++] = new_seat;
}

void Section::Display() const
{
    cout << "\nSection " << section_name << "\n";

    // Sort seats by Row, put into a map
    map<string, Seat_Row*> rows;
    for (int j = 0; j < number_of_seats; j++)
    {
        const string row_name = seats[j]->Get_Seat_Row()->Get_Seat_Row_Name();
        
        // If row is in map, add seat to row
        // Else, add a new row to map
        if (rows.find(row_name) != rows.end()) 
        {
            rows[row_name]->Add_Seat(seats[j]);
        } 
        else
        {
            rows[row_name] = new Seat_Row(row_name);
            rows[row_name]->Add_Seat(seats[j]);
        }
    }
    
    // Iterate through map
    map<string, Seat_Row*>::iterator it;
    for (it = rows.begin(); it != rows.end(); it++) 
    {
        Seat_Row* row = it->second;   	
        cout << "Row " << it->first << " Seats " << 
            row->Get_Seat(0)->Get_Seat_Number() << " - " <<
            row->Get_Seat(row->Number_of_Seats() - 1)->Get_Seat_Number() << "\n";
    }
    
    // Destroy map
    for (it = rows.begin(); it != rows.end(); it++) 
        delete it->second;
}
