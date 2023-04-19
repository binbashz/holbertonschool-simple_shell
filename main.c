#include "main.h"

int main(int arc, char **argv)
{
	char *user_imput = "(my_sh) c:\\>>$ ";  /* prompt */
	char *lineptr = NULL; /* to sotre buffer direction, contains what is written.[getline function]*/
	char *lineptr_duplicate = NULL; /* variable to contain the copy of the string to be passe to strtok. */
	size_t n = 0; /* size_t store the assigned size in bytes;  [getline function] */
	size_t readCharacterCount; /* variable for EOF */
	const char *delimiters = "\n";
	/* declaring void variables */
	(void)arc;
	(void)argv;

	while (1)/* infite loop, for a prompt */
	{
	printf("%s", user_imput);
	readCharacterCount = getline(&lineptr, &n, stdin); /* [getline function]  stdin = stream; */
						/* represents the source from which we want the function to get the data from. */
	/* Ensure that the getline function didn't encounter any errors, reached the end of file, or if the user used CTRL + D*/
	if (readCharacterCount == -1)
	{
	printf("Exit shell\n");
	return (-1);
	}
	printf("%s\n", lineptr); /* printing what was written or saved in *lineptr.  */

	free(lineptr); /* [getline] allocates memory, must be freed */
	}
	return (0);
}
