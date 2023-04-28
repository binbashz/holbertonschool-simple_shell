#include "main.h"

/**
 * _strcpy -  function that copies the string
 * @src: pointer to the strign
 * @dest: string copy destination
 * Return: dest
 **/

char *_strcpy(char *dest, char *src)
{
	int i;
	char *dest_start; /* save the star of the destination */

	for (i = 0; src[i] != '\0'; i++)  /* Copy the contents of src to dest */
	{

		dest[i] = src[i];
	}
	/*dest[i] = '\0'; *add the null terminator to the end of dest */
	dest_start = dest;

	return (dest_start);
}

/**
 *  _strlen - a function that shows the prints the lenght of the array
 *
 *   @s: - the array
 *   Return: the size of the string
 */
int _strlen(char *s)
{
	int a = 0;

	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}


/**
 * _strcmp - a function that comapre two string
 *  @s1: - the first pointer to the string
 *  @s2: - the second pointer to the string
 *     *Return: an int
 */

int _strcmp(char *s1, char *s2)
{
	int a;
	int b;
	int i;
	int d;
	int s;

	d = 0;
	s = strlen(s1);
	for (i = 0; i < s; i++)
	{
		if (s1[i] != s2[i])
		{
			a = s1[i];
			b = s2[i];
			d = a - b;
			break;
		}
		else
		{
			d = 0;
		}
	}
	return (d);
}





/**
 *  _strncmp - function compares the first `n`
 *  characters of the strings `s1` and `s2`.
 * It returns a negative number if
 * @s1: is less than
 * @s2: a positive number if `s1` is greater than `s2`,
 * and 0 if the strings are equal.
 * @n: the asize of the strings
 * Return: an int
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	/* Iterate over the first `n` characters of the strings */
	for (i = 0; i < n; i++)
	{

		if (s1[i] == '\0' || s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (0);
}
