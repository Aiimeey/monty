#include "monty.h"
/**
 * mul_error - Prints an error message for a mul op with an insufficient stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int mul_error(int line_number)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * div_error - Prints an error message for a div op with an insufficient stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int div_error(int line_number)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * mod_error - Prints an error message for a mod op with an insufficient stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int mod_error(int line_number)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * zero_error - Prints a message for the division by zero error
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int zero_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}
