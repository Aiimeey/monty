#include "monty.h"

int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

int f_open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

int unknown_op_error(char *op_code, int line_number)
{
	if (strcmp(op_code, "push") != 0
			&& strcmp(op_code, "pall") != 0
			&& strcmp(op_code, "pint") != 0
			&& strcmp(op_code, "nop") != 0
			&& strcmp(op_code, "pop") != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_code);
		exit(EXIT_FAILURE);
	}
	return (0);
}
int int_error(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

int no_int_error(int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

int pint_error(int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

int pop_error(int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

