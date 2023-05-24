#include"shell.h"
/**
 * printEnvironment - Prints the current environment variables
 * @arr: array[0]
 * Return: void
 */
 int printenv(char *arr)
 {
	 extern char **environ;
	 char **env;

	 env = environ;
	 if (stringcompare(arr, "env") == 0)
	 {
	 	while (*env)
	 	{
			 putword(*env);
			 putword("\n");
			 env++;
		}
		return (1);
	}
	else
		return (0);
 }

/**
 * customgetline - Reads a line of text from a file stream or stdin
 * @lineptr: Pointer to the buffer that will hold the line
 * @n: Pointer to the size of the buffer
 * @stream: The file stream to read from (or stdin if NULL)
 *
 * Return:
 *    - The number of characters read (excluding newline)
 *    - -1 if an error occurs or end of file is reached
 
 ssize_t customgetline(char **buff, int n, FILE *stream)
 {
	 int counter;

	 counter = read(STDIN_FILENO, *buff, n - 1);
	 if (counter < n - 1)
	 {
		 *buff[n-1] = "\0";
	 }
 }*/

void tostring(char str[], int num)
{
    int i, rem, len, n;

    rem = 0;
    len = 0;
    i = 0;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

void handle_error(char *fname, int linecount, int n)
{
	char *linec;
	
	linec = malloc(sizeof(char) * 3);
	if (!linec)
		exit(90);
	if (n)
	{
		putword(fname);
		putword(": ");
		tostring(linec, linecount);
		perror(linec);
	}
	else
	{
		perror(fname);
	}
}
