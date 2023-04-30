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

	for (i = 0; src[i] != '\0'; i++)  /* Copy the contents of src to dest */
	{

		dest[i] = src[i];
	}
	return (dest);
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

	if (s == NULL)
		return (-1);
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
	int a = 0;
	int b = 0;
	int i = 0;
	int d = 0;
	int s = 0;

	s = _strlen(s1);
	if (s1 == NULL || s2 == NULL)
		return (-1);
	for (; i < s; i++)
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
