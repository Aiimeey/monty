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
 * @stack: A pointer to the top of the stack
 * Return: exit the program.
 */
int malloc_error(stack_t **stack)
{
	fprintf(stderr, "Error: malloc failed\n");
	if (!*stack)
		free(stack);
	exit(EXIT_FAILURE);
}

/**
 * no_int_error - Prints an error message for push with a non-integer argument
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program.
 */

int no_int_error(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
