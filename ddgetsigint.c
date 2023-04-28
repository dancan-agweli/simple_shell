#include "shel.h"
/**
 * ge2_sigint - writes  crtl + c in shell
 *
 * @g: sign of handling
 */
void ge2_sigint(int g)
{
	(void)g;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

