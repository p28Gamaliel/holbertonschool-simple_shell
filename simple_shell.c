#include "shell.h"

/**
 * main - simple shell
 * Return: 0
 */

int main(int argc, char **argv, char **envp)
{
	char *line;
	(void)argc;

	while (1)
	{
		printf("Dura-Shell:$ ");
		line = read_line();
		if (!line)
		{
			printf("\n\nNos vemos miamol\n\n");
			break;
		}
		if (is_exit(line))
		{
			free(line);
			break;
		}
		argv = split_string(line);
		if (argv[0])
			execute_command(argv, envp);
		free(argv);
		free(line);
	}
	return (0);
}
