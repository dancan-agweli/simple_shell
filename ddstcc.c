#include "shel.h"
/**
 * _strcat - function concatenatinating two strings
 * @dt: distination to copy
 * @sc: source char
 * Return: returns the concatenated string
 */
char *_strcat(char *dt, const char *sc)
{
	int ka;
	int r;

	for (ka = 0; dt[ka] != '\0'; ka++)
		;
	for (r = 0; sc[r] != '\0'; r++)
	{
		dt[ka] = sc[r];
		ka++;
	}
	dt[ka] = '\0';
	return (dt);
}
/**
 * *_strcpy - function that copies string
 * @dt: destinatin string
 * @sc: source string
 * Return: returns the copied string
 */
char *_strcpy(char *dt, char *sc)
{

	size_t b;

	for (b = 0; sc[b] != '\0'; b++)
	{
		dt[b] = sc[b];
	}
	dt[b] = '\0';
	return (dt);
}
/**
 * _strcmp - compare strings
 * @s11: string to be compared
 * @s22: string to be compared
 * Return: returns 0.
 */
int _strcmp(char *s11, char *s22)
{
	int ka;

	for (ka = 0; s11[ka] == s22[ka] && s11[ka]; ka++)
		;
	if (s11[ka] > s22[ka])
		return (1);
	if (s11[ka] < s22[ka])
		return (-1);
	return (0);
}
/**
 * _strchr - function to locate a character in string
 * @ss: test string
 * @cc: char to test
 * Return: returns the firts occurrence of a char
 */
char *_strchr(char *ss, char cc)
{
	unsigned int ka = 0;

	for (; *(ss + ka) != '\0'; ka++)
		if (*(ss + ka) == cc)
			return (ss + ka);
	if (*(ss + ka) == cc)
		return (ss + ka);
	return ('\0');
}
/**
 * _strspn - functions that gets prefix string length
 * @ss: the start segment.
 * @acceps: bytes that are accepted
 * Return: returns the total accepted bytes.
 */
int _strspn(char *ss, char *acceps)
{
	int ka, r, bool;

	for (ka = 0; *(ss + ka) != '\0'; ka++)
	{
		bool = 1;
		for (r = 0; *(acceps + r) != '\0'; r++)
		{
			if (*(ss + ka) == *(acceps + r))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (ka);
}
