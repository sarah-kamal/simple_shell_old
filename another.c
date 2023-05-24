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
 * custom_getline - Read a line from a file stream.
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Pointer to the size of the buffer.
 * @stream: File stream to read from.
 *
 * Return: Number of characters read, or -1 on failure.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t capacity = 0;
	size_t bytesRead = 0;
	int character;
	char *newLineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return -1;

	while ((character = custom_fgetc(stream)) != EOF && character != '\n')
	{
		if (bytesRead >= capacity - 1)
		{
			capacity = capacity == 0 ? 1 : capacity * 2;
			newLineptr = realloc(*lineptr, capacity);
			if (newLineptr == NULL)
				return -1;
			*lineptr = newLineptr;
			*n = capacity;
		}
		(*lineptr)[bytesRead++] = character;
	}

	if (bytesRead == 0)
		return -2;
	else if ( character == EOF)
		return -1;
	(*lineptr)[bytesRead] = '\0';

	return bytesRead;
}

int custom_fgetc(FILE *stream) {
    unsigned char character;
    ssize_t bytesRead = read(fileno(stream), &character, 1);

    if (bytesRead == 1) {
        return character;
    } else {
        return EOF;
    }
}
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
