#include "main.h"

char *create_buff()
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		exit(90);
	return (buffer);
}

void sighandler(int signum)
{
	printf("Stopped: %d\n", signum);
}
