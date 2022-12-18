#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "monty.h"

static const char *PUSH = "push";
static const char *PALL = "pall";

/**
 * check_argc - check argc
 * @argc: the argc
 * Return: Void
 */
void check_argc(int argc)
{
	if (argc != 2)
	{
		puts("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
}

/**
 * open_commandfile - open command file
 * @file: the file
 * Return: the open file
 */
FILE *open_commandfile(char *file)
{
	FILE *fd = NULL;

	fd = fopen(file, "rb");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * write_command_and_opcode - write command and opcode
 * @word_sep: word seperator
 * @command: command
 * @opcode: opcode
 * Return: Void
*/
void write_command_and_opcode(char *word_sep, char **command, char **opcode)
{
	char *word = NULL;
	int word_pos = 0;

	while ((word = strtok(word_sep, " ")) != NULL)
	{
		if (strcmp(word, " ") == 0)
		{
			break;
		}
		else if (word_pos == 0)
		{
			*command = word;
		}
		else if (word_pos == 1)
		{
			*opcode = word;
		}

		word_pos++;
		word_sep = NULL;
	}
}

/**
 * main - program entry point
 * @argc: argument count
 * @argv: arguments
 * Return: exit code
 */
int main(int argc, char **argv)
{
	char *command_file = NULL, *command = NULL, *opcode = NULL;
	int line_number = 0, buffer_size = sizeof(char) * 2000;
	char *buffer = (char *)malloc(buffer_size), *word_sep = NULL;
	FILE *fd = NULL;
	stack_t *ret_stack = NULL, *stack = NULL;

	check_argc(argc);
	command_file = *(++argv);
	fd = open_commandfile(command_file);
	check_malloc(buffer);

	while ((word_sep = fgets(buffer, buffer_size, fd)) != NULL)
	{
		line_number++;
		monty_trim(&word_sep);
		if (strchr(word_sep, ' ') == NULL)
		{
			command = word_sep;
			if (strchr(command, '\n') != NULL)
			{
				command[strlen(command) - 1] = '\0';
			}
		} else
		{
			write_command_and_opcode(word_sep, &command, &opcode);
		}

		if (strcmp(command, PUSH) == 0)
			push(&stack, atoi(opcode));
		else if (strcmp(command, PALL) == 0)
		{
			while ((ret_stack = pop(&stack)) != NULL)
			{
				printf("%d\n", ret_stack->n);
			}
		}
		command = NULL;
		opcode = NULL;
	}
	return (0);
}
