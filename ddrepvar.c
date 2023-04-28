#include "shel.h"
/**
 * check_environment - function to check wether environmental var
 * @h: link list head
 * @n: string to test
 * @info3: pointer to struct
 */
void check_environment(r_var **h, char *n, info2 *info3)
{
	int pr, mn, r, x;
	char **sn;

	sn = info3->_environn;
	for (pr = 0; sn[pr]; pr++)
	{
		for (r = 1, mn = 0; sn[pr][mn]; mn++)
		{
			if (sn[pr][mn] == '=')
			{
				x = _strlen(sn[pr] + mn + 1);
				add_rvar_node(h, r, sn[pr] + mn + 1, x);
				return;
			}

			if (n[r] == sn[pr][mn])
				r++;
			else
				break;
		}
	}

	for (r = 0; n[r]; r++)
	{
		if (n[r] == ' ' || n[r] == '\t' || n[r] == ';' || n[r] == '\n')
			break;
	}
	add_rvar_node(h, r, NULL, 0);
}
/**
 * checkvars - function checks if ?
 * @h: link list head
 * @n: string to check
 * @s: the previous ststus of the shell
 * @info3: pointer struct
 * Return: return 0
 */
int checkvars(r_var **h, char *n, char *s, info2 *info3)
{
	int i, lst, lpd;
	int ka, f, d;

	f = _strlen(s);
	d = _strlen(info3->pid);
	for (ka = 0; n[ka]; ka++)
	{
		if (n[ka] == '$')
		{
			if (n[ka + 1] == '?')
				add_rvar_node(h, 2, s, f), ka++;
			else if (n[ka + 1] == '$')
				add_rvar_node(h, 2, info3->pid, f), ka++;
			else if (n[ka + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (n[ka + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (n[ka + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (n[ka + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (n[ka + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_environment(h, n + ka, info3);
		}
	}

	return (ka);
}
/**
 * rep__input - this function is replacing strings to variables
 * @headd: linked list head
 * @inp: string to test
 * @nwinp: string to replace
 * @lenn: length new
 * Return: returns the returned string
 */
char *rep__input(r_var **headd, char *inp, char *nwinp, int lenn)
{
	r_var *tr;
	int ka, r, p;

	tr = *headd;
	for (r = ka = 0; ka < lenn; ka++)
	{
		if (inp[r] == '$')
		{
			if (!(tr->lenvar) && !(tr->lenval))
			{
				nwinp[ka] = inp[r];
				r++;
			}
			else if (tr->lenvar && !(tr->lenval))
			{
				for (p = 0; p < tr->lenvar; p++)
					r++;
				ka--;
			}
			else
			{
				for (p = 0; p < tr->lenval; p++)
				{
					nwinp[ka] = tr->valuee[p];
					ka++;
				}
				r += (tr->lenvar);
				ka--;
			}
			tr = tr->next;
		}
		else
		{
			nwinp[ka] = inp[r];
			r++;
		}
	}

	return (nwinp);
}
/**
 * replace_var - function that calls functions replacing strings
 * @inp: test string
 * @info3: pointer to struct
 * Return: returns the string replaced
 */
char *replace_var(char *inp, info2 *info3)
{
	r_var *d, *tr;
	char *s, *it;
	int pen, lenn;

	s = a_ito(info3->status);
	d = NULL;
	pen = checkvars(&d, inp, s, info3);
	if (d == NULL)
	{
		free(s);
		return (inp);
	}
	tr = d;
	lenn = 0;
	while (tr != NULL)
	{
		lenn += (tr->lenval - tr->lenvar);
		tr = tr->next;
	}
	lenn += pen;
	it = malloc(sizeof(char) * (lenn + 1));
	it[lenn] = '\0';
	it = rep__input(&d, inp, it, lenn);
	free(inp);
	free(s);
	free_rvar_list(&d);
	return (it);
}

