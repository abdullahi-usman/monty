#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * monty_trim - trim string at both ends
 * @str: the string
 * Return: Void
*/
void monty_trim(char **str)
{
	int len = 0;

	while (1)
	{
		if (isspace((**str)) != 0)
			++(*str);
		else
			break;
	}

	len = (int)strlen(*str);
	while (1)
	{
		if (len > 0 && (isspace((*str)[--len])) != 0)
			(*str)[len] = '\0';
		else
			break;
	}
}
