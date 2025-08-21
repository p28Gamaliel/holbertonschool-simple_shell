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
	char *dob = malloc(strlen(path) + 1);
	char *direc;
	char Path[1024];

	if (!NULL)
		return (0);
	if(ac < 2)
		return (1);

	strcpy(dob, path);
	direc = strtok(dob, ":");

	while (direc)
	{
		int len = strlen(direc) + strlen(av[1]) + 2;

		if (len < (int)sizeof(Path))
		{
			strcpy(Path, direc);
			strcat(Path, "/");
			strcat(Path, av[1]);

			if (access(Path, X_OK) == 0)
				printf("%s\n", Path);
		}
		direc = strtok(NULL, ":");
	}
	free(dob);
	return (0);
}
