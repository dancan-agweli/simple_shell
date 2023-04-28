#include "shel.h"

/**
 * executeline1 - the builtins cmd
 * @info3: infor of the data
 * Return: return sucess
 */
int executeline1(info2 *info3)
{
	int (*builtin)(info2 *info3);

	if (info3->args[0] == NULL)
		return (1);

	builtin = get_builtin(info3->args[0]);

	while (builtin != NULL)
		return (builtin(info3));

	return (cmexec(info3));
}
