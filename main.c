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
