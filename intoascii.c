#include "shell.h"
/**
 * _itoa - helper function
 * @x: in number
 * Return: string
*/
char *_itoa(int x)
{
	char buffer[20];
	int i = 0;

	if (x == 0)
		buffer[i++] = '0';
	else
	{
		while (x > 0)
		{
			buffer[i++] = (x % 10) + '0';
			x /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_strdup(buffer));
}

/**
 * reverse_string - function reverse string
 * @str: string to be reversed
 * @len: length of the string
 * Return : void return
*/
void reverse_string(char *str, int len)
{
	int start = 0;
	int end = len - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

}
