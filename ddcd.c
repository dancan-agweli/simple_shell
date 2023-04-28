#include "shel.h"

/**
 * cddott - the parent directory
 * @info3: data relevant (envirnon)
 * Return: nothing
 */
void cddott(info2 *info3)
{
	char pwdd[PATH_MAX];
	char *dirr, *cppwd, *cpstrtokpwd;

	getcwd(pwdd, sizeof(pwdd));
	cppwd = _strdup(pwdd);
	setenvv("OLDPWD", cppwd, info3);
	dirr = info3->args[1];
	if (_strcmp(".", dirr) == 0)
	{
		setenvv("PWD", cppwd, info3);
		free(cppwd);
		return;
	}
	if (_strcmp("/", cppwd) == 0)
	{
		free(cppwd);
		return;
	}
	cpstrtokpwd = cppwd;
	rev_strings(cpstrtokpwd);
	cpstrtokpwd = _strtoks(cpstrtokpwd, "/");
	if (cpstrtokpwd != NULL)
	{
		cpstrtokpwd = _strtoks(NULL, "\0");

		if (cpstrtokpwd != NULL)
			rev_strings(cpstrtokpwd);
	}
	if (cpstrtokpwd != NULL)
	{
		chdir(cpstrtokpwd);
		setenvv("PWD", cpstrtokpwd, info3);
	}
	else
	{
		chdir("/");
		setenvv("PWD", "/", info3);
	}
	info3->status = 0;
	free(cppwd);
}

/**
 * cdto2 - finds to a directory given
 * @info3: datas relevant (directories)
 * Return: no returns
 */
void cdto2(info2 *info3)
{
	char pwdd[PATH_MAX];
	char *dirr, *cppwd, *cpdir;

	getcwd(pwdd, sizeof(pwdd));

	dirr = info3->args[1];
	if (chdir(dirr) == -1)
	{
		get1_err(info3, 2);
		return;
	}

	cppwd = _strdup(pwdd);
	setenvv("OLDPWD", cppwd, info3);

	cpdir = _strdup(dirr);
	setenvv("PWD", cpdir, info3);

	free(cppwd);
	free(cpdir);

	info3->status = 0;

	chdir(dirr);
}

/**
 * cdprev - changes to the previous directory
 * @info3: pointed (nenviron)
 * Return: nothing
 */
void cdprev(info2 *info3)
{
	char pwdd[PATH_MAX];
	char *ppwd, *poldpwd, *cppwd, *cpoldpwd;

	getcwd(pwdd, sizeof(pwdd));
	cppwd = _strdup(pwdd);

	poldpwd = getenv1("OLDPWD", info3->_environn);

	if (!poldpwd)
		cpoldpwd = cppwd;
	else
		cpoldpwd = _strdup(poldpwd);

	setenvv("OLDPWD", cppwd, info3);

	if (chdir(cpoldpwd) == -1)
		setenvv("PWD", cppwd, info3);
	else
		setenvv("PWD", cpoldpwd, info3);

	ppwd = getenv1("PWD", info3->_environn);

	write(STDOUT_FILENO, ppwd, _strlen(ppwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cppwd);
	if (poldpwd)
		free(cpoldpwd);

	info3->status = 0;

	chdir(ppwd);
}

/**
 * cdhome -  home directory
 * @info3: data relevant (environ)
 * Return: nothing
 */
void cdhome(info2 *info3)
{
	char *ppwd, *hme;
	char pwdd[PATH_MAX];

	getcwd(pwdd, sizeof(pwdd));
	ppwd = _strdup(pwdd);

	hme = getenv1("HOME", info3->_environn);

	while (hme == NULL)
	{
		setenvv("OLDPWD", ppwd, info3);
		free(ppwd);
		return;
	}

	if (chdir(hme) == -1)
	{
		get1_err(info3, 2);
		free(ppwd);
		return;
	}

	setenvv("OLDPWD", ppwd, info3);
	setenvv("PWD", hme, info3);
	free(ppwd);
	info3->status = 0;
}
