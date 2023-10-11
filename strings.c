#include "shell.h"
/**
 * _strdup- function that return copy of string
 * @str: string pointer to be duplicate
 * Return: pointer to duplicte string
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
	return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	return (NULL);
	for (i = 0; i <= len; i++)
	ptr[i] = str[i];
	return (ptr);

}
/**
 * strcmp - function that compare two string
 * @c1: the first string to be compared
 * @c2: the second string
 * Rturn: 0 if is equal ,positve if is greator
 * negative if first string is less than second string
*/
int _strcmp(char *c1, char *c2)
{
	int i;
	i = (int)*c1 - (int)*c2;
	while (*c1)
	{
		if (*c1 != *c2)
		break;
		c1++;
		c2++;
		i = (int)*c1 - (int)*c2;
	}
	return (i);
}
/**
 * strlen - count the length of string
 * @c: the string wante length of her
 * Return: the length of string
*/
int _strlen(char *c)
{
int len = 0;
while (c[len] != '\0')
len++;
return (len);
}
/**
 * strcat - concatenat two string
 * @dest: destination string to be appended
 * @src: source string to concatenated
 * Return: the destination string
*/
char *_strcat(char *dest, char *src)
{
	char *p = dest;

while (*p)
{


		p++;
}
		while (*src)
		{
			*p = *src;
			p++;
			src++;
		}
		*p = '\0';
		
		return (dest);
	

}
/**
 * strcpy - copy string from source to destination
 * @dest: destination buffe
 * @src: the source to be copied
*/
char *_strcpy(char *dest, char *src)
{
	int x = 0;
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	
	}
	dest[x] = '\0';
	return (dest);
}
