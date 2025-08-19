#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * split_string - split
 * @strtok: split a string
 * @strdup: duplicate the string
 * Return: the tokens
 */

char **split_string(char *str)
{
	char *token;
	int i = 0;

	char **tokens = malloc(100 * sizeof(char *));
	if (tokens == NULL)
	{
		perror("malloc failed");
		exit(1);
	}

	token = strtok(str, " ");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	tokens[i] = NULL;

	return (tokens);
}

int main(void)
{
	char str[] = "A separar cadena";
	char **lyrics = split_string(str);

	for (int i = 0; lyrics[i] != NULL; i++)
	{
		printf("%s\n", lyrics[i]);
	}
	free(lyrics);
	return (0);
}
