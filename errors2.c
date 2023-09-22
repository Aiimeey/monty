#include "monty.h"

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

/**
 * swap_error - Prints an error message for a swap with an insufficient stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int swap_error(int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * add_error - Prints an error message for an add op with an insufficient stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int add_error(int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
