#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include <fstream>
#include <iterator>
#include <map>
#include <list>
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Section.h"

class Venue
{
public:
    static const int MAX_SEAT_ROWS = 1000;
    static const int MAX_SECTIONS = 1000;

private:
	std::list<Seat_Row> seatrows;
    string venue_name;
    Address address;
    const Seat_Row* seat_rows[MAX_SEAT_ROWS];
    const Section* sections[MAX_SEAT_ROWS];
    int number_of_seat_rows;
    int number_of_sections;

public:
    Venue(const string& venue_name_, const Address address_);

    void Add_Seat_Row(const string& Row_Name, int Number_of_Seats);
    void Add_Seat_Row(const Seat_Row* seat_row);
    void Add_Section(const Section* section);
	int Capacity() const;
    void Display() const;
    void Display_All() const;
    int Number_of_Seat_Rows() const { return number_of_seat_rows; };
	string Venue_Name() const { return venue_name; };

    const Seat_Row* Get_Seat_Row(string Row_Name) const;
    const Seat_Row* Get_Seat_Row(int index) const;

	void Output_XML(ofstream& outfile) const;
};
