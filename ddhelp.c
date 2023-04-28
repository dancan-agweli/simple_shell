#include "shel.h"

/**
 * help1_envv - Gather the builtin env
 * Return: nothing
 */
void help1_envv(void)
{
	char *aid = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "enviroment of the shell.\n";
	write(STDOUT_FILENO, aid, _strlen(aid));

}
/**
 * help2_setenvv - the builtin setenv
 *
 * Return: nothing
 */
void help2_setenvv(void)
{

	char *aid = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "int replace)\n\t";
	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "Append new the environment\n";
	write(STDOUT_FILENO, aid, _strlen(aid));
}
/**
 * help2_unsetenvv - the builtin unsetenv
 * Return: no return
 */
void help2_unsetenvv(void)
{
	char *aid = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "Removethe environment\n";
	write(STDOUT_FILENO, aid, _strlen(aid));
}


/**
 * help2_general - Entry point for the help builtin
 * Return: no return
 */
void help2_general(void)
{
	char *aid = "^-^ bash, version 1.0(2)-release\n";

	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "unsetenv [variable]\n";
	write(STDOUT_FILENO, aid, _strlen(aid));
}
/**
 * help_exitt - Help information fot the built exit
 * Return: no return
 */
void help_exitt(void)
{
	char *aid = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "Quit the shell a status of N.";
	write(STDOUT_FILENO, aid, _strlen(aid));
	aid = "statuss of  end command executed\n";
	write(STDOUT_FILENO, aid, _strlen(aid));
}
