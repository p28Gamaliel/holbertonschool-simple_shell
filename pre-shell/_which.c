#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - 
 *
 */
int main(int ac, char **av)
{
	char *path = getenv("PATH");
		if (path == NULL)
			return (1);

	char *direc;
	char gran_path[1024];
	char *dob = malloc(strlen(path) + 1);
		if (dob == NULL)
			return (1);

	if(ac < 2)
		return (1);

	strcpy(dob, path);
	direc = strtok(dob, ":");

	while (direc)
	{
		int len = strlen(direc) + strlen(av[1]) + 2;

		if (len < (int)sizeof(gran_path))
		{
			strcpy(gran_path, direc);
			strcat(gran_path, "/");
			strcat(gran_path, av[1]);

			if (access(gran_path, X_OK) == 0)
			{
				printf("%s\n", gran_path);
			}
		}
		direc = strtok(NULL, ":");
	}
	free(dob);
	return (0);
}
