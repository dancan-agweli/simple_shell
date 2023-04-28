#include "shel.h"
/**
 * copyinff - creates copies of values
 * @namee: the name of the var
 * @vlue: value env
 * Return: return the new env var.
 */
char *copyinff(char *namee, char *vlue)
{
	char *brn;
	int nml2, vln, rn3;

	nml2 = _strlen(namee);
	vln = _strlen(vlue);
	rn3 = nml2 + vln + 2;
	brn = malloc(sizeof(char) * (rn3));

	_strcpy(brn, namee);
	_strcat(brn, "=");

	_strcat(brn, vlue);
	_strcat(brn, "\0");
	return (brn);
}
/**
 * setenvv - functin setting env variable
 * @namee: the env var name
 * @vlue: environment var value
 * @info3: pointer to struct
 */
void setenvv(char *namee, char *vlue, info2 *info3)
{
	int ka;
	char *rv3, *vn2m;

	for (ka = 0; info3->_environn[ka]; ka++)
	{
		rv3 = _strdup(info3->_environn[ka]);
		vn2m = _strtoks(rv3, "=");
		if (_strcmp(vn2m, namee) == 0)
		{
			free(info3->_environn[ka]);
			info3->_environn[ka] = copyinff(vn2m, vlue);
			free(rv3);

			return;
		}
		free(rv3);
	}
	info3->_environn = _reallocc2(info3->_environn, ka,
	sizeof(char *) * (ka + 2));
	info3->_environn[ka] = copyinff(namee, vlue);
	info3->_environn[ka + 1] = NULL;
}

/**
 * setenv1 - function that compares env vars
 * with the name passed.
 * @info3: pointer to struct
 * Return: returns 1 if successful
 */
int setenv1(info2 *info3)
{
	if (info3->args[1] == NULL || info3->args[2] == NULL)
	{
		get1_err(info3, -1);
		return (1);
	}
	setenvv(info3->args[1], info3->args[2], info3);
	return (1);
}
/**
 * unsetenvv2 - function deleting an
 * environmental variabel
 * @info3: pointer to struct
 * Return: returcns 1 when successful
 */
int unsetenvv2(info2 *info3)
{
	char **envr3c;
	char *vrn, *vnm;
	int ka, r, p;

	if (info3->args[1] == NULL)
	{
		get1_err(info3, -1);
		return (1);
	}
	p = -1;
	for (ka = 0; info3->_environn[ka]; ka++)
	{
		vrn = _strdup(info3->_environn[ka]);
		vnm = _strtoks(vrn, "=");
		if (_strcmp(vnm, info3->args[1]) == 0)
		{
			p = ka;
		}
		free(vrn);
	}
	if (p == -1)
	{
		get1_err(info3, -1);
		return (1);
	}
	envr3c = malloc(sizeof(char *) * (ka));
	for (ka = r = 0; info3->_environn[ka]; ka++)
	{
		if (ka != p)
		{
			envr3c[r] = info3->_environn[ka];
			r++;
		}
	}
	envr3c[r] = NULL;
	free(info3->_environn[p]);
	free(info3->_environn);
	info3->_environn = envr3c;
	return (1);
}

