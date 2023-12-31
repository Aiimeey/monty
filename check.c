#include "monty.h"
/**
 * is_numeric - Checks if a string consists of numeric characters
 * @str: The string to be checked
 *
 * Return: 0 if the string contains only numeric characters
 *         EXIT_FAILURE if it contains non-numeric characters
 */
int is_numeric(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[0] == '-')
			continue;

		if (!isdigit(str[i]))
		{
			return (EXIT_FAILURE);
		}
	}
	return (0);
}
/**
 * unknown_op_error - Prints an error message for an unknown instruction
 * @stack: A pointer to the top of the stack
 * @op_code: The unknown instruction.
 * @line_number: The line number in the Monty bytecode file
 * Return: Exit on failure
 */
int unknown_op_error(stack_t **stack, char *op_code, unsigned int line_number)
{
	if (strcmp(op_code, "push") != 0
			&& strcmp(op_code, "pall") != 0
			&& strcmp(op_code, "pint") != 0
			&& strcmp(op_code, "pop") != 0
			&& strcmp(op_code, "swap") != 0
			&& strcmp(op_code, "add") != 0
			&& strcmp(op_code, "nop") != 0
			&& strcmp(op_code, "sub") != 0
			&& strcmp(op_code, "mul") != 0
			&& strcmp(op_code, "div") != 0
			&& strcmp(op_code, "mod") != 0
			&& strcmp(op_code, "pchar") != 0
			&& strcmp(op_code, "pstr") != 0
			&& strcmp(op_code, "rotl") != 0
			&& strcmp(op_code, "rotr") != 0
			&& strcmp(op_code, "queu") != 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_code);
		if (*stack)
			free_stack(stack);
		exit(EXIT_FAILURE);
	}
	return (0);
}
/**
 * free_stack - Frees a stack and its elements.
 * @stack: A pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
/**
 * opcode_check - Check and remove leading delimiter characters
 * @op_code: The input string to be checked
 *
 * Return: A pointer to the modified string after removing leading delimiters
 */
char *opcode_check(char *op_code)
{
	char *delimiter = " \t\n";

	do {
		if (strcmp(op_code, "\n") == 0 || strcmp(op_code, "\t") == 0)
			op_code = strtok(NULL, delimiter);
		else
			break;
	} while (op_code);

	return (op_code);

}
/**
 * switch_mode - Determines the operating mode based on the input opcode
 * @op_code: A pointer to a null-terminated string containing the opcode
 * Return: The determined operating mode (0 for "stack" and 1 for "queue")
 */
int switch_mode(char *op_code)
{
	int mode;

	if (strcmp(op_code, "stack") == 0)
		mode = 0;

	if (strcmp(op_code, "queue") == 0)
		mode = 1;

	return (mode);

}
