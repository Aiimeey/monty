#include "monty.h"
/**
 * get_func - Get the function associated with a Monty opcode
 * @op_code: The Monty opcode to look up
 *
 * Return: A pointer to the function associated with the opcode
 *         or NULL if the opcode is not found
 */
f get_func(char *op_code)
{

	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", diiv},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queu", queu},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_func[i].opcode; i++)
	{
		if (strcmp(op_code, op_func[i].opcode) == 0)
		{
			return (op_func[i].f);
		}

	}
	return (NULL);
}

/**
 * queu - Pushes a new element to the end of a stack
 * @stack: A pointer to a pointer to the stack
 * @line_number: The line number in the source file (unused)
 */

void queu(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *current = NULL;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_error(stack);

	new->prev = NULL;
	new->n = atoi(n);
	new->next = NULL;

	if (!*stack)
	{
		*stack = new;
	}
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;

		current->next = new;
		new->prev = current;
	}

}
/**
 * push_check - Checks and handles the push operation for a stack or queue
 * @op_code: A pointer to a null-terminated string containing the opcode
 * @stack: A pointer to a pointer to the stack or queue structure
 * @mode: An integer indicating the operating mode (0 for stack, 1 for queue)
 * @line_number: The line number in the source file
 *
 * Return: A pointer to the modified 'op_code' string
 */
char *push_check(char *op_code, stack_t **stack, int mode, int line_number)
{
	char *delimiter = " \t\n";

	if (strcmp(op_code, "push") == 0)
	{
		if (mode == 1)
			strcpy(op_code, "queu");

		n = strtok(NULL, delimiter);

		if (n == NULL || is_numeric(n) != 0)
		{
			int_error(stack, line_number);
			exit(EXIT_FAILURE);
		}
	}

	return (op_code);
}