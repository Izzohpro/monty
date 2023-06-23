#include "monty.h"

/**
 * push_op- pushes element into the stack
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
