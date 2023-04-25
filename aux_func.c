#include "main.h"

/**
 * _strcpy -  function that copies the string
 * @src: pointer to the strign
 * @dest: string copy destination
 * Return: dest
 **/

char *_strcpy(char *dest, char *src)
{

	char *dest_start = dest; /* save the star of the destination */

	while (*src != '\0')  /* Copy the contents of src to dest */
	{

		*dest = *src;

		dest++;

		src++;
	}

	*dest = '\0'; /* add the null terminator to the end of dest */

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

