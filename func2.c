#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int x;
	stack_t *current;

	if (!*stack || !(*stack)->next)
	{
		swap_error(line_number);
	}

	current = (*stack)->next;

	x = (*stack)->n;
	(*stack)->n = current->n;
	current->n = x;
}
/**
 * add - Adds the top two elements of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *current;

	if (!*stack || !(*stack)->next)
	{
		add_error(line_number);
	}

	current = *stack;

	*stack = (*stack)->next;
	sum = current->n + (*stack)->n;
	(*stack)->n = sum;
	free(current);
}

/**
 * sub - substract the top two elements of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int sub;
	stack_t *current;

	if (!*stack || !(*stack)->next)
	{
		sub_error(line_number);
	}
	current = *stack;

	*stack = (*stack)->next;
	sub = (*stack)->n - current->n;
	(*stack)->n = sub;
	free(current);
}

