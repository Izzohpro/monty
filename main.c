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
 * start_vglo - initialies global variables
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

/**
 * main - Entry level
 *
 * @argc: arggument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_vlog(fd);
	nlines = getline(&vglo.buffer, &size, fd;);
	while (nlines != -1)
	{
		lines[0] = _strtoky(vglo.buffer. " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprint(2, "L%u: ", vglo.line_count);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = _strtoky(NULL, " \t\n");
			f(&vglo.stack, vglo.line_count);
		}
		nlines = getline(&vglo.buffer, &size, fd);
		vglo.line_count++;
	}

	free_vglo();
}
	return (0);
