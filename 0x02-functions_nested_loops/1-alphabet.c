#include "main.h"

/**
 *  Main - Print alphabet in lower caseS
 *  Return: Always 0.
 */

void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);
	_putchar('\n');
	return (0);
}
