#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/**
 * main - super simple shell
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("Dura-Shell:");
		if (getline(&line, &len, stdin) == -1 || exit)
		{
			printf("\n\nChaito Baby\n\n");
			break;
		}
		line[strcspn(line, "\n")] = 0;
		if (line[0] == '\0')
			continue;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			continue;
		}
		if (child_pid == 0)
		{
			char *argv[] = {line, NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("execve");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	free(line);
	return (0);
}
