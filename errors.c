#include "monty.h"
/**
 * usage_error - Prints a usage error message and exits with failure status
 * Return: exit the program
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * f_open_error - Prints an error message for file open failure
 * @file: The name of the file that failed to open
 * Return: exit the program
 */
int f_open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
/**
 * unknown_op_error - Prints an error message for an unknown instruction
 * @op_code: The unknown instruction.
 * @line_number: The line number in the Monty bytecode file
 * Return: Exit on failure
 */
int unknown_op_error(char *op_code, int line_number)
{
	if (strcmp(op_code, "push") != 0
			&& strcmp(op_code, "pall") != 0
			&& strcmp(op_code, "pint") != 0
			&& strcmp(op_code, "nop") != 0
			&& strcmp(op_code, "pop") != 0
			&& strcmp(op_code, "swap") != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_code);
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * int_error - Prints an error message for a push without an integer
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program.
 */
int int_error(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * malloc_error - Prints an error message for a malloc failure
 * Return: exit the program.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

