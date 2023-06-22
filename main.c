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
