#include "main.h"

extern char **environ;

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main()
{
	int command, id;
	char *buffer;
	char *cmd;
	char **arg;
	signal(SIGTSTP, sighandler);
	while (1)
	{
		if (write(STDOUT_FILENO, "$", 1) == -1)
		{
			printf("Failure to write\n");
			exit(90);
		}
		buffer = create_buff();
		command = read(STDIN_FILENO, buffer, 1024);
		if (command == -1)
		{
			
			printf("Failure to read\n");
			exit(91);
		}
		printf("\n");
		cmd = buffer;
		*arg = buffer;

		id = fork();

		if (id == -1)
			exit(80);

		if (id == 0)
		{
			int e;
			e = execve(cmd, arg, environ);
			if (e == -1)
				perror("./shell");
		}
		else
		{
			wait(NULL);
			printf("\n");
			continue;
		}
		
	}

	return (0);
}
