#include <unistd.h>
/**
 * _putchar - A program that writes the character c to stdou
 * @c: The character to print
 * Return: 1 (Success)
 * on error, -1 is returned and error is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
