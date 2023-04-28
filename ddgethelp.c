#include "shel.h"

/**
 * gett_helpp - retrieval builtin
 * @info3: pointer to data info.
 *
 * Return: Return always answer
*/
int gett_helpp(info2 *info3)
{

	if (info3->args[1] == 0)
		help2_general();
	if (_strcmp(info3->args[1], "setenv") == 0)
		help2_setenvv();
	if (_strcmp(info3->args[1], "env") == 0)
		help1_envv();
	if (_strcmp(info3->args[1], "unsetenv") == 0)
		help2_unsetenvv();
	if (_strcmp(info3->args[1], "help") == 0)
		_help();
	if (_strcmp(info3->args[1], "exit") == 0)
		help_exitt();
	if (_strcmp(info3->args[1], "cd") == 0)
		_help_cdd();
	if (_strcmp(info3->args[1], "alias") == 0)
		_help1_alias();
	else
		write(STDERR_FILENO, info3->args[0],
		      _strlen(info3->args[0]));

	info3->status = 0;
	return (1);
}

