#include "shel.h"

/**
 * fdt2 - functi for freeing data
 * @info3: pointer to struct
 */
void fdt2(info2 *info3)
{
	unsigned int ka;

	for (ka = 0; info3->_environn[ka]; ka++)
	{
		free(info3->_environn[ka]);
	}
	free(info3->_environn);
	free(info3->pid);
}
/**
 * dst - this function initializes a struct
 * @info3: struct pointer
 * @aav: the argument vecttor
 */
void dst(info2 *info3, char **aav)
{
	unsigned int ka;

	info3->aav = aav;
	info3->in = NULL;
	info3->args = NULL;
	info3->status = 0;
	info3->count = 1;
	for (ka = 0; environ[ka]; ka++)
		;
	info3->_environn = malloc(sizeof(char *) * (ka + 1));
	for (ka = 0; environ[ka]; ka++)
	{
		info3->_environn[ka] = _strdup(environ[ka]);
	}
	info3->_environn[ka] = NULL;
	info3->pid = a_ito(getpid());
}
/**
 * main - start point
 * @ac: this count number of arguments
 * @av: The argument variable
 * Return: returns 0 if successful
 */
int main(int ac, char **av)
{
	info2 info3;
	(void) ac;

	signal(SIGINT, ge2_sigint);
	dst(&info3, av);
	s_loop(&info3);
	fdt2(&info3);
	if (info3.status < 0)
		return (255);
	return (info3.status);
}

