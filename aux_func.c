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
