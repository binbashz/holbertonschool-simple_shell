#include "main.h"

/**
 * main - entry point
 * argv argument stdin path
 *
 * Return: 1 ... -1
 */

	int main(void)
	{
		char *argv[] = {"/bin/ls", "-l", NULL};

		int checkValuReturn = execve(argv[0], argv, NULL);

		if (val == -1)
		{
			perror("Error sgmf!!")

		}

		return (0);
	}
