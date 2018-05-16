#include <string.h>
#include<iostream>
#include "Plane.h"
#include "ReadWord.h"

using namespace std;

char *	PlaneWords [] =	{
						"Alfa",
						"Bravo"
						};

void FlyPlane (struct Plane & WhichPlane, PlaneID WhichID,struct Plane & Lounge)
	{
	int		i;
	int     j;

	PlaneName(WhichID);
	cout << " has taken off and landed " << endl;
	// show name of each party on plane
	WhichPlane.NumEmptySeats	= WhichPlane.NumSeats;
	for (i = 0; i < WhichPlane.NumParties; i++)
	{
		cout << WhichPlane.Parties[i].pName << " with "<< WhichPlane.Parties[i].Size<< " passengers "<<" has reached its destination " << endl;
		delete[] WhichPlane.Parties[i].pName;
	}
	WhichPlane.NumParties = 0;
	// move anyone waiting from lounge onto the plane
	if (Lounge.NumEmptySeats<Lounge.NumSeats)
	MoveToPlane(WhichPlane, WhichID, Lounge);
	else;
	
	}

void MoveToPlane(struct Plane & WhichPlane, PlaneID WhichID, struct Plane & Lounge)
{
	int     i;
	int     j;
	

	for (i = 0;i < Lounge.NumParties;i++)
	{
		if (Lounge.Parties[i].WhichPlane == WhichID)
		{
			if (Lounge.Parties[i].Size <= WhichPlane.NumEmptySeats)
			{
				WhichPlane.NumEmptySeats = WhichPlane.NumEmptySeats - Lounge.Parties[i].Size;
				Lounge.NumEmptySeats     = Lounge.NumEmptySeats + Lounge.Parties[i].Size;
				cout << Lounge.Parties[i].pName << " has boarded ";
				PlaneName(WhichID);
				WhichPlane.Parties[WhichPlane.NumParties]    = Lounge.Parties[i];
				WhichPlane.NumParties++;
				j = i;
				// the following loop will eliminate the gap in the array
				Lounge.NumParties--;
				for (i;i < Lounge.NumParties;i++)
				Lounge.Parties[i] = Lounge.Parties[i + 1];
				
				
				i = j;
				i--;

				if (WhichPlane.NumEmptySeats == 0)
					FlyPlane(WhichPlane, WhichID, Lounge);
				else;

			}
			else;
		}
		else;
	} 

}




PlaneID GetPlane ()
	{
	char *		Plane;
	PlaneID		WhichPlane;

	Plane	= ReadWord ();
	for (WhichPlane = PlaneAlfa; WhichPlane < InvalidPlane; WhichPlane = (PlaneID)(WhichPlane + 1))
		if (_strcmpi(Plane, PlaneWords[WhichPlane]) == 0)
		{
			delete[] Plane;
			return WhichPlane;
		}
		else;
			delete[] Plane;
	return InvalidPlane;
	}

void InitPlane (struct Plane & P)
	{
	P.NumSeats		= ReadInteger ();
	P.NumEmptySeats	= P.NumSeats;
	P.NumParties	= 0;
	P.Parties		= new Party [P.NumSeats];
	}
