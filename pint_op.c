#include "monty.h"

/**
 * pint_op - Prints the value at the top of the stack.
 * @head: pointer to the head of the stack.
 * @line_count: line number
 *
 * Return: no return
 */
void pint_op(stack_t **head, unsigned int line_count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
