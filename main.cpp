#include <iostream>
#include "Seat.h"
#include "Seat_Row.h"
#include "Venue.h"
#include "Performance.h"
#include "Ticket.h"
#include "Ticket_Book.h"
#include "Section.h"


//Sterling Price
//I want to be. The very best. Like no one ever was. Dun dun dun-dun. To create them is my real test, to print them is my cause.
//I will code across Git-Hub. Commenting far and wide. Dun dun dun-dun. These pointers, do understand, the seat that's inside.
//Venue sort! Gotta create them all. It's you and me. I know it's my Programming Grade. Venue sort! Ohh, you're my best program.
//In a group we must defend. Venue sort! A code so true. Our programming will pull us through. You access me and I'll access you.
//VENUE SORT!


using namespace std;

// Create a Seat_Row with the specified name and 
// specified number of seats,
Section* Create_Seat_Row(const string seat_row_name,
                          int number_of_seats)
{
    Section* row = new Section(seat_row_name);
    for (int i = 1; i <= number_of_seats; ++i)
    {
        Seat* new_seat = new Seat(seat_row_name, i, row);
        row->Add_Seat(new_seat);
    }
    return row;
}

// stoi() is only in C++11 and up. 
int str_to_int(string str) { 
    int i;
    std::istringstream(str) >> i;
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
    
    cout << "This is the New Venue program\n" + 
        "Please enter venue information";
    cout << "\nName: ";
    getline(cin, venue_name);
    cout << "\nStreet Address: ";
    getline(cin, street);
    cout << "\nCity: ";
    getline(cin, city);
    cout >> "\nState: ";
    getline(cin, state);
    cout >> "\nZip: ";
    getline(cin, zip);

    Address address = {street, city, state, zip};
    Venue* venue = new Venue(venue_name, address);
    cout << "\nEnter seat row information\n" + 
        "Enter blank line for name when finished";

    // Create seat rows
    while (1) 
    {
        string row_name;
        string num_seats;

        cout << "\nSeat row name: ";
        getline(cin, row_name);
        if (row_name == "") break;
        cout << "\nNumber of seats: ";
        getline(cin, num_seats);
         
        Seat_Row* row = Create_Seat_Row(row_name, str_to_int(num_seats));
        venue->Add_Seat_Row(row);
    }

    // Create sections
    cout << "Enter seating section information\n" + 
        "Enter blank line for seating section when finished";
    while(1) 
    {
        string section_name;
        cout << "\nSeating Section name: ";
        getline(cin, section_name);
        if (section_name == "") break;

        Section* section = new Section(section_name);
        
        // Add rows to a section
        while (1) 
        {
            string row_name;
            string first_seat_number;
            string last_seat_number;
            
            cout << "\nRow Name: ";
            getline(cin, row_name);
            if (row_name == "") break;
            
            Seat_Row* row = venue->Get_Seat_Row(row_name);
            
            // Check that row exists
            if (row == NULL) 
            {
                cout << "\nThat is not a valid row name!\n";
                continue;
            }

            cout << "\nFirst seat number: ";
            getline(cin, first_seat_number);
            cout << "\nLast seat number: ";
            getline(cin, last_seat_number);
            
            // Add seats from row to section
            for (int i = str_to_int(first_seat_number);
                    i <= str_to_int(last_seat_number);
                    i++) 
                    section->Add_Seat(row[i]);
            
        }
        
        venue->Add_Section(section);
    }        

    return venue;
}


Performance* Create_Performance(Venue* venue)
{
}


int main()
{
    Venue* venue = Create_Venue();
    venue->Display_All();
}


