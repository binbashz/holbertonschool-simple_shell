
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
	int status;
	char *envp[] = { NULL };

	pid = fork(); /* crea un proceso hijo */

	if (pid == 0) /* si pid == 0, este es el proceso hijo */
	{
	/* This is the child process */
	execve(argv[0], argv, envp); /* ejecuta el comando */
	perror("execve error");
	exit(EXIT_FAILURE); /* termina el proceso hijo */
	}
	else if (pid < 0) /* i pid <0, el fork fallor */
	{
	/* The fork failed */
	perror("fork error");
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
 *  execute_internal_command - Executes a command built into the shell.
 *  @argv: an array of arguments passed to the function
 * This function handles internal shell commands such as "cd" or "exit".
 * Return: 0 on success.
 *
 **/


int execute_internal_command(char **argv)
{
	(void)argv; /* evita la advertencia de paramero sin usar */
	/* Handle the internal command here */
	/* maneja el comando interno aqui */

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
	ssize_t inputLength; /* longitud de la linea igresada */
	const char *delim = " \t\r\n\a"; /* delimitadores para el tokenizador */
	int number_tokens = 0; /* numero total de tokens en la linea */
	char *token; /* puntero a cada token */
	int i;  /* contador para bucle */

	/* declaring void variables */
	(void)argc;

	while (1)
	{
		argv = NULL; /* se agrego, para evitar la doble liberacion de memoria */

		printf("%s", prompt_message);
		inputLength = getline(&lineptr, &n, stdin);

		if (inputLength == -1) /* si getline falla, o EOF salimos del programa*/
		{
			printf("Exit shell\n");
			return (-1);
		}

		/* allocate space for a copy of the lineptr */
		lineptr_duplicate = malloc(sizeof(char) * inputLength); /* asiganamos memoria para el duplicado */
		if (lineptr_duplicate == NULL) /* si malloc falla  al asignar, liberamos al mem prev asignada y salimos del prog*/
		{
			perror("memory allocation error");
			return (-1);
		}

		/* copy lineptr to lineptr_duplicate */
		_strcpy(lineptr_duplicate, lineptr);

		/********** split the string (lineptr) into an array of words ********/
		/* calculate the total number of tokens */
		token = strtok(lineptr, delim); /* se separa la cadena en palabras ,utilizando el delimitador */

		while (token != NULL) /* se cuentan la cantidad de palabras */
		{
			number_tokens++;
			token = strtok(NULL, delim);
		}
		number_tokens++;

		/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) * number_tokens); /* se asigna memoria para un array de punteros a char */
		if (argv == NULL)/* si malloc falla al asignar mem, liberamos la prev asignada y salimos del programa */
		{
			perror("oops, memory allocation error");
				return (-1);
		}
		/* Store each token in the array argv  */
		token = strtok(lineptr_duplicate, delim); /*  se espera la cadena en palabras utilizando el delimitador especifico */

		for (i = 0; token != NULL; i++) /* se almacena cada palabra en el array argv */
		{
			argv[i] = malloc(sizeof(char) * (_strlen(token) + 1)); /* se asigna memoria para la palabra actual y se almacena en argv */
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
			argv[0] = "/bin/ls";
			execute_external_command(argv);
		}
		else if (_strcmp(argv[0], "env") == 0)
			/* Agregar un comando para mostrar el valor de la variable PATH */
		{
			printf("PATH: %s\n", getenv("PATH"));
		}
		else if (_strcmp(argv[0], "exit") == 0)
		{
			printf("Exiting the shell... \n");
			break;
		}
		else
		{
			execute_external_command(argv);
		}
		printf("%s\n", lineptr);

		free(lineptr_duplicate);
		free(argv);
	}

	return (0);
}
