#include "monty.h"

/**
 * swap_op - swaps the elements of a stack
 * @head: a pointer to the head of stack
 * @line_count: line number
 *
 * Return: no return
 */
void swap_op(stack_t **head, unsigned int line_count)
{
	stack_t *top;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	top = (*head)->next;
	(*head)->next = top->next;
	top->next = *head;
	top->prev = (*head)->prev;
	(*head)->prev = top;

	if ((*head)->next != NULL)
		(*head)->next->prev = *head;

	*head = top;
}
