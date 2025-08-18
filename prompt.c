#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints what the user is going to enter
 * @line: where we will store the chain
 * @len: how much space has been reserved
 * @nread: where what getline reserves will be stored
 * Return: return -1
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("$");
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			printf("\nChao\n");
			break;
		}
		printf("%s", line);
	}

	free(line);
	return (0);
}
