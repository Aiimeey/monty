#include "monty.h"
/**
 * is_numeric - Checks if a string consists of numeric characters
 * @str: The string to be checked
 *
 * Return: 0 if the string contains only numeric characters
 *         EXIT_FAILURE if it contains non-numeric characters
 */
int is_numeric(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[0] == '-')
			continue;

		if (!isdigit(str[i]))
		{
			return (EXIT_FAILURE);
		}
	}
	return (0);
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
/**
 * pop_error - Prints an error message for pop with an empty stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int pop_error(int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}
