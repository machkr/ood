#include "Venue.h"

using namespace std;

Venue::Venue(const string& venue_name_, const Address address_) :
    venue_name(venue_name_),
	address(address_), 
    number_of_seat_rows(0), 
    number_of_sections(0)
{}

void Venue::Add_Seat_Row(const string& Row_Name, int Number_of_Seats)
{
    assert(number_of_seat_rows < MAX_SEAT_ROWS - 1);
    seat_rows[number_of_seat_rows++] = new Seat_Row(Row_Name, Number_of_Seats);
}

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
	cout /*<< "\nThe new venue:\n"*/ << venue_name << endl;
	address.Display();
/*	list<Seat_Row>::const_iterator s;
	s = seatrows.begin();
	while (s != seatrows.end())
	{
		cout << " ";
		s->Display();
		cout << endl;
		++s;
	}
	cout << endl; edit*/
}

void Venue::Display_All() const
{
    Display(); 
    cout << "\n";
	for (int i = 0; i < number_of_seat_rows; i++) 
    {
        for (int j = 0; j < seat_rows[i]->Number_of_Seats(); j++)
        {
            seat_rows[i]->Get_Seat(j)->Display();
        }
    }
	cout << endl;
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

void Venue::Output_XML(ofstream& outfile) const
{
	outfile << "\t<venue>\n";
	outfile << "\t\t<name>" << venue_name <<"</name>\n";

	outfile << "\t\t<address>\n";
	outfile << "\t\t\t<street>" << address.Street_Address() << "</street>\n";
	outfile << "\t\t\t<city>" << address.City() << "</city>\n";
	outfile << "\t\t\t<state>" << address.State() << "</state>\n";
	outfile << "\t\t\t<zip_code>" << address.ZIP_Code() << "</zip_code>\n";
	outfile << "\t\t</address>\n";

	for (int i = 0; i < number_of_seat_rows; i++)
	{
		
		seat_rows[i]->Output_XML(outfile);
		for (int j = 0; j < seat_rows[i]->Number_of_Seats(); j++)
		{
			seat_rows[i]->Get_Seat(j)->Output_Xml(outfile);
		}
		outfile << "\t\t</seat_row>\n";
	}
	cout << endl;
	/*
	list<Seat_Row>::const_iterator c;
	c = seatrows.begin();
	while (c != seatrows.end())
	{
		c->Output_XML(outfile);
		++c;
	}
	*/
	//cout << endl;
	outfile << "\t</venue>\n";

}