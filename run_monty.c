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
