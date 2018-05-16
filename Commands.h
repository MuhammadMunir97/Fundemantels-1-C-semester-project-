#ifndef COMMANDS_H
#define COMMANDS_H

enum Commands	{
				CmdAlfa,
				CmdBravo,
				CmdLounge,
				CmdFly,
				CmdArrive,
				CmdShutdown,

				CmdInvalid
				};

Commands GetCommand ();

#endif

