#include "shel.h"
/**
 * swpch - this function swaps schars
 * @inp: test string
 * @bool: this is type
 * Return: returns the string swapped
 */
char *swpch(char *inp, int bool)
{
	int ka;

	if (bool == 0)
	{
		for (ka = 0; inp[ka]; ka++)
		{
			if (inp[ka] == '|')
			{
				if (inp[ka + 1] != '|')
					inp[ka] = 16;
				else
					ka++;
			}
			if (inp[ka] == '&')
			{
				if (inp[ka + 1] != '&')
					inp[ka] = 12;
				else
					ka++;
			}
		}
	}
	else
	{
		for (ka = 0; inp[ka]; ka++)
		{
			inp[ka] = (inp[ka] == 16 ? '|' : inp[ka]);
			inp[ka] = (inp[ka] == 12 ? '&' : inp[ka]);
		}
	}
	return (inp);
}
/**
 * add_node1 - function adding sep list to line list
 * @head_ss: sep list head
 * @head_ll: line list head
 * @inp: string to test
 */
void add_node1(sep_list **head_ss, line_list **head_ll, char *inp)
{
	int ka;
	char *rn;

	inp = swpch(inp, 0);
	for (ka = 0; inp[ka]; ka++)
	{
		if (inp[ka] == ';')
			add_sep_node_end(head_ss, inp[ka]);

		if (inp[ka] == '|' || inp[ka] == '&')
		{
			add_sep_node_end(head_ss, inp[ka]);
			ka++;
		}
	}
	rn = _strtoks(inp, ";|&");
	do {
		rn = swpch(rn, 1);
		add_line_node_end(head_ll, rn);
		rn = _strtoks(NULL, ";|&");
	} while (rn != NULL);
}
/**
 * go_next - goes to the command nest
 * @list_ss: list of seps
 * @list_ll: list of line
 * @info3: pointer to struct
 */
void go_next(sep_list **list_ss, line_list **list_ll, info2 *info3)
{
	int prl;
	sep_list *kn;
	line_list *br;

	prl = 1;
	kn = *list_ss;
	br = *list_ll;
	while (kn != NULL && prl)
	{
		if (info3->status == 0)
		{
			if (kn->sep == '&' || kn->sep == ';')
				prl = 0;
			if (kn->sep == '|')
				br = br->next, kn = kn->next;
		}
		else
		{
			if (kn->sep == '|' || kn->sep == ';')
				prl = 0;
			if (kn->sep == '&')
				br = br->next, kn = kn->next;
		}
		if (kn != NULL && !prl)
			kn = kn->next;
	}
	*list_ss = kn;
	*list_ll = br;
}
/**
 * spltcmd - function that splits commands
 * @info3: pointer to struct
 * @inp: string to test
 * Return: returns 0 when exit
 */
int spltcmd(info2 *info3, char *inp)
{

	sep_list *hs, *ls;
	line_list *hl, *ll;
	int x;

	hs = NULL;
	hl = NULL;
	add_node1(&hs, &hl, inp);
	ls = hs;
	ll = hl;

	while (ll != NULL)
	{
		info3->inp = ll->line;
		info3->args = spltlne(info3->inp);
		x = executeline1(info3);
		free(info3->args);
		if (x == 0)
			break;
		go_next(&ls, &ll, info3);
		if (ll != NULL)
			ll = ll->next;
	}
	free_sep_list(&hs);
	free_line_list(&hl);
	if (x == 0)
		return (0);
	return (1);
}
/**
 * spltlne - this function tokenizes strings
 * @inp: test string
 * Return: returns the split string
 */
char **spltlne(char *inp)
{
	size_t length;
	size_t ka;
	char **ds;
	char *d;

	length = TOK_BUFSIZE;
	ds = malloc(sizeof(char *) * (length));
	if (!ds)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}
	d = _strtoks(inp, TOK_DELM);
	ds[0] = d;
	for (ka = 1; d != NULL; ka++)
	{
		if (ka == length)
		{
			length += TOK_BUFSIZE;
			d = _reallocc(ds, ka, sizeof(char *) * length);
			if (d == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		d = _strtoks(NULL, TOK_DELM);
		ds[ka] = d;
	}

	return (ds);
}

