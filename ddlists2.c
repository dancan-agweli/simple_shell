#include "shel.h"

/**
 * add_rvar_node - appends a variable at the latter.
 * @headd: core of singly linked
 * @lenvar: length.
 * @valuee: variable valuee.
 * @lenval: length in the data typelue.
 * Return: sucess on answer.
 */
r_var *add_rvar_node(r_var **headd, int lenvar, char *valuee, int lenval)
{
	r_var *fresh, *swapp;

	fresh = malloc(sizeof(r_var));
	if (!fresh)
		return (NULL);

	fresh->lenvar = lenvar;
	fresh->valuee = valuee;
	fresh->lenval = lenval;

	fresh->next = NULL;
	swapp = *headd;

	if (swapp == NULL)
	{
		*headd = fresh;
	}
	else
	{
		while (swapp->next != NULL)
			swapp = swapp->next;
		swapp->next = fresh;
	}

	return (*headd);
}

/**
 * free_rvar_list - realease  list
 * @headd: ...
 * Return: no return.
 */
void free_rvar_list(r_var **headd)
{
	r_var *sw;
	r_var *rc;

	if (headd != NULL)
	{
		rc = *headd;
		while ((sw = rc) != NULL)
		{
			rc = rc->next;
			free(sw);
		}
		*headd = NULL;
	}
}
