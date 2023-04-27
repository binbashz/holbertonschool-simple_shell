#include <stdio.h>
#include "main.h"
/**
 * _getpath - Entry point for the program
 *
 * @envp: An array of strings containing the environment variables
 *
 * Return: 0 on success, 1 on failure
 */

int _getpath(char **envp)
{
	char **env;

	for (env = envp; *env != 0; env++)
	{
	char *thisEnv = *env;

	printf("%s\n", thisEnv);

	}
	return (0);
}
