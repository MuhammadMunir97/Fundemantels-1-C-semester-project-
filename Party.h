#ifndef PARTY_H
#define PARTY_H

enum PlaneID	{
				PlaneAlfa,
				PlaneBravo,

				InvalidPlane
				};

struct Party
	{
	char *		pName;
	int			Size;
	PlaneID		WhichPlane;
	};

#endif
