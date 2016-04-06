#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include "Seat.h"

using namespace std;

// Forward declarations to prevent circular dependency error
// http://stackoverflow.com/a/628079

class Seat;

class Seat_Row
{
public:
    static const int MAX_SEATS_PER_ROW = 1000;

private:
    string row_name;
    const Seat* seats[MAX_SEATS_PER_ROW];
    int  number_of_seats;

public:
	Seat_Row(const string& Row_Name);
    Seat_Row(const string& Row_Name, int Number_of_Seats);

    void Add_Seat(const Seat* new_seat);
    void Display() const;

	string Row_Name() const { return row_name; };
    int Number_of_Seats() const { return number_of_seats; }

    const Seat* Get_Seat(int idx) const { return seats[idx]; };
    const Seat* Get_Seat_by_Number(int n) const;
    string Get_Seat_Row_Name() const { return row_name; };
};


