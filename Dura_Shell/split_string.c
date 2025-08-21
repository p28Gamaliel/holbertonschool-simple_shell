#include "shell.h"

/**
 * split_string - separa una línea en tokens
 * @str: línea original
 * Return: array de tokens terminados en NULL
 */

char **split_string(char *str)
{
	char *token;
	int i = 0;
	char **tokens = malloc(100 * sizeof(char *));
	char *ignore = " \t\n,";

	if (!tokens)
	{
		perror("malloc failed");
		exit(1);
	}
	token = strtok(str, ignore);
	while (token)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, ignore);
	}
	tokens[i] = NULL;
	return (tokens);
}
