#include "shell.h"

/**
 * find_in_path - searches command in PATH
 * @command: name of the command
 * @envp: manually search for the path
 * Return: string with the full route (malloc), or NULL if it doesnt exist
 */

char *find_in_path(char *command, char **envp)
{
	char *path;

	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
		{
			char *cpy = malloc(strlen(command) + 1);

			if (!cpy)
				return (NULL);
			strcpy(cpy, command);
			return (cpy);
		}
		return (NULL);
	}

	path = get_path_env(envp);
	if (!path)
		return (NULL);
	return (search_command_in_path(path, command));
}

/**
 * get_path_env - Retrieves the PATH environment variable from envp
 * @envp: Array of environment variables
 *
 * Return: Pointer to the PATH string (excluding "PATH="), or NULL if not found
 */

char *get_path_env(char **envp)
{
	int i = 0;
	char *path = NULL;

	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break;
		}
		i++;
	}
	return (NULL);
}

/**
 * search_command_in_path - Searches the path
 * @path: The PATH string containing colon-separated directories
 * @command: The command to search for
 *
 * Return: Pointer to the full path (malloc'd) if found, or NULL
 */

char *search_command_in_path(char *path, char *command)
{
	char *dob, *dir, *full_path;
	int len;

	dob = malloc(strlen(path) + 1);
	if (!dob)
		return (NULL);
	strcpy(dob, path);

	dir = strtok(dob, ":");
	while (dir)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(dob);
			return (NULL);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			free(dob);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(dob);
	return (NULL);
}

/**
 * execute_command - executes command with fork+execve
 * @envp: manually search for the path
 * @argv: arguments ended in NULL
 */
void execute_command(char **argv, char **envp)
{
	pid_t child_pid;
	int status;
	char *cmd_path;

	cmd_path = find_in_path(argv[0], envp);
	if (!cmd_path)
	{
		fprintf(stderr, "Dura-Shell: command not found: %s\n", argv[0]);
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return;
	}
	if (child_pid == 0)
	{
		if (execve(cmd_path, argv, NULL) == -1)
			perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		free(cmd_path);
	}
}
