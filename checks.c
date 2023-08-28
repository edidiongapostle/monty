#include "monty.h"

/**
 * check_argc - check the number of argument passed to the interpreter
 * @argc: the argument count
 */

void check_argc(int argc)
{
	if (argc != MIN_ARGS)
		handle_errors(ERR_ARG_USG, NULL, 0, NULL);
}

/**
 * check_access_rights - Check if the user has permission to read the file
 * @filename: the filename to be checked
 */

void check_access_rights(char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_push_paline - Check the palineeter of the push instructon
 * @paline: The palineeter to be checked
 *
 * Return: 0 if the it is valid or errcode if otherwise
 */

int check_push_paline(char *paline)
{
	if (paline == NULL || check_digits(paline) == 0)
		return (ERR_PUSH_USG);
	return (VALID_paline);
}

/**
 * check_digits - check if all character in as string are digits
 * @s: the string to be checked
 *
 * Return: 1 if all evaluated characters are digits or 0 if not
 */

int check_digits(char *s)
{
	int status = 1;

	while (*s)
	{
		if (s[0] == 45)
		{
			++s;
			continue;
		}
		if (isdigit(*s) == 0)
		{
			status = 0;
			return (status);
		}
		++s;
	}
	return (status);
}
