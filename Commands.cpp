#include <string.h>

#include "Commands.h"
#include "ReadWord.h"

char *	CmdWords [] =	{
						"Alfa",
						"Bravo",
						"Lounge",
						"Fly",
						"Arrive",
						"Shutdown"
						};

Commands GetCommand ()
	{
	char *		Cmd;
	Commands	WhichCmd;

	Cmd	= ReadWord ();
	for (WhichCmd = CmdAlfa; WhichCmd <= CmdShutdown; WhichCmd = (Commands) (WhichCmd + 1))
		if (_strcmpi(Cmd, CmdWords[WhichCmd]) == 0)
		{
			delete[] Cmd;
			return WhichCmd;
		}
			else;
			delete[] Cmd;
	        return CmdInvalid;
	}
