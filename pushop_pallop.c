#include "monty.h"

/**
 * push_op - push element into the stack.
 * @stack: double pointer to the head of the stack.
 * @line_count: line count in file.
 *
 * Return: void.
 */
void push_op(stack_t **stack, unsigned int line_count)
{
	char *a;
	int m;

	a = strtok(NULL, " \n");

	if (a == NULL || !is_num(a))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}

	m = atoi(a);
	push_opstack(stack, m);
}


/**
 * pall_op - prints all values in stack.
 * @stack: double pointer to the head of stack.
 * @line_count: line count in file.
 *
 * Return: void.
 */
void pall_op(stack_t **stack, unsigned int line_count)
{
	stack_t *c;
	(void)line_count;

	c = *stack;
	if (c == NULL)
		return;

	while (c != NULL)
	{
		printf("%d\n", c->n);
		c = c->next;
	}
}
