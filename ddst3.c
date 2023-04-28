#include "shel.h"
/**
 * rev_strings -function that  reverses a string.
 * @ss: test string.
 */
void rev_strings(char *ss)
{
	int num = 0, ka, r;
	char *rs, p;

	while (num >= 0)
	{
		if (ss[num] == '\0')
			break;
		num++;
	}
	rs = ss;
	for (ka = 0; ka < (num - 1); ka++)
	{
		for (r = ka + 1; r > 0; r--)
		{
			p = *(rs + r);
			*(rs + r) = *(rs + (r - 1));
			*(rs + (r - 1)) = p;
		}
	}
}
