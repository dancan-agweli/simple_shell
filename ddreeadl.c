#include "shel.h"
/**
 * readline1 - function that reads the test string
 * @x_eof: test string
 * Return: reads line
 */
char *readline1(int *x_eof)
{
	char *m = NULL;
	size_t p = 0;

	*x_eof = getline(&m, &p, stdin);
	return (m);
}

