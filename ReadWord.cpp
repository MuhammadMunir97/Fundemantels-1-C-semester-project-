#include <iostream>

using namespace std;

#include <ctype.h>		// needed to get isspace
#include <memory.h>

#include "ReadWord.h"

static void SkipSpaces ();

int ReadInteger ()
	{
	char	c;
	bool	IsNeg;
	int		Num;
	int		NumCharsRead;

	IsNeg			= false;
	Num				= 0;
	NumCharsRead	= 0;
	while (!isspace (c = cin.get ()))
		{
		switch (c)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
						Num = (Num * 10) + (c - '0');
						NumCharsRead++;
						break;
			default:
						; // skip the character
			}
		}
	return Num;
	}

char * ReadWord ()
	{
	const	int		FirstGuess (50);
			char	c;
			int		MaxCharsPerLine;
			int		NumCharsEntered;
			char *	pLine;
			char *	pTempLine;

	SkipSpaces ();
	MaxCharsPerLine	= FirstGuess;
	NumCharsEntered	= 0;
	pLine			= new char [MaxCharsPerLine + 1];
	while (!isspace (c = cin.get ()))
		{
		pLine [NumCharsEntered++]	= c;
		if (NumCharsEntered >= MaxCharsPerLine)
				{
				MaxCharsPerLine	+= FirstGuess;
				pTempLine		= new char [MaxCharsPerLine + 1];
				memcpy (pTempLine, pLine, NumCharsEntered);
				delete [] pLine;
				pLine			= pTempLine;
				}
			else;
		}
	pLine [NumCharsEntered] = '\0';
	return pLine;
	}

void SkipSpaces ()
	{
	char	c;

	do	{
		c = cin.get ();
		} while (isspace (c));
	cin.putback (c);
	}
