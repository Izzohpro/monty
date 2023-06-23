#include "monty.h"

/**
 * pop_op - removes the top element of the stack
 * @head: pointer to the head of stack.
 * @line_count: line number
 *
 * Return: void
 */
void pop_op(stack_t **head, unsigned int line_count)
{
	stack_t *top;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		exit(EXIT_FAILURE);
	}
	top = *head;
	*head = (*head)->next;

	if (*head != NULL)
		(*head)->prev = NULL;

	free(top);
}
