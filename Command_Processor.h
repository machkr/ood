#pragma once
#include <string>
#include "Menu.h"
#include "Venue.h"

enum Command_States { Initial, Venue_Selected, Done };
using namespace std;
class Command_Processor
{
public:
	static void Process_Commands(Venue** venues_, int* nr_venues_);
private:
	static const int NR_CMD_STATES = (int)Done + 1;
	static Command_States command_state;
	static Menu* menus[NR_CMD_STATES];
	Command_Processor(void);
	static void Create_Menus();
	static void Process_Command_1(const string& cmd);
	static void Process_Command_2(const string& cmd);
	static void Select_Venue();
	static void Select_Show();
	static Venue** venues;
	static int* nr_venues;
	static Venue* selected_venue;
	static void Output_XML();
};