#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - Print the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in Monty byte code file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
