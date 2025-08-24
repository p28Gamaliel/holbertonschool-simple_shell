#include "shell.h"

/**
 * split_string - separates a string into tokens
 * @str: original string
 * Return: array of tokens finished in NULL
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
