#include "shell.h"
/**
 * free_pointer - function that free pointer allocted before
 * @ptr: pointer to be free
 * Return: no return
 */
void free_pointer(char **ptr)
{
int i;
if (!ptr)
return;
for (i = 0; ptr[i]; i++)
{
	free(ptr[i]);
	ptr[i] = NULL;
}
free(ptr), ptr = NULL;
}
