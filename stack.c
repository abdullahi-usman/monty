#include <stdlib.h>
#include <stdio.h>
#include "monty.h"


/**
 * push - push number into the stack
 * @stack: the stack
 * @n: the number
 * Return: top of the stack
*/
stack_t *push(stack_t **stack, int n)
{
	stack_t *new_stack = NULL;

	if (*stack == NULL)
	{
		new_stack = (stack_t *)malloc(sizeof(stack_t));
		if (new_stack == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new_stack->n = n;
		*stack = new_stack;
		return (new_stack);
	}

	if ((*stack)->next == NULL)
	{
		new_stack = (stack_t *)malloc(sizeof(stack_t));
		if (new_stack == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new_stack->n = n;

		(*stack)->next = new_stack;
		new_stack->prev = (*stack);
		(*stack) = new_stack;

		return (*stack);
	}

	return (push(&(*stack)->next, n));
}

/**
 * pop - remove the last stack
 * @stack: current head
 * Return: the removed tail or head
*/
stack_t *pop(stack_t **stack)
{
	stack_t *ret_stack = NULL;

	if (*stack == NULL)
	{
		return (*stack);
	}

	ret_stack = *stack;

	if ((*stack)->prev != NULL)
	{
		*stack = (*stack)->prev;
	}
	else
	{
		*stack = NULL;
	}

	ret_stack->next = NULL;
	ret_stack->prev = NULL;

	return (ret_stack);
}

/**
 * print_all - print all values
 * @stack: the stack
 * @rev: the rev
 * Return: Void
*/
void print_all(stack_t *stack, int rev)
{
	if (stack != NULL)
	{
		printf("%d\n", stack->n);
	}
	else
	{
		return;
	}

	if (rev != -1)
	{
		print_all(stack->next, rev);
	} else
	{
		print_all(stack->prev, rev);
	}

}