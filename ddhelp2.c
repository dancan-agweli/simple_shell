#include "shel.h"

/**
 * _help - Gathres information for the builtin help.
 * Return: nothing
 */
void _help(void)
{
	char *aid = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "\tprints  builtin commands.\n ";
	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "printssummaries of builtin commands.\n";
	write(STDOUT_FILENO, aid, _strlen(aid));
}
/**
 * _help1_alias - the builtin alias.
 * Return: nothing
 */
void _help1_alias(void)
{
	char *aid = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "\tdisplay aliases.\n ";
	write(STDOUT_FILENO, aid, _strlen(aid));
}
/**
 * _help_cdd - the information for the builtin directory.
 *
 * Return: nothing
 */
void _help_cdd(void)
{
	char *aid = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "\tshell working directory.\n ";
	write(STDOUT_FILENO, aid, _strlen(aid));
}
