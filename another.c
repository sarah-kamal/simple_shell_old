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
 * custom_getline - Reads a line from input stream
 * @line: Pointer to the line buffer
 * @max_len: Maximum length of the line buffer
 * @stream: Input stream to read from
 *
 * Return: Number of characters read, or -1 on failure
 */
ssize_t custom_getline(char **line, size_t max_len, FILE *stream)
{
	size_t i;
	int c;
	char *new_line;
    if (line == NULL || max_len == 0 || stream == NULL)
        return -1;
    *line = malloc(max_len);
    if (*line == NULL)
        return -1;

    while ((c = fgetc(stream)) != EOF && c != '\n') {
        (*line)[i++] = (char)c;

        if (i == max_len - 1) {
            max_len *= 2;
            new_line = realloc(*line, max_len);
            if (new_line == NULL) {
                free(*line);
                return -1;
            }
            *line = new_line;
        }
    }

    (*line)[i] = '\0';

    return (i);
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
