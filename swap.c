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
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack) = temp->next;
	temp->prev = (*stack);
	temp->next = (*stack)->next;

	if ((*stack)->next != NULL)
		(*stack)->next->prev = temp;

	(*stack)->prev = NULL;
	(*stack)->next = temp;
	temp->prev = NULL;
}
