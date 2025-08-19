#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("My Parent PID is: %ld\n", (long)getppid());
	return (0);
}
