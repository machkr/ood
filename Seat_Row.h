#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include "Seat.h"
#include <fstream>
#include <list>

using namespace std;

// Forward declarations to prevent circular dependency error
// http://stackoverflow.com/a/628079

class Seat;

class Seat_Row
{
public:
    static const int MAX_SEATS_PER_ROW = 1000;

private:
	std::list<Seat> s;
    string row_name;
    Seat* seats[MAX_SEATS_PER_ROW];
    int  number_of_seats;

public:
	Seat_Row(const string& Row_Name);
    Seat_Row(const string& Row_Name, int Number_of_Seats);

    void Add_Seat(Seat* new_seat);
    void Display() const;

	string Row_Name() const { return row_name; };
    int Number_of_Seats() const { return number_of_seats; }

    Seat* Get_Seat(int idx) const { return seats[idx]; };
    Seat* Get_Seat_by_Number(int n) const;
    string Get_Seat_Row_Name() const { return row_name; };

	void Output_XML(std::ofstream& outfile) const;
};


