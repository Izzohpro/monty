#include "monty.h"

/**
 * swap_op - swap the element of a stack.
 * @stack: double pointer to the head of stack.
 * @line_count: line count in file.
 *
 * Return: void
 */
void swap_op(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	tmp->prev = (*stack)->prev;
	(*stack)->prev = tmp;

	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;

	*stack = tmp;
}

/**
 * add_op - adds the top two elements of the stack.
 * @stack: double pointer to the head of stack.
 * @line_count: line count in file.
 *
 * Return: void.
 */
void add_op(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}
