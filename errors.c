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
 * int_error - Prints an error message for a push without an integer
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program.
 */
int int_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * malloc_error - Prints an error message for a malloc failure
 * @stack: A pointer to the top of the stack
 * Return: exit the program.
 */
int malloc_error(stack_t **stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * pint_error - Prints an error message for pint with an empty stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int pint_error(int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
