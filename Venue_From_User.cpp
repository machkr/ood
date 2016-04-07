#include <iostream>
#include <string>
#include "Section.h"
#include "Venue.h"
#include "Venue_From_User.h"

using namespace std;

Venue* Venue_From_User::Get_Venue_From_User()
{
	string venue_name;
	string street;
	string city;
	string state;
	int zip;

	cout << "Please enter venue information" << endl;

	cout << "Name: ";
	getline(cin, venue_name);

	cout << "Street Address: ";
	getline(cin, street);

	cout << "City: ";
	getline(cin, city);

	cout << "State: ";
	getline(cin, state);

	cout << "Zip Code: ";
	cin >> zip;
	cin.ignore();

	Address* address = new Address(street, city, state, zip);
	Venue* venue = new Venue(venue_name, *address);

	Add_Seat_Rows(venue);
	Add_Sections(venue);

	return venue;
}

void Venue_From_User::Add_Seat_Rows(Venue* venue)
{
	cout << endl << "Enter seat row information ";
	cout << endl << "Enter blank line for name when finished" << endl;;

	while (true)
	{
		string row_name;
		int num_seats;

		cout << "Seat row name: ";
		getline(cin, row_name);

		if (row_name == "") break;

		cout << "Number of seats: ";
		cin >> num_seats;
		cin.ignore();

		venue->Add_Seat_Row(row_name, num_seats);
	}
}

void Venue_From_User::Add_Sections(Venue* venue)
{
	cout << endl << "Enter seating section information";
	cout << endl << "Enter blank line for seating section name when finished" << endl;

	while (true)
	{
		string section_name;
		cout << endl << "Seating Section name: ";
		getline(cin, section_name);

		if (section_name == "") break;

		Section* section = new Section(section_name);

		cout << "Enter Row names and seat number ranges";
		cout << endl << "Enter a blank line for row name when finished with this section" << endl;

		//Add rows to a section
		while (true)
		{
			string row_name;
			int first_seat_number;
			int last_seat_number;

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

			//Get first and last seat numbers
			cout << "First seat number: ";
			cin >> first_seat_number;
			cin.ignore();

			cout << "Last seat number: ";
			cin >> last_seat_number;
			cin.ignore();

			//Add seats from row to section
			for (int i = first_seat_number; i <= last_seat_number; i++)
			{
				section->Add_Seat(row->Get_Seat_by_Number(i));
			}
		}
		//Add section to venue
		venue->Add_Section(section);
	}
}