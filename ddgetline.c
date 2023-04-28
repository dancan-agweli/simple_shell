#include "shel.h"

/**
 * get_line3 - function assigning
 * @lptr: stores the test stringr
 * @buff: string called to line
 * @m: the size of the line
 * @i: buffer size
 */
void get_line3(char **lptr, size_t *m, char *buff, size_t i)
{

	if (*lptr == NULL)
	{
		if  (i > BUFSIZE)
			*m = i;

		else
			*m = BUFSIZE;
		*lptr = buff;
	}
	else if (*m < i)
	{
		if (i > BUFSIZE)
			*m = i;
		else
			*m = BUFSIZE;
		*lptr = buff;
	}
	else
	{
		_strcpy(*lptr, buff);
		free(buff);
	}
}
/**
 * get_line - function that reads input stream
 * @lptr: binput
 * @m: size of lptr
 * @stream: this is the stream to read
 * Return: returns the total bytes
 */
ssize_t get_line(char **lptr, size_t *m, FILE *stream)
{
	int ka;
	static ssize_t x;
	ssize_t p;
	char *bfr;
	char d = 'z';

	if (ka == 0)
		fflush(stream);
	else
		return (-1);
	x = 0;

	bfr = malloc(sizeof(char) * BUFSIZE);
	if (bfr == 0)
		return (-1);
	while (d != '\n')
	{
		ka = read(STDIN_FILENO, &d, 1);
		if (ka == -1 || (ka == 0 && x == 0))
		{
			free(bfr);
			return (-1);
		}
		if (ka == 0 && x != 0)
		{
			x++;
			break;
		}
		if (x >= BUFSIZE)
			bfr = _reallocc(bfr, x, x + 1);
		bfr[x] = d;
		x++;
	}
	bfr[x] = '\0';
	get_line3(lptr, m, bfr, x);
	p = x;
	if (ka != 0)
		x = 0;
	return (p);
}

