#include <stdlib.h>
#include <stdio.h>

/**
 * check_malloc - check if malloc succeeded
 * @buffer: the malloc'd buffer
*/
void check_malloc(void *buffer)
{
	if (buffer == NULL)
	{
		puts("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
