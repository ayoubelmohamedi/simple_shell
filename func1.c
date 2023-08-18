#include "main.h"

/**
 * _strcmp - strmcpm
 * @str1: First string
 * @str2: Second string
 *
 * Return: 0 if equal, otherwise the differences
*/
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str2[i] != str1[i])
			return (str1[i] - str2[i]);
		i++;
	}

return (0);
}

/**
 * _strncmp - custom strncmp()
 * @str1: first string
 * @str2: second string
 * @n: number to compare
 *
 * Return: a value, otherwise 0
*/
int _strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++)
    {
        if (str1[i] != str2[i])
            return ((unsigned char)str1[i] - (unsigned char)str2[i]);

        if (str1[i] == '\0')
            return (0);
    }
    return (0);
}

/**
 * _strcspn - custom strcspn()
 * @str: string.
 * @reject: reject.
 * 
 * Return: count
*/
size_t _strcspn(const char *str, const char *reject)
{
	const char *p, *r;
	size_t count = 0;
	for (p = str; *p != '\0'; ++p)
    {
		for (r = reject; *r != '\0'; ++r)
			if (*p == *r)
				return (count);
		++count;
	}

	return (count);
}

/**
 * _strdup - custom strdup()
 * @str: string
 *
 * Return: buffer on success, NULL on failure
 */
char *_strdup(char *str)
{
    char *buff;
	size_t i, j;

	i = _strlen(str);
	buff = malloc(sizeof(char) * (i + 1));

	if (buff == NULL)
		return (NULL);

	for (j = 0; j <= i; j++)
		buff[j] = str[j];

	return (buff);
}

/**
 * _strlen - custom strlen()
 * @str: string provided
 *
 * Return: length
 */
int _strlen(char *str)
{
	int len = 0;

		while (str[len] != '\0')
            len++;

return (len);
}
