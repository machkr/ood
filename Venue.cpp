#include "Venue.h"

using namespace std;

Venue::Venue(const string& venue_name_,
    const Address address_) :
    venue_name(venue_name_), address(address_), 
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
    /*cout << name << endl;
    address->Display();
    for (int i = 0; i < number_of_seat_rows; ++i)
    {
        const Seat_Row* row = seat_rows[i];
        row->Display();
    }*/
}

void Venue::Display_All() const
{
    cout << "\nThe new venue:\n" << venue_name << "\n" << address.street << "\n" 
        << address.city << ", " << address.state << " " << address.zip << "\n";
    for (int i = 0; i < number_of_seat_rows; i++) 
    {
        cout << "Row " << seat_rows[i]->Get_Seat_Row_Name() << " Seats 1 - " <<
            seat_rows[i]->Number_of_Seats() << "\n";
    }

	cout << endl << "Seating Sections:";

    for (int i = 0; i < number_of_sections; i++) 
    {
        cout << "\nSection " << sections[i]->Get_Section_Name() << "\n";

        // Sort seats by Row, put into a map
        map<string, Seat_Row*> rows;
        const Section* s = sections[i];
        for (int j = 0; j < s->Number_of_Seats(); j++)
        {
            const string row_name = s->Get_Seat(j)->Get_Seat_Row()->Get_Seat_Row_Name();
            
            // If row is in map, add seat to row
            // Else, add a new row to map
            if (rows.find(row_name) != rows.end()) 
            {
                rows[row_name]->Add_Seat(s->Get_Seat(j));
            } 
            else
            {
                rows[row_name] = new Seat_Row(row_name);
                rows[row_name]->Add_Seat(s->Get_Seat(j));
            }
        }
        
        // Iterate through map
        map<string, Seat_Row*>::iterator it;
        for (it = rows.begin(); it != rows.end(); it++) 
        {
            Seat_Row* row = it->second;   	
            cout << "Row " << it->first << "  Seats " << 
                row->Get_Seat(0)->Get_Seat_Number() << " - " <<
                row->Get_Seat(row->Number_of_Seats() - 1)->Get_Seat_Number() << "\n";
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

const Seat_Row* Venue::Get_Seat_Row(string Row_Name) const 
{
    for (int i = 0; i < number_of_seat_rows; i++) 
    {
        if (seat_rows[i]->Get_Seat_Row_Name() == Row_Name) 
        {
            return seat_rows[i];
        }
    }
    return NULL;
}

const Seat_Row* Venue::Get_Seat_Row(int index) const 
{
    return seat_rows[index];
}
