#include <iostream>
#include <sstream>

#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Venue.h"
#include "Section.h"
#include "tinyxml.h"
#include "Venue_From_Xml.h"

using namespace std;

//Create a Seat_Row with the specified name and specified number of seats,
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

//stoi() is only in C++11 and up. 
int str_to_int(string str)
{ 
    int i;
    istringstream(str) >> i;
    return i;
}

//Create venue by prompting user for details
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

    Address* address = new Address(street, city, state, zip);  
    Venue* venue = new Venue(venue_name, *address);

	cout << endl << "Enter seat row information ";
	cout << endl << "Enter blank line for name when finished" << endl;;

    //Create seat rows
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

    //Create sections
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
        
        //Add rows to a section
        while (1) 
        {
            string row_name;
            string first_seat_number;
            string last_seat_number;
            
            cout << "Row Name: ";
            getline(cin, row_name);
            if (row_name == "") break;
            
            const Seat_Row* row = venue->Get_Seat_Row(row_name);
            
            //Check that row exists
            if (row == NULL) 
            {
                cout << "\nThat is not a valid row name!" << endl << endl;
                continue;
            }

            cout << "First seat number: ";
            getline(cin, first_seat_number);

            cout << "Last seat number: ";
            getline(cin, last_seat_number);
            
            //Add seats from row to section
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
	cout << "This is the Level 0 Ticket Booth program!" << endl;

	string filename = "Venue.xml";
	TiXmlDocument doc(filename);
	bool loadOkay = doc.LoadFile();

	if (!loadOkay)
	{
		cout << "Could not load file " << filename << endl;
		cout << "Error='" << doc.ErrorDesc() << "'. Exiting.\n";
		cin.get();
		exit(1);
	}

	cout << filename << " read from disk " << endl;
	//cout << "Printing via doc.Print \n";
	//doc.Print(stdout);
	
	TiXmlNode* venue_file_node = doc.FirstChild("venue_file");
	assert(venue_file_node != 0);
	cout << venue_file_node->Value() << endl;

	TiXmlNode* venue_node = venue_file_node->FirstChild();
	assert(venue_node != 0);
	cout << venue_node->Value() << endl;

	Venue* venue = Venue_from_XML::Get_Venue_From_XML(venue_node);
	venue->Display_All;

	cin.get();
	return 0;
}
