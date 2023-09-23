#include "monty.h"
/**
 * mod - computes the rest of the division of the top two elements of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int mod;
	stack_t *current;

	if (!*stack || !(*stack)->next)
	{
		mod_error(stack, line_number);
	}
	if ((*stack)->n == 0)
	{
		zero_error(stack, line_number);
	}
	current = *stack;

	*stack = (*stack)->next;
	mod = (*stack)->n % current->n;
	(*stack)->n = mod;
	free(current);
}

/**
 * pchar - Print the character at the top of the stack
 * @stack: A pointer to the stack data structure
 * @line_number: The line number where the pchar operation is called
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		pchar_empty_error(line_number);

	if (((*stack)->n >= 65 && (*stack)->n <= 90)
			|| ((*stack)->n >= 97 && (*stack)->n <= 122))

		printf("%c\n", (*stack)->n);
	else
	{
		pchar_range_error(stack, line_number);
	}

}
