#include "shell.h"
char *_strdup(char *str)
{
    char *ptr = NULL;
    int i, len = 0;
    if (str == NULL)
    {
    	free(str);
    	return (NULL);
    }
    while (*str != '\0')
    {
        len++;
        str++;
    }
    str = str - len;
    if (ptr == NULL)
    return (NULL);
    for (i = 0; i <= len; i++)
    ptr[i] = str[i];
    free(str);
    return (ptr);

}
