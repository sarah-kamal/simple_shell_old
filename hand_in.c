#include "main.h"

char *create_buff()
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
	{
		free(buffer);
		exit(90);
	}
	return (buffer);
}

void sighandler(int signum)
{
	signal(SIGINT, sighandler);
	printf("Stopped: %d\n", signum);
}

char * customstrtok(char * str, char del)
{
        char *token;
        static char *nexttoken;
        if (str != NULL)
        {
                nexttoken = str;
        }
        else if (nexttoken == NULL)
        {
                return (NULL);
        }
        while (*nexttoken && *nexttoken == del)
                nexttoken++;
        token = nexttoken;
        while (*nexttoken && *nexttoken != del)
                nexttoken++;
        if (*nexttoken)
        {
                *nexttoken ='\0';
                nexttoken++;
        }
        else
        {
                nexttoken = NULL;
        }
        /*printf("token %s\n", token);
        fflush(stdout);*/
        return (token);
}
void putword(char *word)
{
	int i;
	for (i = 0; word[i] != '\0'; i++);
	if (write(STDOUT_FILENO, word, i) == -1)
		exit(90);
	fflush(stdout);
}
