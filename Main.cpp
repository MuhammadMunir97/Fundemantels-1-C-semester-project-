/*******************************************************************

DESCRIPTION:    Semester Project
CLASS:          COSC 1436.3S1
AUTHOR:         MUHAMMAD S MUNIR
DATE:           August 2017


********************************************************************/



#include <iostream>

using namespace std;

#include <stdlib.h>

#include "Commands.h"
#include "Plane.h"
#include "ReadWord.h"

void main ()
	{
	cout << "Semester Project by Muhammad S Munir for COSC 1436.3S1" << endl;
	cout << "\t Tree Top Airways (TTA)" << endl;

	Plane		Alfa;
	Plane		Bravo;
	Plane		Lounge;
	
	int         j;
	bool        b1;
	bool        InitAlfa;
	bool        InitBravo;
	bool        InitLounge;
	bool        AllInitialised;

	AllInitialised = false;
	InitAlfa       = false;
	InitBravo      = false;
	InitLounge     = false;
	// create a loop to initialise all the planes and lounge
	do {
		// all three of these bools will become true when all the planes and lounge have been initialised
		// and the loop will exterminate
		if ((InitAlfa == false) || (InitBravo == false) || (InitLounge == false))
		{
			switch (GetCommand())
			{
			case CmdAlfa:
				if (InitAlfa == false)
				{
					InitPlane(Alfa);
					InitAlfa = true;
				}
				else
				{
					cout << "Plane alfa has already been initialised " << endl;
					cout << "If you want to reinitialise plane alfa enter shutdown and start again" << endl;
				}
				break;
			case CmdBravo:
				if (InitBravo == false)
				{
					InitPlane(Bravo);
					InitBravo = true;
				}
				else
				{
					cout << "Plane Bravo has already been initialised " << endl;
					cout << "If you want to reinitialise plane Bravo enter shutdown and start again" << endl;
				}
				break;
			case CmdLounge:
				if (InitLounge == false)
				{
					InitPlane(Lounge);
					InitLounge = true;
				}
				else
				{
					cout << "Lounge has already been initialised " << endl;
					cout << "If you want to reinitialise Lounge enter shutdown and start again" << endl;
				}
				break;
			case CmdShutdown:
				cout << "Shutdown" << endl;
				exit(0);
				break;
				// all these commands would result in the command being inavalid
			case CmdFly:
			case CmdArrive:
			case CmdInvalid:
				cout << "You entered an invalid command, please Initialise first" << endl;
				break;
			default:
				cout << "Internal Error 101, please contact customer support" << endl;
				exit(0);
			}
		}
		else
		{
			AllInitialised = true;
		}

	} while (!AllInitialised);



	cout << "Initializing done" << endl;
	// create an infinite loop
	j = 1;
	while (j > 0)
	{
    	switch (GetCommand())
			{
		    case CmdAlfa:
				cout << "Plane Alfa is already Initialised" << endl;
				break;
		    case CmdBravo:
				cout << "Plane Bravo is already Initialised" << endl;
				break;
		    case CmdLounge:
				cout << "The Lounge is already Initialised" << endl;
				break;
			case CmdFly:
				switch (GetPlane())
				{
				case PlaneAlfa:
					// fly plane Alfa
					FlyPlane(Alfa, PlaneAlfa, Lounge);
					break;
				case PlaneBravo:
					FlyPlane(Bravo, PlaneBravo, Lounge);
					break;
				case InvalidPlane:
					cout << "You entered an invalid plane, please try again" << endl;
					break;
				default:
					cout << "Internal Error 102, please contact customer support" << endl;
					exit(0);
				}
				break;
			case CmdArrive:
				switch (GetPlane())
				{
				case PlaneAlfa:
					Board(Alfa, PlaneAlfa, Lounge);
					break;
				case PlaneBravo:
					Board(Bravo, PlaneBravo, Lounge);
					break;
				case InvalidPlane:
					cout << "You entered an invalid plane, please try again" << endl;
					break;
				default:
					cout << "Internal Error 102, please contact customer support" << endl;
					exit(0);
				}
				break;
			case CmdShutdown:
				// for each plane and the lounge, delete the array of parties we initially created with new
				cout << " Shutdown" << endl;
				// the infinite loop will exterminate when there is no one in the lounge , alfa and bravo
				b1 = false;
				do {
					if ((Alfa.NumEmptySeats == Alfa.NumSeats) && (Bravo.NumEmptySeats == Bravo.NumSeats) && (Lounge.NumEmptySeats == Lounge.NumSeats))
					{
						delete[]Alfa.Parties;
						delete[]Bravo.Parties;
						delete[]Lounge.Parties;
						exit(0);
					}
					else
					{
						FlyPlane(Alfa, PlaneAlfa, Lounge);
						FlyPlane(Bravo, PlaneAlfa, Lounge);
					}
				} while (!b1);
				break;
			case CmdInvalid:
				cout << "You entered an invalid command, please try again" << endl;
				break;
			default:
				cout << "Internal Error 103, please contact customer support" << endl;
				exit(0);
			}
		
	}
	}
