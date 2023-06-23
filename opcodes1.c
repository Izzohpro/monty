#include "monty.h"

/**
 * push_op - pushes element into the stack
 * @head: pointer to the head of the stack
 * @line_count: line number in file.
 *
 * Return: void
 */
void push_op(stack_t **head, unsigned int line_count)
{
	char *argument;
	int value;

	argument = strtok(NULL, " \n");

	if (argument == NULL || !is_digit(argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);
	push_head(head, value);
}

/**
 * pall_op - prints all values on the stack
 * @head: pointer to the head of stack.
 * @line_count: line number
 *
 * Return: void
 */
void pall_op(stack_t **head, unsigned int line_count)
{
	stack_t *current;
	(void)line_count;

	current = *head;
	if (current == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
