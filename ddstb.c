#include "shel.h"
/**
 * get_length - this function gets the length of an int
 * @m: integer number.
 * Return: returns the total length
 */
int get_length(int m)
{
	unsigned int p3;
	int rn = 1;

	if (m < 0)
	{
		rn++;
		p3 = m * -1;
	}
	else
	{
		p3 = m;
	}
	while (p3 > 9)
	{
		rn++;
		p3 = p3 / 10;
	}
	return (rn);
}
/**
 * a_ito - this function converts interger to string
 * @m: test integer
 * Return: returns a string
 */
char *a_ito(int m)
{
	unsigned int p3;
	int rn = get_length(m);
	char *rb3;

	rb3 = malloc(sizeof(char) * (rn + 1));
	if (rb3 == 0)
		return (NULL);
	*(rb3 + rn) = '\0';
	if (m < 0)
	{
		p3 = m * -1;
		rb3[0] = '-';
	}
	else
	{
		p3 = m;
	}
	rn--;
	do {
		*(rb3 + rn) = (p3 % 10) + '0';
		p3 = p3 / 10;
		rn--;
	}
	while (p3 > 0)
		;
	return (rb3);
}
/**
 * _atoiii - function converting string to integer
 * @r: string to convert.
 * Return: returns the converted integer.
 */
int _atoiii(char *r)
{
	unsigned int num = 0, length = 0, p = 0, rn = 1, n = 1, ka;

	while (*(r + num) != '\0')
	{
		if (length > 0 && (*(r + num) < '0' || *(r + num) > '9'))
			break;
		if (*(r + num) == '-')
			rn *= -1;
		if ((*(r + num) >= '0') && (*(r + num) <= '9'))
		{
			if (length > 0)
				n *= 10;
			length++;
		}
		num++;
	}
	for (ka = num - length; ka < num; ka++)
	{
		p = p + ((*(r + ka) - 48) * n);
		n /= 10;
	}
	return (p * rn);
}
