#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point for the Monty interpreter program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
	(void)argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
