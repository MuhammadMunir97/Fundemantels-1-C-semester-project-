#ifndef PLANE_H
#define PLANE_H

#include "Party.h"

struct Plane
	{
	int		NumSeats;
	int		NumEmptySeats;
	int		NumParties;
	Party *	Parties;
	};

void    FlyPlane    (struct Plane & WhichPlane, PlaneID WhichID, struct Plane & Lounge);
PlaneID	GetPlane	();
void	InitPlane	(struct Plane &);
void    Board       (struct Plane &, PlaneID p, Plane &);
void PlaneName(PlaneID p);
void MoveToPlane(struct Plane & WhichPlane, PlaneID WhichID, struct Plane & Lounge);

#endif
