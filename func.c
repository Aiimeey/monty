#include "monty.h"
/**
 * push - Pushes an integer onto the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */

void push(stack_t **stack, unsigned int line_number)
{

	stack_t *new = NULL;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_error(stack);

	new->prev = NULL;
	new->n = atoi(n);
	new->next = NULL;
	if (*stack)
	{
		(*stack)->prev = new;
		new->next = (*stack);
	}

	*stack = new;

}
/**
 * pall - Prints all elements of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{

	size_t i = 0;
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
		i++;
	}
}
/**
 * pint - Prints the value at the top of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!*stack)
	{
		pint_error(line_number);
	}

	printf("%d\n", (*stack)->n);

}
/**
 * nop - Does nothing
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * pop - Removes the top element of the stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number in the Monty bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!*stack)
		pop_error(line_number);

	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(current);

}
