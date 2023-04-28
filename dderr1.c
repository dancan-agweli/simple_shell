#include "shel.h"
/**
 * strctCd - Concatenates strings and sets illegal flag if necessary
 * @info3: Struct containing the strings to concatenate
 * @err: String to store the concatenated result
 * @ver: Version string
 * @mess: Message string
 *
 * Return: Pointer to the concatenated string
 */
char *strctCd(info2 *info3, char *mess, char *err, char *ver)
{
	char *fl;

	_strcpy(err, info3->aav[0]);
	_strcat(err, ": ");
	_strcat(err, ver);
	_strcat(err, ": ");
	_strcat(err, info3->args[0]);
	_strcat(err, mess);

	if (info3->args[1][0] == '-')
	{
		fl = malloc(3);
		fl[0] = '-';
		fl[1] = info3->args[1][1];
		fl[2] = '\0';
		_strcat(err, fl);
		free(fl);
	}
	else
	{
		_strcat(err, info3->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}
/**
 * err_cd - Creates an error message for the cd command
 * @info3: Struct containing the strings to concatenate
 *
 * Return: Pointer to the concatenated string
 */
char *err_cd(info2 *info3)
{
	int len1, dln;
	char *err, *ver, *mess;

	ver = a_ito(info3->count);
	if (info3->args[1][0] == '-')
	{
		mess = ": option not legal ";
		dln = 2;
	}
	else
	{
		mess = ": cannot cd to ";
		dln = _strlen(info3->args[1]);
	}
	len1 = _strlen(info3->aav[0]) + _strlen(info3->args[0]);
	len1 += _strlen(ver) + _strlen(mess) + dln + 5;
	err = malloc(sizeof(char) * (len1 + 1));
	if (err == 0)
	{
		free(ver);
		return (NULL);
	}
	err = strctCd(info3, mess, err, ver);
	free(ver);
	return (err);
}
/**
 * err_unfound - Creates an error message for a file not found
 * @info3: Struct containing the strings to concatenate
 *
 * Return: Pointer to the concatenated string
 */
char *err_unfound(info2 *info3)
{
	int len1;
	char *err;
	char *ver;

	ver = a_ito(info3->count);
	len1 = _strlen(info3->aav[0]) + _strlen(ver);
	len1 += _strlen(info3->args[0]) + 16;
	err = malloc(sizeof(char) * (len1 + 1));
	if (err == 0)
	{
		free(err);
		free(ver);
		return (NULL);
	}
	_strcpy(err, info3->aav[0]);
	_strcat(err, ": ");
	_strcat(err, ver);
	_strcat(err, ": ");
	_strcat(err, info3->args[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver);
	return (err);
}
/**
 * err_exitshell - function to create exit shell error messages
 * @info3: Pointer to a struct of info about the arguments
 *
 * Return: Pointer to the error message
 */
char *err_exitshell(info2 *info3)
{
	int len;
	char *err;
	char *ver;

	ver = a_ito(info3->count);
	len = _strlen(info3->aav[0]) + _strlen(ver);
	len += _strlen(info3->args[0]) + _strlen(info3->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ver);
		return (NULL);
	}
	_strcpy(err, info3->aav[0]);
	_strcat(err, ": ");
	_strcat(err, ver);

	_strcat(err, ": ");
	_strcat(err, info3->args[0]);

	_strcat(err, ": Number illegal: ");
	_strcat(err, info3->args[1]);

	_strcat(err, "\n\0");
	free(ver);
	return (err);
}
