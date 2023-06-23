#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: a pointer to the head of stack
 * @line_count: line number
 *
 * Return: void
 */
void add(stack_t **head, unsigned int line_count)
{
	stack_t *top;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n += (*head)->n;
	top = *head;
	*head = (*head)->next;

	if (*head != NULL)
		(*head)->prev = NULL;

	free(top);
}
