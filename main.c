#include "shell.h"

extern char **environ;
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int command, id, j, numofargs, e, linecount;
	size_t len;
	char *words, binloc[6];
	char *buffer;
	char *arr[10000];
	char temp[1000];
	for (j = 0; j < 10000; j++)
		arr[j] = NULL;
	if (argc > 1)
		return (1);
	linecount = 0;
	(void)len;
	len = 1024;
	numofargs = 0;
	words = NULL;
	signal(SIGINT, SIG_DFL);
	numofargs = 0;
	stringcopy(binloc, "/bin/");
	while (1)
	{
		linecount++;
		while (numofargs)
		{
			free(arr[--numofargs]);
			arr[numofargs] = NULL;
		}
		putword("#cisfun$");
		if (!create_buff(&buffer))
		{
			exit(0);
		}
		command = custom_getline(&buffer, &len, stdin);
		if (command == -1)
		{
			putword("Failure to read");
			free(buffer);
			buffer = NULL;
			exit(0);
		}
		else if (command == 0)
		{
			free(buffer);
			buffer = NULL;
			/*putword("\n");*/
			return 0;
			continue;
		}
		words = customstrtok(buffer, ' ');
		if (stringcompare(words,"\0") == 0|| stringcompare(words, "") == 0)
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		while (words)
		{
			if (!create_buff(&(arr[numofargs])))
			{
				exit(0);
			}
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
		{
			free(buffer);
			continue;
		}
		if (!(access(arr[0], R_OK) == 0))
		{
			handle_error(argv[0], linecount, 0);
			free(buffer);
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
				free(buffer);
				return (0);
			}
			free(buffer);
			return (0);
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
