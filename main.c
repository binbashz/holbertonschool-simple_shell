#include "main.h"

/**
 * execute_external_command - Executes a command not built into the shell.
 * @argv: an array of arguments passed to the function
 * This function creates a child process and attempts to execute the command
 * specified in the argv array. If successful, the child process will run the
 * command and then terminate. The parent process will wait for the child to
 * complete execution before terminating.
 * Return: 0 on success, -1 on failure.
 */

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
		/* free(argv);    */
	}
	return (0);
}


/**
 * execute_internal_command - Executes a command built into the shell.
 * @argv: an array of arguments passed to the function
 * This function handles internal shell commands such as "cd" or "exit".
 * Return: 0 on success.
 */

int execute_internal_command(char **argv)
{
	/* Handle the internal command here */

	return (0);
}

/**
 * main - Entry point for the shell program.
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments
 * This function contains the main loop for the shell program. It prints a
 * prompt message, reads input from the user, and determines whether the
 * command entered is an internal or external command. Internal commands are
 * executed by calling the execute_internal_command function, and external
 * commands are executed by calling the execute_external_command function.
 * Return: 0 on success.
 */

int main(int argc, char **argv)                 /* main */
{
	char *prompt_message = "(my_sh) c:\\>>$ ";
	char *lineptr = NULL;
	char *lineptr_duplicate = NULL;
	size_t n = 0;
	ssize_t inputLength;
	const char *delim = " \t\r\n\a";
	int number_tokens = 0;
	char *token;
	int i, j = 0;

	/* declaring void variables */
	(void)argc;

	while (1)
	{
		argv = NULL; /* se agrego, para evitar la doble liberacion de memoria */

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
			free(lineptr_duplicate);
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
		if (argv == NULL)
		{
			free(lineptr_duplicate);
			perror("oops, memory allocation error");
				return (-1);
		}
		/* Store each token in the array argv  */
		token = strtok(lineptr_duplicate, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * (_strlen(token) + 1)); /* add +1*/
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;


	/* Determine if the command is internal or external */
	if (_strcmp(argv[0], "cd") == 0)
	{
	execute_internal_command(argv);
	}
	else if (_strcmp(argv[0], "ls") == 0)
	{
	argv[0] = "/bin/ls"; /* specify the command path to execute */
	execute_external_command(argv);
	}
	else
	{
	execute_external_command(argv);
	}
		printf("%s\n", lineptr);

		free(lineptr);
		j = 0;

		while (argv[j] != NULL)

		{
			free(argv[j]);
			j++;
		}
		free(argv);
	}
/*	free(argv); */

	return (0);
}
