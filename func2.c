#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int x;
	stack_t *current = (*stack)->next;

	if (!*stack || !(*stack)->next)

	{
		swap_error(line_number);
	}

	x = (*stack)->n;
	(*stack)->n = current->n;
	current->n = x;
}
