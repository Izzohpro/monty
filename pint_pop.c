#include "monty.h"

/**
 * pint_op - prints value at the top of stack.
 * @stack: double pointer to the head of the stack.
 * @line_count: line count in file.
 *
 * Return: void
 */
void pint_op(stack_t **stack, unsigned int line_count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_op - removes top element of stack.
 * @stack: double pointer to the head of stack.
 * @line_count: line number in file.
 *
 * Return: void
 */
void pop_op(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}
