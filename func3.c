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
		mod_error(line_number);
	}
	if ((*stack)->n == 0)
	{
		zero_error(line_number);
	}
	current = *stack;

	*stack = (*stack)->next;
	mod = (*stack)->n % current->n;
	(*stack)->n = mod;
	free(current);
}

