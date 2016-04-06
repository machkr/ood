#include "Seat_Row.h"

using namespace std;

Seat_Row::Seat_Row(const string& Row_Name) :
	row_name(Row_Name),
	number_of_seats(0)
{}

Seat_Row::Seat_Row(const string& Row_Name, int Number_of_Seats) :
    row_name(Row_Name),
    number_of_seats(Number_of_Seats)
{}

void Seat_Row::Add_Seat(const Seat* new_seat)
{
    assert(number_of_seats < MAX_SEATS_PER_ROW);
    seats[number_of_seats++] = new_seat;
}

void Seat_Row::Display() const
{
    cout << "Row " << row_name << " Seats 1 - " <<
        number_of_seats << "\n";
}

const Seat* Seat_Row::Get_Seat_by_Number(int n) const 
{
    for (int i = 0; i < number_of_seats; i++) 
            if (n == seats[i]->Get_Seat_Number()) return seats[i];

    return NULL;
}
