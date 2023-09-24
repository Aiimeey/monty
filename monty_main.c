#include "monty.h"
/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: 0 on successful execution or an exit code on failure
 */
char *n;
int main(int argc, char **argv)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char line[1024], *op_code, *delimiter = " \t\n";
	FILE *file;
	int line_number = 0, mode = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		return (usage_error());
	file = fopen(argv[1], "r");
	if (file == NULL)
		return (f_open_error(argv[1]));

	while (fgets(line, sizeof(line), file) != NULL)
	{ line_number++;
		op_code = strtok(line, delimiter);

		if (op_code[0] == '#')
			continue;

		if (strcmp(op_code, "stack") == 0 || strcmp(op_code, "queue") == 0)
		{
			mode = switch_mode(op_code);
			continue;
		}

		op_code = opcode_check(op_code);

		if (unknown_op_error(&stack, op_code, line_number) != 0)
			exit(EXIT_FAILURE);

	op_code = push_check(op_code, &stack, mode, line_number);

		f = get_func(op_code);
		if (f != NULL)
			f(&stack, line_number);
	}
	if (stack)
		free_stack(&stack);
	fclose(file);
	return (0); }
