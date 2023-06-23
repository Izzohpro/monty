#include "monty.h"

/**
 * mod_op - computes the rest of division of the second top element
 * of the stack bytop element of the stack.
 * @stack: double pointer to the head of stack.
 * @line_count: line count in file.
 *
 * Return: void
 */
void mod_op(stack_t **stack, unsigned int line_count)
{
	int sum, div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->n;

	if (div == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_count);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n % div;
	pop_op(stack, line_count);
	(*stack)->n = sum;
}

/**
 * pchar_op - prints the char at the top of the stack.
 * @stack: double pointed to the head of stack.
 * @line_count: line count in file.
 *
 * Return: void
 */
void pchar_op(stack_t **stack, unsigned int line_count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_count);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr_op - prints the string starting at the top of the stack.
 * @stack: double pointer to the head of stack.
 * @line_count: line count in file.
 *
 * Return: void
 */
void pstr_op(stack_t **stack, unsigned int line_count)
{
	stack_t *cindy = *stack;
	(void)line_count;

	while (cindy != NULL && cindy->n > 0 && cindy->n <= 127)
	{
		printf("%c", cindy->n);
		cindy = cindy->next;
	}
	printf("\n");
}
