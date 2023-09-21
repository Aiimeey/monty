#include "monty.h"

int is_numeric(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (EXIT_FAILURE);
		}
	}
	return (0);
}
