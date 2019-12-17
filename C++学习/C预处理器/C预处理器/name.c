#include<stdio.h>
#include "name.h"

void get_names(names *pn)
{
	printf("please enter your first name:");
	s_gets(pn->first, SLEN);
	printf("please enter your last name:");
	s_gets(pn->last, SLEN);
}

void show_names(names *pn)
{
	printf("%s %s", pn->first, pn->last);
}

char * s_gets(char *st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}