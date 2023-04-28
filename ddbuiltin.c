#include "shel.h"

/**
 * get_builtin - builtin for  command
 *
 * @cmd: the shell command
 * Return: always sucess
 */
int (*get_builtin(char *cmd))(info2 *)
{
	builtin_t builtin[] = {
		{ "env", env1 },
		{ "exit", exit_shell },
		{ "setenv", setenv1 },
		{ "unsetenv", unsetenvv2 },
		{ "cd", cdshel },
		{ "help", gett_helpp },
		{ NULL, NULL }
	};
	int x;

	for (x = 0; builtin[x].name; x++)
	{
		if (_strcmp(builtin[x].name, cmd) == 0)
			break;
	}

	return (builtin[x].f);
}

