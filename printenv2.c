/**
 *  print_env - print the env
 *
 */


#include "main.h"

int print_env(void)
{
	int i;

	if (!environ)
		return (-1);

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	return(0);
}
