#include "shel.h"

/**
 * cdshel - finds the current directory
 * @info3: pointed to data
 * Return: always give 1 on success
 */
int cdshel(info2 *info3)
{
	char *rd;
	int h, x, y;

	rd = info3->args[1];

	if (rd != NULL)
	{
		h = _strcmp("$HOME", rd);
		x = _strcmp("~", rd);
		y = _strcmp("--", rd);
	}

	if (!rd || !h || !x || !y)
	{
		cdhome(info3);
		return (1);
	}

	if (_strcmp("-", rd) == 0)
	{
		cdprev(info3);
		return (1);
	}

	if (_strcmp(".", rd) == 0 || _strcmp("..", rd) == 0)
	{
		cddott(info3);
		return (1);
	}

	cdto2(info3);

	return (1);
}
