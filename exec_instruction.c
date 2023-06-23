#include "monty.h"

/**
 * exec_instruction - execute instructions.
 * @opcode: opcode.
 * @stack: double pointer to the head of the stack
 * @line_count: line count in file.
 *
 * Return: void.
 */
void exec_instruction(char *opcode, stack_t **stack, unsigned int line_count)
{
	int cindy, pop;

	instruction_t instruc[] = {
		{"push", push_op},
		{"pall", pall_op},
	};

	cindy = sizeof(instruc) / sizeof(instruction_t);

	for (pop = 0; pop < cindy; pop++)
	{
		if (strcmp(opcode, instruc[pop].opcode) == 0)
		{
			instruc[pop].f(stack, line_count);
			break;
		}
	}
	if  (pop == cindy)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_count, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * run_file - execute instructions.
 * @doc: file name.
 *
 * Return: void.
 */
void run_file(const char *doc)
{
	char *input = NULL;
	char *opcode;
	size_t size = 0;
	ssize_t length;
	unsigned int line_count = 0;
	stack_t *stack = NULL;

	FILE *file = fopen(doc, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", doc);
		free(input);
		exit(EXIT_FAILURE);
	}
	while ((length = getline(&input, &size, file)) != -1)
	{
		line_count++;
		opcode = strtok(input, " \n\t\r");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		exec_instruction(opcode, &stack, line_count);
	}
	fclose(file);
	free(input);

	while (stack != NULL)
	{
		stack_t *next = stack->next;

		free(stack);
		stack = next;
	}
}
