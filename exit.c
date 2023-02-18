#include "shell.h"
/**
 * *_strncpy - copies a string
 * @dest: destination to copy string
 * @src: source of string
 * @n: amount of character to be copied
 * Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int k, l;
	char *g = dest;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < n)
	{
		l = k;
		while (l < n)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (g);
}
/**
 * *_strncat - concatenates 2 strings
 * @dest: first string
 * @src: second string
 * @n: amount of bytes to be used
 * Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int k, l;
	char *g = dest;

	k = 0;
	l = 0;
	while (dest[k] != '\0')
		k++;
	while (src[l] != '\0' && l < n)
	{
		dest[k] = src[l];
		k++;
		l++;
	}
	if (l < n)
		dest[k] = '\0';
	return (g);
}
/**
 * *_strchr - locates a character in string
 * @g: string to be parsed
 * @c: character to look for
 * Return: pointer to the memory s
 */
char *_strchr(char *g, char c)
{
	do {
		if (*g == c)
			return (g);
	} while (*g++ != '\0');
	return (NULL);
}
