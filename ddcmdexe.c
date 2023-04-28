#include "shel.h"

/**
 * iscdir - checks :if is in the current directory.
 * @path: type char pointer in shell
 * @j: type int pointer of index.
 * Return:  if the path is available in the cd 1, 0 otherwise.
 */
int iscdir(char *path, int *j)
{
	while (path[*j] == ':')
		return (1);

	while (path[*j] != ':' && path[*j])
	{
		*j += 1;
	}

	while (path[*j])
		*j += 1;

	return (0);
}

/**
 * _wh - Finds the a command
 * @cmd: command names in the program
 * @_environn: environment of the variable
 * Return: location of the cmd
 */
char *_wh(char *cmd, char **_environn)
{
	char *paths, *ptrpath, *t_path, *dirr;
	int lendir, lencmd, x;
	struct stat stt;

	paths = getenv1("PATH", _environn);
	if (paths)
	{
		ptrpath = _strdup(paths);
		lencmd = _strlen(cmd);
		t_path = _strtoks(ptrpath, ":");
		x = 0;
		while (t_path != NULL)
		{
			if (iscdir(paths, &x))
				if (stat(cmd, &stt) == 0)
					return (cmd);
			lendir = _strlen(t_path);
			dirr = malloc(lendir + lencmd + 2);
			_strcpy(dirr, t_path);
			_strcat(dirr, "/");
			_strcat(dirr, cmd);
			_strcat(dirr, "\0");
			if (stat(dirr, &stt) == 0)
			{
				free(ptrpath);
				return (dirr);
			}
			free(dirr);
			t_path = _strtoks(NULL, ":");
		}
		free(ptrpath);
		if (stat(cmd, &stt) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &stt) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - finds if is an executable
 * @info3: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_executable(info2 *info3)
{
	struct stat stt;
	int x;
	char *inp;

	inp = info3->args[0];
	for (x = 0; inp[x]; x++)
	{
		if (inp[x] == '.')
		{
			if (inp[x + 1] == '.')
				return (0);
			if (inp[x + 1] == '/')
				continue;
			else
				break;
		}
		else if (inp[x] == '/' && x != 0)
		{
			if (inp[x + 1] == '.')
				continue;
			x++;
			break;
		}
		else
			break;
	}
	if (x == 0)
		return (0);

	if (stat(inp + x, &stt) == 0)
	{
		return (x);
	}
	get1_err(info3, 127);
	return (-1);
}

/**
 * checkerrcmd - finds if user has permissions to access
 * @dir: the  directory
 * @info3: data structure
 * Return: 1 if  is an error, 0 if not
 */
int checkerrcmd(char *dir, info2 *info3)
{
	if (dir == NULL)
	{
		get1_err(info3, 127);
		return (1);
	}

	if (_strcmp(info3->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get1_err(info3, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(info3->args[0], X_OK) == -1)
		{
			get1_err(info3, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmdexec - executes commandss in shell
 * @info3: relevant (args and input)
 * Return: always 1 on success.
 */
int cmexec(info2 *info3)
{
	pid_t pd;
	pid_t wpd;
	int statt;
	int excc;
	char *dirr;
	(void) wpd;

	excc = is_executable(info3);
	if (excc == -1)
		return (1);
	if (excc == 0)
	{
		dirr = _wh(info3->args[0], info3->_environn);
		if (checkerrcmd(dirr, info3) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (excc == 0)
			dirr = _wh(info3->args[0], info3->_environn);
		else
			dirr = info3->args[0];
		execve(dirr + excc, info3->args, info3->_environn);
	}
	else if (pd < 0)
	{
		perror(info3->aav[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &statt, WUNTRACED);
		} while (!WIFEXITED(statt) && !WIFSIGNALED(statt));
	}

	info3->status = statt / 256;
	return (1);
}
