#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - A program that print all single digit numbers
 *
 * Return: Always (Success)
 */

int main(void)

{

	int d;

	for (d = '0'; d <= '9'; d++)
		putchar(d);
	putchar('\n');

	return (0);
}
