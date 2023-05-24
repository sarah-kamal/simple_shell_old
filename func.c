#include"shell.h"

/**
 * stringcopy - Copies a string from source to destination
 * @dest: Pointer to the destination string
 * @src: Pointer to the source string
 *
 * Return: void
 */
void stringcopy(char* dest, const char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
/**
 * stringcat - Concatenates two strings
 * @dest: Pointer to the destination string
 * @src: Pointer to the source string
 *
 * Return: void
 */
void stringcat(char *dest, const char *src)
{
	int dest_len = 0;
	int i = 0;

	while (dest[dest_len] != '\0')
		dest_len++;

	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	dest[dest_len + i] = '\0';
}
/**
 * stringToNum - Converts a string to a numerical value
 * @str: Pointer to the string
 *
 * Return: The numerical value of the string, or 0 if conversion fails
 */
int stringToNum(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	if (!str)
		return (-1);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			return (-1);
		}
	}
	return (result * sign);
}
/**
 * exitcode - Determines the exit code based on a character array and a code string
 * @arr: Pointer to the character array
 * @code: Pointer to the code string
 *
 * Return:
 *     - The exit code as an integer:
 *         - 0 if the code string is found within the character array
 *         - 1 if the code string is not found within the character array
 */
int exitcode(char *arr, char *code)
{
	if (stringcompare(arr, "exit") == 0)
	{
		if (code)
		{
			if (stringToNum(code) != -1)
			{
				exit(stringToNum(code));
			}
			else
			{
				perror(code);
			}
		}
		else
		{
			exit(0);
		}
		return (1);
	}
	return (0);
}
/**
 * stringcompare - Compares two strings
 * @str1: Pointer to the first string
 * @str2: Pointer to the second string
 *
 * Return:
 *    - Negative value if str1 is less than str2
 *    - Zero if str1 is equal to str2
 *    - Positive value if str1 is greater than str2
 */
int stringcompare(const char *str1, const char *str2)
{
	int i = 0;
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
			 return 0;
		i++;
	}
	return str1[i] - str2[i];
}
