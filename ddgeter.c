#include "shel.h"

/**
 * get1_err - this function calls the byuiltin error
 * @info3: pointert to struct
 * @val: value with an err
 * Return: returns the error message
 */
int get1_err(info2 *info3, int val)
{
	char *er4;

	switch (val)
	{
	case -1:
		er4 = er2_envir(info3);
		break;
	case 126:
		er4 = error_path(info3);
		break;
	case 127:
		er4 = err_unfound(info3);
		break;
	case 2:
		if (_strcmp("exit", info3->args[0]) == 0)
			er4 = err_exitshell(info3);
		else if (_strcmp("cd", info3->args[0]) == 0)
			er4 = err_cd(info3);
		break;
	}
	if (er4)
	{
		write(STDERR_FILENO, er4, _strlen(er4));
		free(er4);
	}
	info3->status = val;

	return (val);
}
