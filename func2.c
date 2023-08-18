#include "main.h"

/**
 * *_strcpy - custom strcpy()
 * @dest: destination string (to)
 * @src: source string (from)
 *
 * Return: ptr
*/
char *_strcpy(char *dest, char *src)
{
    char *ptr = dest;

	while (*src != '\0')
	{
	    *dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}

/**
 * _strcat - custom strcat()
 * @dest: destination string (to)
 * @src: source string (from)
 *
 * Return: dest
*/
char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}