#include "monty.h"

int main(int argc, char **argv)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char line[1024], *op_code, *n;
	FILE *file;
	int line_number = 0;
	stack_t *stack = NULL;
	char *delimiter = " \t\n";

	if (argc != 2)
		return (usage_error());

	file = fopen(argv[1], "r");
	if (file == NULL)
		return (f_open_error(argv[1]));

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		op_code = strtok(line, delimiter);

		if (unknown_op_error(op_code, line_number) != 0)
			exit(EXIT_FAILURE);

		if (strcmp(op_code, "push") == 0)
		{
			n = strtok(NULL, delimiter);
			if (n == NULL || is_numeric(n) != 0)
			{
				int_error(line_number);
				exit(EXIT_FAILURE);
			}
		}
		f = get_func(op_code);
		if (f != NULL)
		{
			f(&stack, line_number);
		}
	}
	fclose(file);
	return (0);
}
