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
	const char *fileName;

	if (argumentCount != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileName = argumentVector[1];
	processFile(fileName);

	return (EXIT_SUCCESS);
}
