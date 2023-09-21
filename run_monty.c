#include "monty.h"

f get_func(char *op_code)
{

	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"pop", pop},
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
