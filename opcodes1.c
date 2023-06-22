#include "monty.h"

/**
 * push - pushes element into the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in file.
 *
 * Return: no return.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	int value;

	argument = strtok(NULL, " \n");

	if (argument == NULL || !is_number(argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);
	push_stack(stack, value);
}

/**
 * pall - prints all values on the stack
 * @stack: pointer to the head of stack.
 * @line_number: line number
 *
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (current == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}