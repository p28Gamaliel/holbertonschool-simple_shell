#include "shell.h"

/**
 * read_line - reads the input from stdin
 * Return: pointer to the line (malloc), NULL if EOF
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	line[strcspn(line, "\n")] = 0;
	return (line);
}

/**
 * is_exit - checks if input is "exit"
 * @line: input
 * Return: 1 if its exit, 0 in other case
 */

int is_exit(char *line)
{
	if (line && strcmp(line, "exit") == 0)
	{
		printf("\n\nNos Vemos Miamol\n\n");
		return (1);
	}
	return (0);
}
