#include "monty.h"

/**
 * parse_command - parses command
 * @opcode: operation identifier
 * @head: pointer to the head of a stack
 * @line_count: line number
 *
 * Return: void
 */
void parse_command(char *opcode, stack_t **head, unsigned int line_count)
{
	int c, i;

	instruction_t cindy[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
	};

	i = sizeof(cindy) / sizeof(instruction_t);

	for (c = 0; c < i; i++)
	{
		if (strcmp(opcode, cindy[i].opcode) == 0)
		{
			cindy[c].f(head, line_count);
			break;
		}
	}
	if (c == i)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_count, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * runfile - execute instructions
 * @docname: name of file
 *
 * Return: void
 */
void runfile(const char *docname)
{
	char *line = NULL, *opcode;
	size_t line_size = 0;
	ssize_t line_length;
	unsigned int line_count = 0;
	stack_t *head = NULL;
	FILE *doc = fopen(docname, "r");

	if (doc == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", docname);
		free(line);
		exit(EXIT_FAILURE);
	}

	while ((line_length = getline(&line, &line_size, doc)) != -1)
	{
		line_count++;
		opcode = strtok(line, " \n\t\r");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		parse_command(opcode, &head, line_count);
	}
	fclose(doc);
	free(line);

	while (head != NULL)
	{
		stack_t *next = head->next;

		free(head);
		head = next;
	}
}
