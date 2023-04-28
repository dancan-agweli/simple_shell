#include "shel.h"

/**
 * add_sep_node_end - adds a separators
 * @headd: the linked list.
 * @sep: separators(; | &).
 * Return: always answer..
 */
sep_list *add_sep_node_end(sep_list **headd, char sep)
{
	sep_list *fresh, *swapp;

	fresh = malloc(sizeof(sep_list));
	if (fresh == NULL)
		return (NULL);

	fresh->sep = sep;
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
 * free_sep_list - realieses a sep_list
 * @headd: ...
 * Return: nothing
 */
void free_sep_list(sep_list **headd)
{
	sep_list *swapp;
	sep_list *rc;

	if (headd != NULL)
	{
		rc = *headd;
		while ((swapp = rc) != NULL)
		{
			rc = rc->next;
			free(swapp);
		}
		*headd = NULL;
	}
}

/**
 * add_line_node_end - prints the command line at the end
 * @headd: the linked list.
 * @line: cmd line.
 * Return: address of the head.
 */
line_list *add_line_node_end(line_list **headd, char *line)
{
	line_list *fresh, *swapp;

	fresh = malloc(sizeof(line_list));
	if (fresh == NULL)
		return (NULL);

	fresh->line = line;
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
 * free_line_list - realises line_list
 * @headd: ...
 * Return: no return.
 */
void free_line_list(line_list **headd)
{
	line_list *swapp;
	line_list *rc;

	if (headd != NULL)
	{
		rc = *headd;
		while ((swapp = rc) != NULL)
		{
			rc = rc->next;
			free(swapp);
		}
		*headd = NULL;
	}
}
