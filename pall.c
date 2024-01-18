#include "monty.h"

/**
 * pall - Prints all values in the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the monty file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
