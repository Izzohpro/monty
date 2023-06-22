#include "monty.h"

/**
 * free_vglo - frees global variables
 *
 * @vglo: pointer to the global structure
 * Return: no return
 */
void free_vglo(global_t *vglo)
{
	free(vglo->buffer);
	fclose(vglo->file_descriptor);
}

/**
 * start_vglo - initialies global variables
 *
 * @vglo: pointer to the global structure
 * @fd: file descriptor
 * Return: no return
 */
void start_vglo(global_t *vglo, FILE *fd)
{
	vglo->is_lifo = 1;
	vglo->line_count = 1;
	vglo->arg = NULL;
	vglo->stack = NULL;
	vglo->file_descriptor = fd;
	vglo->buffer = NULL;
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

	return (fd);
}

/**
 * main - Entry level
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *line = NULL;
	char *token = NULL;
	global_t vglo;

	fd = check_input(argc, argv);
	start_vlog(&vglo, fd);
	while ((nlines = getline(&vglo.buffer, &size, fd)) != -1)
	{
		line = strtok(vglo.buffer, "\n");
		token = strtok(line, " \t");
		while (token != NULL)
		{
			if (token[0] != '#')
			{
				f = get_opcodes(token);
				if (!f)
				{
					dprintf(2, "L%u: ", vglo.line_count);
					dprintf(2, "unknown instruction %s\n", token);
					free_vglo(&vglo);
					exit(EXIT_FAILURE);
				}
				vglo.arg = strtok(NULL, " \t");
				f(&vglo.stack, vglo.line_count);
			}
			token = strtok(NULL, " \t");
		}
		vglo.line_count++;
	}

	free_vglo(&vglo);

	return (0);
