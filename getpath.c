#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void print_path()
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

int iniciar() {
	print_path();
	return (0);
}
