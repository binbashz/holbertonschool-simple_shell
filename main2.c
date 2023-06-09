/**
 * execute_external_command - Executes a command not built into the shell.
 * @argv: an array of arguments passed to the function
 * This function creates a child process and attempts to execute the command
 * specified in the argv array. If successful, the child process will run the
 * command and then terminate. The parent process will wait for the child to
 * complete execution before terminating.
 * Return: 0 on success, -1 on failure.
 */

#include "main.h"

int execute_external_command(char **argv)
{
	pid_t pid;
	int status = 0, i = 0;
	char *envp[] = { NULL };

	pid = fork(); /* crea un proceso hijo */

	if (pid == 0) /* si pid == 0, este es el proceso hijo */
	{
		/* This is the child process */
		execve(argv[0], argv, envp); /* ejecuta el comando */
		perror("execve error");
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
		exit(EXIT_FAILURE); /* termina el proceso hijo */
	}
	else if (pid < 0) /* i pid <0, el fork fallor */
	{
		/* The fork failed */
		perror("fork error");
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
		return (-1);
	}
	else /* si pid > 0, este es el proceso padre */
	{
		/* This is the parent process */
		waitpid(pid, &status, 0); /* espera a que el proceso hijo termine */
	}
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
 **/

int main(int argc, char **argv)                 /* main */
{
	char *prompt_message = "(my_sh) c:\\>>$ "; /* mensaje para el prompt */
	char *lineptr = NULL; /* puntero a la linea ingresada por el usuario */
	char *lineptr_duplicate = NULL; /* copia de lineptr */
	size_t n = 0; /* tamano de la linea ingresada */
	ssize_t inputLength = 0; /* longitud de la linea igresada */
	const char *delim = " \t\r\n\a"; /* delimitadores para el tokenizador */
	int number_tokens = 0; /* numero total de tokens en la linea */
	char *token = NULL; /* puntero a cada token */
	int i, s = 0;  /* contador para bucle */

	/* declaring void variables */
	(void)argc;

	while (1)
	{
		argv = NULL; /* se agrego, para evitar la doble liberacion de memoria */

		printf("%s", prompt_message);
		inputLength = getline(&lineptr, &n, stdin);

		if (inputLength == -1) /* si getline falla, o EOF salimos del programa*/
		{
			free(lineptr);
			return (-1);
		}

		/* allocate space for a copy of the lineptr */
		lineptr_duplicate = malloc(sizeof(char) * (size_t)inputLength + 1);
		if (lineptr_duplicate == NULL)
		{
			perror("memory allocation error");
			free(lineptr);
			return (-1);
		}

		/* copy lineptr to lineptr_duplicate */
		_strcpy(lineptr_duplicate, lineptr);

		/********** split the string (lineptr) into an array of words ********/
		/* calculate the total number of tokens */
		token = strtok(lineptr, delim); /* se separa la cadena ,util el delim */

		while (token != NULL) /* se cuentan la cantidad de palabras */
		{
			number_tokens++;
			token = strtok(NULL, delim);
		}
		number_tokens++;
		/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) * number_tokens);
		if (argv == NULL)
		{
			free(lineptr);
			free(lineptr_duplicate);
			perror("oops, memory allocation error");
			return (-1);
		}
		/* Store each token in the array argv  */
		token = strtok(lineptr_duplicate, delim);
		s = _strlen(token);
		for (i = 0; token != NULL; i++) /* se almacena cada palabra en array argv*/
		{
			argv[i] = malloc(sizeof(char) * (s + 1));
			if (argv[i] == NULL)
			{
				free(lineptr);
				free(lineptr_duplicate);
				free(argv);
				perror("memory allocation error");
				return (-1);
			}
			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		/* Determine if the command is internal or external */

		if (_strcmp(argv[0], "ls") == 0)
		{
			argv[0] = "/bin/ls";
			execute_external_command(argv);
		}
		/* print the path */
		else if (_strcmp(argv[0], "env") == 0)
		{
			print_env();
		}
		else if (_strcmp(argv[0], "exit") == 0)
		{
			free(lineptr);
			free(token);
			free(lineptr_duplicate);
			for (; i > 0; i--)
				free(argv[i]);
			free(argv);
			break;
		}
		else
		{
			execute_external_command(argv);
		}
		for (; i > 0; i--)
			free(argv[i]);
		free(argv);
		free(token);
	}
	return (0);
}
