/**
 *  print_path - print the env
 *   when you call them
 *  iniciar - inica e es
 */



#include "main.h"

extern char **environ;

void print_path(void)
{
	char **env = environ;

	while (*env != NULL)

	{
	if (_strncmp(*env, "PATH=", 5) == 0)
	{
	printf("%s\n", *env + 5);
	break;

	}
	env++;
	}
}

int iniciar(void)
{
	print_path();
	return (0);
}
