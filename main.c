#include "shell.h"

extern char **environ;
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int command, id, j, i, numofargs, e, linecount;
	char *words, *buffer, binloc[6];
	char *arr[10000];
	char temp[1000];
	for (j = 0; j < 10000; j++)
		arr[j] = NULL;
	if (argc > 1)
		return (1);
	linecount = 0;
	numofargs = 0;
	words = NULL;
	signal(SIGINT, SIG_DFL);
	numofargs = 0;
	stringcopy(binloc, "/bin/");
	while (1)
	{
		linecount++;
		while (numofargs != 0)
		{
			arr[numofargs] = NULL;
			numofargs--;
		}
		putword("#cisfun$");
		buffer = create_buff();
		command = read(STDIN_FILENO, buffer, 1024);
		if (command == -1)
		{
			putword("Failure to read");
			exit(91);
		}
		else if (command == 0)
		{
			/*putword("\n");*/
			return (1);
		}
		for (i = 0; buffer[i] != '\n'; i++)
		;
		buffer[i] = '\0';
		words = customstrtok(buffer, ' ');
		while (words)
		{
			arr[numofargs] = create_buff();
			stringcopy(arr[numofargs], words);
			numofargs++;
			words = customstrtok(NULL, ' ');
		}
		exitcode(arr[0], arr[1]);
		stringcopy(temp, arr[0]);
		if (temp[0] != '/' && temp[0] != '.')
		{
			stringcopy(arr[0], binloc);
			stringcat(arr[0], temp);
			stringcat(arr[0], "\0");
		}
		if (printenv(arr[0]))
			continue;
		if (!(access(arr[0], R_OK) == 0))
		{
			handle_error(argv[0], linecount, 0);
			continue;
		}
		id = fork();
		if (id == -1)
			exit(80);
		if (id == 0)
		{
			e = execve(arr[0], arr, environ);
			if (e == -1)
			{
				handle_error(argv[0], linecount, 0);
			}
		}
		else
		{
			 wait(NULL);
			/* putword("\n");*/
			 free(buffer);
			 continue;
		}
		
	}
	return (0);
}
