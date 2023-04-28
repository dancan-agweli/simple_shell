#include "shel.h"

/**
 * er2_envir - show the error message
 * @info3: pointer to struct
 * Return: returns the pointer to the error message.
 */
char *er2_envir(info2 *info3)
{
	int rn2;
	char *err;
	char *ver;
	char *mess;

	ver = a_ito(info3->count);
	mess = ": Can neither add or remove\n";
	rn2 = _strlen(info3->aav[0]) + _strlen(ver);
	rn2 += _strlen(info3->args[0]) + _strlen(mess) + 4;
	err = malloc(sizeof(char) * (rn2 + 1));

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

	_strcat(err, mess);
	_strcat(err, "\0");
	free(ver);
	return (err);
}
/**
 * error_path - prints an error message if not permitted
 * @info3: info3 to a struct
 * Return: returns the string with an error message
 */
char *error_path(info2 *info3)
{
	int rn23;
	char *vr5;
	char *er6;

	vr5 = a_ito(info3->count);
	rn23 = _strlen(info3->aav[0]) + _strlen(vr5);
	rn23 += _strlen(info3->args[0]) + 24;
	er6 = malloc(sizeof(char) * (rn23 + 1));
	if (er6 == 0)
	{
		free(er6);
		free(vr5);
		return (NULL);
	}
	_strcpy(er6, info3->aav[0]);
	_strcat(er6, ": ");
	_strcat(er6, vr5);
	_strcat(er6, ": ");
	_strcat(er6, info3->args[0]);
	_strcat(er6, ": denied permission\n");
	_strcat(er6, "\0");
	free(vr5);
	return (er6);
}
