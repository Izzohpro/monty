#include "monty.h"

/**
 * main - entry point of the program.
 * @argumentCount: number of command-line arguments.
 * @argumentVector: array of command-line arguments.
 *
 * Return: exit status.
 */
int main(int argumentCount, char *argumentVector[])
{
	const char *docname;

	if (argumentCount != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	docname = argumentVector[1];
	runfile(docname);

	return (EXIT_SUCCESS);
}
