#include <stdlib.h>
#include <stdio.h>


/**
 * main - program entry point
 * @argc: argument count
 * @argv: arguments
 * Return: exit code
*/
int main(int argc, char **argv)
{
	char *command = NULL;
	char *operations = NULL;
	int c = 0;

	if (argv != NULL)
	{
		printf("encounter line %s:\n", *(argv));
		argv++;

		if (c == 1)
		{bett
			command = *(argv);
		}
		else if (c == 2)
		{
			operations = *(argv);
		}
	}

	return (0);
}
