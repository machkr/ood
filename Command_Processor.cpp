#include <iostream>
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
	Menu* menu = new Menu("Enter command number");
	menu->Add_Command("Select Venue");
	menu->Add_Command("Quit");
	menus[0] = menu;

	// Menu for Venue Selected
	menu = new Menu("Enter command number");
	menu->Add_Command("Display Venue")
	menu->Add_Command("Select Show");
	menu->Add_Command("Change Venue");
	menu->Add_Command("Quit");
	menus[1] = menu;
}

void Command_Processor::Process_Commands(Venue** venues_,
	int* nr_venues_)
{
	cout << "Process commands starting\n";

	venues = venues_;
	nr_venues = nr_venues_;

	Create_Menus();

	while (command_state != Done)
	{
		if (command_state == Venue_Selected)
		{
			cout << "Selected venue is "
				<< selected_venue->Name() << endl;
		}
		const string* cmd = menus[command_state]->Get_Command();

		switch (command_state)
		{
		case Initial:   Process_Command_0(*cmd);
			break;

		case Venue_Selected:    Process_Command_1(*cmd);
			break;

		case Done:  break;      
		}
	}

	cout << "Command_Processor exiting\n";
}


void Command_Processor::Process_Command_1(const string& cmd)
{
	if (cmd == "Select Venue")
	{
		
		//Select Venue
		Select_Venue();
		command_state = Venue_Selected;
	}
	else
		//Quit
	{
		Output_XML();
		command_state = Done;
	}
}

void Command_Processor::Process_Command_2(const string& cmd)
{
	if (cmd == "Display Venue")
	{
		//Display Venue
	}

	else if (cmd == "Select Show")
	{
		//Select Show
	}
	else if (cmd == "Change Venue")
	{
	
		//Change Venue
	}
	else
	{
		//Quit
		Output_XML();
		command_state = Done;
	}


	void Command_Processor::Select_Venue()
	{
		//Select Venue method
	}

	void Command_Processor::Select_Show()
	{
		//Select Show method
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
		for (int i = 0; i < *nr_venues; ++i)
		{
			venues[i]->Output_XML(outfile);
		}
		outfile.close();
		cout << "File venues2.xml written\n";
	}

