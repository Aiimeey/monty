#include "monty.h"
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
int swap_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * add_error - Prints an error message for an add op with an insufficient stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int add_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * sub_error - Prints an error message for an sub op with an insufficient stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int sub_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * mul_error - Prints an error message for a mul op with an insufficient stack
 * @line_number: The line number in the Monty bytecode file
 * Return: exit the program
 */
int mul_error(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	if (*stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}