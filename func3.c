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
/**
 * pstr - Print characters from the stack until a non-printable
 * @stack: A pointer to the stack data structure
 * @line_number: The line number where the pstr operation is called (unused)
 * Return : void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;
	if (!*stack)
	{
		putchar('\n');
		return;
	}

	current = *stack;
	while (current && current->n != 0 &&
			((current->n >= 65 && current->n <= 90)
			 || (current->n >= 97 && current->n <= 122)))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar ('\n');

}
