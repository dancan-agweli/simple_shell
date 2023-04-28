#include "shel.h"

/**
 * exit_shell - quit shell
 *
 * @info3: ...)
 * Return: always success.
 */
int exit_shell(info2 *info3)
{
	unsigned int uts;
	int dgt;
	int stl;
	int bn;

	if (info3->args[1] != NULL)
	{
		uts = _atoiii(info3->args[1]);
		dgt = _isdigits(info3->args[1]);
		stl = _strlen(info3->args[1]);
		bn = uts > (unsigned int)INT_MAX;
		if (!dgt || stl > 10 || bn)
		{
			get1_err(info3, 2);
			info3->status = 2;
			return (1);
		}
		info3->status = (uts % 256);
	}
	return (0);
}

