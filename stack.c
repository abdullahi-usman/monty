#include <stdlib.h>
#include "stack.h"


/**
 * push - push number into the stack
 * @stack: the stack
 * @n: the number
 * Return: top of the stack
*/
stack_t *push(stack_t **stack, int n)
{
	stack_t *new_stack = NULL;

	if (stack == NULL)
	{
		*stack = new_stack;
		return (new_stack);
	}

	if ((*stack)->next == NULL)
	{
		new_stack = (stack_t *)malloc(sizeof(stack_t));
		new_stack->n = n;

		(*stack)->next = new_stack;
		new_stack->prev = (*stack);
		(*stack) = new_stack;

		return (stack);
	}

	return (push((*stack)->next, n));
}

/**
 * pop - remove the last stack
 * @stack: current head
 * Return: the removed tail or head
*/
stack_t *pop(stack_t **stack)
{
	if (stack == NULL)
	{
		return (stack);
	}

	if ((*stack)->next == NULL)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
		return (*stack);
	}

	return (pop((*stack)->next));
}
