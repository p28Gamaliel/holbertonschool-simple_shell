#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints what the user is going to enter
 * Return: return -1
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("Dura-Shell:");
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			printf("\nChaito baby\n");
			break;
		}
		printf("%s", line);
	}

	free(line);
	return (0);
}
