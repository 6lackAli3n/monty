#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit - checks if a string represents a positive integer
 * @str: pointer to the string to be checked
 *
 * Description: The is_digit function takes a string as input
 * and checks whether it represents a positive integer.
 * Return: 1 if the string is a valid positive integer and 0 otherwise.
 */
int is_digit(const char *str)
{
	if (!str)
		return (0);
	for (; *str; str++)
	{
		if (!isdigit(*str))
			return (0);
	}
	return (1);
}

/**
 * free_stack - frees all elements of a doubly linked list (stack)
 * @stack: double pointer to the head of the stack
 *
 * Description: The free_stack function takes a double pointer to the
 * head of a doubly linked list (stack) and frees all its elements,
 * effectively clearing the entire stack. It sets the head pointer to NULL
 * after freeing all nodes.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack, *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

/**
 * main - Entry point for the Monty interpreter program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %sfilename\n", argv[0]);
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		process_line(line, &stack, &line_number, file);
		line_number++;
	}
	free(line);
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * process_line - Process a line of Monty byte code
 * @line: The line of Monty byte code to be processed
 * @stack: Double pointer to the head of the stack
 * @line_number: Pointer to the current line number in the Monty byte code file
 *
 * Description: The process_line function takes a line of Monty byte code
 * and interprets the opcode to perform the corresponding operation
 * It delegates the specific operations to other functions based on the opcode.
 * This function helps modularize the code in the main function, making it more
 * readable and maintainable.
 */
void process_line(char *line, stack_t **stack, unsigned int *line_number, FILE *file)
{
	char *opcode, *argument;

	opcode = strtok(line, " \t\n");
	if (!opcode || opcode[0] == '#')
		return;

	argument = strtok(NULL, " \t\n");
	if (strcmp(opcode, "push") == 0)
	{
		if (!argument || !is_digit(argument))
		{
			fprintf(stderr, "L%u: usage: push integer\n", *line_number);
			free_stack(stack);
			fclose(file);
			free(line);
			exit(EXIT_FAILURE);
		}
			push(stack, atoi(argument));
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, *line_number);
	}
	else if (strcmp(line, "pint") == 0)
	{
		pint(stack, *line_number);
	}
	else if (strcmp(line, "pop") == 0)
	{
		pop(stack, *line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", *line_number, opcode);
		free_stack(stack);
		fclose(file);
		free(line);
		exit(EXIT_FAILURE);
	}
}
