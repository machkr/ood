#include <iostream>
#include "Seat.h"
#include "Seat_Row.h"
#include "Venue.h"
#include "Section.h"
#include <sstream>

//Sterling Price
//I want to be. The very best. Like no one ever was. Dun dun dun-dun. To create them is my real test, to print them is my cause.
//I will code across Git-Hub. Commenting far and wide. Dun dun dun-dun. These pointers, do understand, the seat that's inside.
//Venue sort! Gotta create them all. It's you and me. I know it's my Programming Grade. Venue sort! Ohh, you're my best program.
//In a group we must defend. Venue sort! A code so true. Our programming will pull us through. You access me and I'll access you.
//VENUE SORT!
// blah blah
using namespace std;

// Create a Seat_Row with the specified name and 
// specified number of seats,
Seat_Row* Create_Seat_Row(const string seat_row_name, int number_of_seats)
{
    Seat_Row* row = new Seat_Row(seat_row_name);

    for (int i = 1; i <= number_of_seats; ++i)
    {
        Seat* new_seat = new Seat(i, row);
        row->Add_Seat(new_seat);
    }

    return row;
}

// stoi() is only in C++11 and up. 
int str_to_int(string str)
{ 
    int i;
    istringstream(str) >> i;
    return i;
}

// Create venue by prompting user for details
Venue* Create_Venue()
{
    string venue_name;
    string street;
    string city;
    string state;
    string zip;
    
	cout << "Please enter venue information" << endl;

    cout << "Name: ";
    getline(cin, venue_name);

    cout << "Street Address: ";
    getline(cin, street);

    cout << "City: ";
    getline(cin, city);

    cout << "State: ";
    getline(cin, state);

    cout << "Zip: ";
    getline(cin, zip);

    Address address = {street, city, state, zip};
    Venue* venue = new Venue(venue_name, address);

	cout << endl << "Enter seat row information ";
	cout << endl << "Enter blank line for name when finished" << endl;;

    // Create seat rows
    while (1) 
    {
        string row_name;
        string num_seats;

        cout << "Seat row name: ";
        getline(cin, row_name);

        if (row_name == "") break;

        cout << "Number of seats: ";
        getline(cin, num_seats);
         
        Seat_Row* row = Create_Seat_Row(row_name, str_to_int(num_seats));
        venue->Add_Seat_Row(row);
    }

    // Create sections
	cout << endl << "Enter seating section information";
	cout << endl << "Enter blank line for seating section name when finished" << endl;

    while(1) 
    {
        string section_name;
        cout << endl << "Seating Section name: ";
        getline(cin, section_name);

		cout << "Enter Row names and seat number ranges";
		cout << endl << "Enter a blank line for row name when finished with this section" << endl;
        if (section_name == "") break;

        Section* section = new Section(section_name);
        
        // Add rows to a section
        while (1) 
        {
            string row_name;
            string first_seat_number;
            string last_seat_number;
            
            cout << "Row Name: ";
            getline(cin, row_name);
            if (row_name == "") break;
            
            const Seat_Row* row = venue->Get_Seat_Row(row_name);
            
            // Check that row exists
            if (row == NULL) 
            {
                cout << "\nThat is not a valid row name!" << endl << endl;
                continue;
            }

            cout << "First seat number: ";
            getline(cin, first_seat_number);

            cout << "Last seat number: ";
            getline(cin, last_seat_number);
            
            // Add seats from row to section
            for (int i = str_to_int(first_seat_number);
					i <= str_to_int(last_seat_number);
					i++) 
				section->Add_Seat(row->Get_Seat_by_Number(i));
        }
        
        venue->Add_Section(section);
    }        

    return venue;
}

int main()
{
	cout << "This is the New Venue program!" << endl;

    Venue* venue = Create_Venue();
    venue->Display_All();

	cin.get();
	cin.get();

	return 0;
}
