#include "shel.h"

/**
 * repchar - writes repetatives
 * @inp: the string of inputs
 * @x: ...
 * Return: iteretative
 */
int repchar(char *inp, int x)
{
	if (*(inp - 1) == *inp)
		return (repchar(inp - 1, x + 1));

	return (x);
}

/**
 * error_sep - locates the syn errors
 * @inp: the strings
 * @x: ...
 * @end: last char read
 * Return: always return answer
 */
int error_sep(char *inp, int x, char end)
{
	int sum;

	sum = 0;
	if (*inp == '\0')
		return (0);

	if (*inp == ' ' || *inp == '\t')
		return (error_sep(inp + 1, x + 1, end));

	if (*inp == ';')
		if (end == '|' || end == '&' || end == ';')
			return (x);

	if (*inp == '|')
	{
		if (end == ';' || end == '&')
			return (x);

		if (end == '|')
		{
			sum = repchar(inp, 0);
			if (sum == 0 || sum > 1)
				return (x);
		}
	}

	if (*inp == '&')
	{
		if (end == ';' || end == '|')
			return (x);

		if (end == '&')
		{
			sum = repchar(inp, 0);
			if (sum == 0 || sum > 1)
				return (x);
		}
	}

	return (error_sep(inp + 1, x + 1, *inp));
}

/**
 * start_char - locates the index  char
 * @inp: insertion of string
 * @x: ...
 * Return: always answer
 */
int start_char(char *inp, int *x)

{

	for (*x = 0; inp[*x]; *x += 1)
	{
		if (inp[*x] == ' ' || inp[*x] == '\t')
			continue;

		if (inp[*x] == ';' || inp[*x] == '|' || inp[*x] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_synt_err - write  a syntax error
 * @info3: the raw info structure
 * @inp: insert of string
 * @x: index of the error
 * @bool: error controler
 * Return: no return
 */
void print_synt_err(info2 *info3, char *inp, int x, int bool)
{
	char *siri1, *siri2, *siri3, *makosa, *count;
	int l;

	if (inp[x] == ';')
	{
		if (bool == 0)
			siri1 = (inp[x + 1] == ';' ? ";;" : ";");
		else
			siri1 = (inp[x - 1] == ';' ? ";;" : ";");
	}

	if (inp[x] == '|')
		siri1 = (inp[x + 1] == '|' ? "||" : "|");

	if (inp[x] == '&')
		siri1 = (inp[x + 1] == '&' ? "&&" : "&");

	siri2 = ": Syntax error: \"";
	siri3 = "\" unexpected\n";
	count = a_ito(info3->count);
	l = _strlen(info3->aav[0]) + _strlen(count);
	l += _strlen(siri1) + _strlen(siri2) + _strlen(siri3) + 2;

	makosa = malloc(sizeof(char) * (l + 1));
	if (makosa == 0)
	{
		free(count);
		return;
	}
	_strcpy(makosa, info3->aav[0]);
	_strcat(makosa, ": ");
	_strcat(makosa, count);
	_strcat(makosa, siri2);
	_strcat(makosa, siri1);
	_strcat(makosa, siri3);
	_strcat(makosa, "\0");

	write(STDERR_FILENO, makosa, l);
	free(makosa);
	free(count);
}

/**
 * check_s_error - the  check functions
 * @info3: info struc of structure
 * @inp: insertion of string
 * Return: always answer
 */
int check_s_error(info2 *info3, char *inp)
{
	int stats = 0;
	int pp = 0;
	int x = 0;

	pp = start_char(inp, &stats);
	if (pp == -1)
	{
		print_synt_err(info3, inp, stats, 0);
		return (1);
	}

	x = error_sep(inp + stats, 0, *(inp + stats));
	if (x != 0)
	{
		print_synt_err(info3, inp, stats + x, 1);
		return (1);
	}

	return (0);
}
