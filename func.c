#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{

	stack_t *new = NULL;
	char *n = "1";
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_error();

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

void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!*stack)
	{
		pint_error(line_number);
	}



	printf("%d\n", (*stack)->n);

}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

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

