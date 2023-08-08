#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Assign 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing characters.
 *
 * Return: A pointer to the newly-assigned buffer.
 */
char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);

if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}

return (buffer);
}

/**
 * close_file - Cloing file descriptors.
 * @fd: The file descriptor set to  close.
 */
void close_file(int fd)
{
int d;

d = close(fd);

if (d == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * main - Copying contents of a file to another file.
 * @argc: The number of arguments in the program.
 * @argv: An array of pointers to the argument.
 *
 * Return: 0 on success.
 *
 * Description: Exit the code 97 if the argument count is incorrect.
 * Exit code 98 If file_from does not exist or cannot be read.
 * Exit code 99 If file_to cannot be created or written to.
 * Exit code 100 If file_to or file_from cannot be closed.
 */
int main(int argc, char *argv[])
{
int from, to, k, v;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
k = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (from == -1 || k == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

v = write(to, buffer, k);
if (to == -1 || v == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

k = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);

} while (k > 0);

free(buffer);
close_file(from);
close_file(to);

return (0);
}
