#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int execute_external_command(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		/* This is the child process */
		execvp(argv[0], argv);
		perror("execvp error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* The fork failed */
		perror("fork error");
		return (-1);
	}
	else
	{
		/* This is the parent process */
		waitpid(pid, &status, 0);
	}
	return (0);
	}

int execute_internal_command(char **argv)
{
	/* Handle the internal command here */

	return (0);
}

int main(int argc, char **argv)                 /* main */
{
	char *prompt_message = "(my_sh) c:\\>>$ ";
	char *lineptr = NULL;
	char *lineptr_duplicate = NULL;
	size_t n = 0;
	size_t inputLength;
	const char *delim = "\n";
	int number_tokens = 0;
	char *token;
	int i;

	/* declaring void variables */
	(void)argc;

	while (1)
	{
		printf("%s", prompt_message);
		inputLength = getline(&lineptr, &n, stdin);

		if (inputLength == -1)
		{
			printf("Exit shell\n");
			return (-1);
		}

		/* allocate space for a copy of the lineptr */
		lineptr_duplicate = malloc(sizeof(char) * inputLength);
		if (lineptr_duplicate == NULL)
		{
			perror("memory allocation error");
			return (-1);
		}

		/* copy lineptr to lineptr_duplicate */
		_strcpy(lineptr_duplicate, lineptr);

		/********** split the string (lineptr) into an array of words ********/
		/* calculate the total number of tokens */
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			number_tokens++;
			token = strtok(NULL, delim);
		}
		number_tokens++;

		/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) * number_tokens);

		/* Store each token in the array argv  */
		token = strtok(lineptr_duplicate, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		/* Determine if the command is internal or external */


		if (_strcmp(argv[0], "cd") == 0)
		{
			execute_internal_command(argv);
		}

		else
		{
			execute_external_command(argv);
		}

		printf("%s\n", lineptr);

		free(lineptr);
	}

	return (0);
}
