#include "monty.h"

global_t vglo;

/**
 * free_vglo - frees global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(vglo.stack);
	free(vglo.buffer);
	fclose(vglo.file_descriptor);
}

/**
 * start_vglo - initialies the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_vglo(FILE *fd)
{
	vglo.is_lifo = 1;
	vglo.line_count = 1;
	vglo.arg = NULL;
	vglo.stack = NULL;
	vglo.file_descriptor = fd;
	vglo.buffer = NULL;
}

/**
 * check_input - checks if the file exists and can be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file dtruct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return fd;
}
