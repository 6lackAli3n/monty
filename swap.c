#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swap the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in Monty byte code file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
