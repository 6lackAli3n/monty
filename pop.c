#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - Remove the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in Monty byte code file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
