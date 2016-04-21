#include <iostream>
#include <fstream>
#include "Command_Processor.h"

using namespace std;

Venue** Command_Processor::venues = 0;
int* Command_Processor::nr_venues = 0;
Venue* Command_Processor::selected_venue = 0;
Command_States Command_Processor::command_state = Initial;
Menu* Command_Processor::menus[NR_CMD_STATES];

void Command_Processor::Create_Menus()
{
	// Menu for Initial command state
	Menu* menu = new Menu("Enter command number:\n");
	menu->Add_Command("Select Venue");
	menu->Add_Command("Quit");
	menus[0] = menu;

	// Menu for Venue Selected
	menu = new Menu("Enter command number:\n");
	menu->Add_Command("Display Venue");
	menu->Add_Command("Select Show");
	menu->Add_Command("Change Venue");
	menu->Add_Command("Quit");
	menus[1] = menu;
}

void Command_Processor::Process_Commands(Venue** venues_, int* nr_venues_)
{
	cout << "The command processor is starting.\n";

	venues = venues_;
	nr_venues = nr_venues_;

	Create_Menus();

	while (command_state != Done)
	{
		if (command_state == Venue_Selected)
		{
			cout << "selected venue is " << selected_venue->Venue_Name() << "." << endl;
		}

		const string* cmd = menus[command_state]->Get_Command();
		switch (command_state)
		{
		case Initial: Process_Command_1(*cmd);
			break;

		case Venue_Selected: Process_Command_2(*cmd);
			break;

		case Done:  
			break;      
		}
	}
	cout << "The command processor is exiting.\n";
}


void Command_Processor::Process_Command_1(const string& cmd)
{
	if (cmd == "Select Venue")
	{	
		Select_Venue();
		command_state = Venue_Selected;
	}
	else
	{
		//Quit
		Output_XML();
		command_state = Done;
	}
}

void Command_Processor::Process_Command_2(const string& cmd)
{
	if (cmd == "Display Venue")
	{
		selected_venue->Display_All();
		
	}
	else if (cmd == "Select Show")
	{
		Select_Show();
			cout << endl;
	}
	else if (cmd == "Change Venue")
	{
		command_state = Initial;
	}
	else
	{
		//Quit
		Output_XML();
		command_state = Done;
	}
}

void Command_Processor::Select_Venue()
{
	Menu* menu = new Menu("Select Venue");
	for (int i = 0; i < *nr_venues; ++i)
	{
		menu->Add_Command(venues[i]->Venue_Name());
	}

	const string* venue_name = menu->Get_Command();
	//find venue with this name
	for (int i = 0; i < *nr_venues; ++i)
	{
		if (venues[i]->Venue_Name() == *venue_name)
		{
			selected_venue = venues[i];
			command_state = Venue_Selected;
			return;
		}
	}

	// Should never reach this point.
	cout << "Error in Command_Processor::Select_Venue()\n";
}

void Command_Processor::Select_Show()
{
	//Select Show method
	cout << "Select Show Command Here";
}

//Not sure if the below is needed, we'll see. 
void Command_Processor::Output_XML()
{
	ofstream outfile;
	outfile.open("venues2.xml");
	if (!outfile.is_open())
	{
		cout << "Failed to open file for output\n";
		return;
	}
	outfile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
	outfile << "<Venue_file>\n";
	for (int i = 0; i < *nr_venues; ++i)
	{
		venues[i]->Output_XML(outfile);
	}
	outfile << "</Venue_file>\n";
	outfile.close();
	cout << "File venues2.xml written\n";
}