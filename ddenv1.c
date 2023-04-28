#include "shel.h"
/**
 * cmp_env_name - fucntion that checks foir the
 * comparison between environmental variables
 * @ennV1: env variable
 * @n2m: name
 * Return: returns 0 if same
 */
int cmp_env_name(const char *ennV1, const char *n2m)
{
	int ba;

	for (ba = 0; ennV1[ba] != '='; ba++)
	{
		if (ennV1[ba] != n2m[ba])
		{
			return (0);
		}
	}
	return (ba + 1);
}
/**
 * getenv1 - function to acquire environmental variable
 * @namee: the envi nam
 * @_environn: the variable itself
 * Return: returns the env value or NULL
 */
char *getenv1(const char *namee, char **_environn)
{
	char *penn;
	int j, pm;

	penn = NULL;
	pm = 0;
	for (j = 0; _environn[j]; j++)
	{
		pm = cmp_env_name(_environn[j], namee);
		if (pm)
		{
			penn = _environn[j];
			break;
		}
	}
	return (penn + pm);
}
/**
 * env1 - function that prints out envi variables
 * @info3: pointer to struct
 * Return: 1 on success.
 */
int env1(info2 *info3)
{
	int ka, r;

	for (ka = 0; info3->_environn[ka]; ka++)
	{
		for (r = 0; info3->_environn[ka][r]; r++)
			;
		write(STDOUT_FILENO, info3->_environn[ka], r);
		write(STDOUT_FILENO, "\n", 1);
	}
	info3->status = 0;
	return (1);
}

