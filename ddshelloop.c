#include "shel.h"

/**
 * witho_comm - erace the comment
 * @ni: insertionstring
 * Return: comment of insert.
 */
char *witho_comm(char *ni)
{
	int x, y;

	y = 0;
	for (x = 0; ni[x]; x++)
	{
		if (ni[x] == '#')
		{
			if (x == 0)
			{
				free(ni);
				return (NULL);
			}

			if (ni[x - 1] == ' ' || ni[x - 1] == '\t' || ni[x - 1] == ';')
				y = x;
		}
	}

	if (y != 0)
	{
		ni = _reallocc(ni, x, y + 1);
		ni[y] = '\0';
	}

	return (ni);
}

/**
 * s_loop - iteration of shell
 * @info3: ...
 * Return: nothing.
 */
void s_loop(info2 *info3)
{
	int iter, x_eof;
	char *inp;

	iter = 1;
	while (iter == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		inp = readline1(&x_eof);
		if (x_eof != -1)
		{
			inp = witho_comm(inp);
			if (!inp)
				continue;

			if (check_s_error(info3, inp) == 1)
			{
				info3->status = 2;
				free(inp);
				continue;
			}
			inp = replace_var(inp, info3);
			iter = spltcmd(info3, inp);
			info3->count += 1;
			free(inp);
		}
		else
		{
			iter = 0;
			free(inp);
		}
	}
}

