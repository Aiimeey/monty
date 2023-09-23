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

/**
 * mul - multiplies the top two elements of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int mul;
	stack_t *current;

	if (!*stack || !(*stack)->next)
	{
		mul_error(line_number);
	}

	current = *stack;

	*stack = (*stack)->next;
	mul = (*stack)->n * current->n;
	(*stack)->n = mul;
	free(current);
}


/**
 * diiv - divides the top two elements of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */

void diiv(stack_t **stack, unsigned int line_number)
{
	int div;
	stack_t *current;

	if (!*stack || !(*stack)->next)
	{
		div_error(line_number);
	}
	if ((*stack)->n == 0)
	{
		zero_error(stack, line_number);
	}
	current = *stack;

	*stack = (*stack)->next;
	div = (*stack)->n - current->n;
	(*stack)->n = div;
	free(current);
}
