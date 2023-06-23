#include "monty.h"

/**
 * nop_op - a placeholder for the alignment purpose.
 * @stack: double pointer to the head of stack.
 * @line_count: line count in file.
 *
 * Return: void
 */
void nop_op(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;
}

/**
 * sub_op - subtracts top element of the stack from second top element of stack.
 * @stack: double pointer to the head of the stack.
 * @line_count: line number of file.
 *
 * Return: void.
 */
void sub_op(stack_t **stack, unsigned int line_count)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n - (*stack)->n;
	pop_op(stack, line_count);
	(*stack)->n = sum;
}

/**
 * div_op - divides second top element of the stack by top element of stack.
 * @stack: double pointer to the head of the stack.
 * @line_count: line count in file.
 *
 * Return: void.
 */
void div_op(stack_t **stack, unsigned int line_count)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_count);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n / (*stack)->n;
	pop_op(stack, line_count);
	(*stack)->n = sum;
}

/**
 * mul_op - multiplies second top element of the stack with top element of stack.
 * @stack: double pointer to the head of stack.
 * @line_count: line count in the file.
 *
 * Return: void
 */
void mul_op(stack_t **stack, unsigned int line_count)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->next->n * (*stack)->n;
	pop_op(stack, line_count);
	(*stack)->n = sum;
}
