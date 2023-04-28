#include "shel.h"

/**
 * _memcpy - handles information between void pointers.
 * @nptr: arrival pointer.
 * @pr: sourceof  pointer.
 * @sz: size of the avaailable pointer.
 * Return: nothing
 */
void _memcpy(void *nptr, const void *pr, unsigned int sz)
{
	char *x = (char *)pr;
	char *y = (char *)nptr;
	unsigned int w;

	for (w = 0; w < sz; w++)
		y[w] = x[w];
}

/**
 * _reallocc - the reallo a memory.
 * @pr: pointer  previously assigned.
 * @oldsz: ...
 * @newsz: new  memory.
 * Return: always the shell
 */
void *_reallocc(void *pr, unsigned int oldsz, unsigned int newsz)
{
	void *z;

	if (!pr)
		return (malloc(newsz));

	if (newsz == 0)
	{
		free(pr);
		return (NULL);
	}

	if (newsz == oldsz)
		return (pr);

	z = malloc(newsz);
	if (z == NULL)
		return (NULL);

	if (newsz < oldsz)
		_memcpy(z, pr, newsz);
	else
		_memcpy(z, pr, oldsz);

	free(pr);
	return (z);
}

/**
 * _reallocc2 - the memory memory block of ponter  to pointer.
 * @pr: ...
 * @oldsz: ...
 * @newsz: ....
 * Return: ponted pr
 */
char **_reallocc2(char **pr, unsigned int oldsz, unsigned int newsz)
{
	char **xx;
	unsigned int ww;

	if (!pr)
		return (malloc(sizeof(char *) * newsz));

	if (newsz == oldsz)
		return (pr);

	xx = malloc(sizeof(char *) * newsz);
	if (xx == NULL)
		return (NULL);

	for (ww = 0; ww < oldsz; ww++)
		xx[ww] = pr[ww];

	free(pr);

	return (xx);
}
