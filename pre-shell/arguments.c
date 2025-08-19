#include <stdio.h>

/**
 * main - prints all the arguments
 * @i: variable that is traversed through each argument
 * Return: 0
 */

int main(int ac, char **av)
{
	int i;

	(void)ac;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("Argumento %d: %s\n", i, av[i]);
	}

	return (0);
}
