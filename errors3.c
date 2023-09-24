#include "monty.h"


/**
 * div_error - Prints an error message for a div op with an insufficient stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int div_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * mod_error - Prints an error message for a mod op with an insufficient stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int mod_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * zero_error - Prints a message for the division by zero error
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int zero_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * pchar_empty_error - Handles the error when pchar from an empty stack
 * @line_number: The line number where the error occurred
 * Return: exit the program
 */
int pchar_empty_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}
/**
 * pchar_range_error - Handles the error when pchar a value out of range
 * @stack: A pointer to the stack data structure
 * @line_number: The line number where the error occurred
 * Return: exit the program
 */
int pchar_range_error(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);

}
