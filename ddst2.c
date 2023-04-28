#include "shel.h"

/**
 * _strdup - function that duplicates a string
 * @ss: string to duplicate
 * Return: returns the duplicate string
 */
char *_strdup(const char *ss)
{
	char *p;
	size_t rn;

	rn = _strlen(ss);
	p = malloc(sizeof(char) * (rn + 1));
	if (p == NULL)
		return (NULL);
	_memcpy(p, ss, rn + 1);
	return (p);
}
/**
 * _strlen - function that gets the string length
 * @ss: string to find length
 * Return: returns the length of the string
 */
int _strlen(const char *ss)
{
	int rn;

	for (rn = 0; ss[rn] != 0; rn++)
	{
	}
	return (rn);
}
/**
 * cmp_charss - function comparing chars in strings
 * @strs: test string
 * @delm: this is the delimeter
 * Return: if equal, return is 1, if not 0
 */
int cmp_charss(char strs[], const char *delm)
{
	unsigned int ka, r, p;

	for (ka = 0, p = 0; strs[ka]; ka++)
	{
		for (r = 0; delm[r]; r++)
		{
			if (strs[ka] == delm[r])
			{
				p++;
				break;
			}
		}
	}
	if (ka == p)
		return (1);
	return (0);
}
/**
 * _strtoks - function spilliting strings by delimeter
 * @strs: test string.
 * @delm: this is the delimeter.
 * Return: returnrns the string spliyted
 */
char *_strtoks(char strs[], const char *delm)
{
	static char *sl, *sd;
	char *st;
	unsigned int ka, bool;

	if (strs != NULL)
	{
		if (cmp_charss(strs, delm))
			return (NULL);
		sl = strs;
		ka = _strlen(strs);
		sd = &strs[ka];
	}
	st = sl;
	if (st == sd)
		return (NULL);

	for (bool = 0; *sl; sl++)
	{
		if (sl != st)
			if (*sl && *(sl - 1) == '\0')
				break;
		for (ka = 0; delm[ka]; ka++)
		{
			if (*sl == delm[ka])
			{
				*sl = '\0';
				if (sl == st)
					st++;
				break;
			}
		}
		if (bool == 0 && *sl)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (st);
}
/**
 * _isdigits - checks if string is a digit
 * @ss: test string
 * Return: if str is a num returns 1, 0, otherwise.
 */
int _isdigits(const char *ss)
{
	unsigned int ka;

	for (ka = 0; ss[ka]; ka++)
	{
		if (ss[ka] < 48 || ss[ka] > 57)
			return (0);
	}
	return (1);
}
