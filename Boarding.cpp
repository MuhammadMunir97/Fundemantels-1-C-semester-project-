#include <iostream>

using namespace std;

#include <stdlib.h>

#include "Commands.h"
#include "Plane.h"
#include "ReadWord.h"

void Board(struct Plane & WhichPlane, PlaneID p,struct Plane & Lounge)
{
	Party TempParty;
	TempParty.WhichPlane = p;
	TempParty.pName = ReadWord();
	TempParty.Size = ReadInteger();

	if (TempParty.Size == 0)
	{
		delete[] TempParty.pName;
		cout << "Sorry but You have entered an Inavalid size of the party " << endl;
	}
	else

	// check if the party can ever fit on the requested plane
	if (TempParty.Size > WhichPlane.NumSeats)
	{
		delete[] TempParty.pName;
		cout << "Sorry but the requested party cannot board ";
		PlaneName(p);
	}
	//		no - party has to leave Make sure and delete TempParty.pName
	else
		//		yes - can they fit on the plane currently
		if (WhichPlane.NumEmptySeats >= TempParty.Size)
		{	//				yes - put them on the plane
			WhichPlane.Parties[WhichPlane.NumParties] = TempParty;
			WhichPlane.NumEmptySeats = WhichPlane.NumEmptySeats - TempParty.Size;
			cout << WhichPlane.NumParties << endl;
			cout << TempParty.pName << " has boarded ";
			PlaneName(p);
			WhichPlane.NumParties++;
			//					  is the plane full?
			if (WhichPlane.NumEmptySeats == 0)
				//							no, break
				FlyPlane(WhichPlane, p, Lounge);
				//							yes, fly the plane
			else;
		}
	//				no - can they ever fit in lounge
		else
			if (TempParty.Size > Lounge.NumSeats)
				//						no - party has to leave Make sure and delete TempParty.pName
			{
				cout << "Sorry ,There is not enough room in Lounge" << endl;
				delete[] TempParty.pName;
			}
	//						yes - can they in the lounge currently
			else
			{
				if (TempParty.Size > Lounge.NumEmptySeats)
					//								no - party has to leave Make sure and delete TempParty.pName
				{
					cout << "Currently there is not enough room in Lounge " << endl;
					cout << "If you can try and come at a latter time" << endl;
					delete[] TempParty.pName;
				}
				//								yes - put them in the lounge
				else
				{
					Lounge.Parties[Lounge.NumParties] = TempParty;
					Lounge.NumParties++;
					Lounge.NumEmptySeats = Lounge.NumEmptySeats - TempParty.Size;
					cout << TempParty.pName << " is seated in Lounge" << endl;
					//	cout << Lounge.Parties[Lounge.NumParties-1].pName << " is seated in Lounge" << endl;
				}
			}
}

void PlaneName(PlaneID p)
{
	if (p == 0)
		cout << "Plane Alfa" << endl;
	else
		cout << "Plane Bravo" << endl;
}