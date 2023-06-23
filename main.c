#include "monty.h"

/**
 * main - main function.
 * @argc: int argument.
 * @argv: char argument.
 *
 * Return: exit_success.
 */
int main(int argc, char *argv[])
{
	const char *doc;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	doc = argv[1];
	run_file(doc);

	return (EXIT_SUCCESS);
}
