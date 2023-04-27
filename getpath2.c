#include <stdio.h>

/**
 * main - Entry point for the program
 *
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 * @envp: An array of strings containing the environment variables
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char **argv, char **envp)
{
	for (char **env = envp; *env != 0; env++)
	{
	char *thisEnv = *env;

	printf("%s\n", thisEnv);

	}
	return (0);
}
