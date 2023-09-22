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
			&& strcmp(op_code, "pop") != 0
			&& strcmp(op_code, "swap") != 0
			&& strcmp(op_code, "add") != 0
			&& strcmp(op_code, "nop") != 0
			&& strcmp(op_code, "sub") != 0
			&& strcmp(op_code, "mul") != 0
			&& strcmp(op_code, "div") != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_code);
		exit(EXIT_FAILURE);
	}
	return (0);
}


