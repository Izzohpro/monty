#include "monty.h"

/**
 * is_num - check for a string can be coneverted to interger.
 * @s: the string to check.
 *
 * Return: 1 or 0 otherwise.
 */
int is_num(char *s)
{
	int imp;

	if (s == NULL || s[0] == '\0')
		return (0);

	for (imp = 0; s[imp] != '\0'; imp++)
	{
		if (imp == 0 && (s[imp] == '-' || s[imp] == '+'))
			continue;
		if (s[imp] < '0' || s[imp] > '9')
			return (0);
	}
	return (1);
}

/**
 * push_opstack - adds a new node to top of stack.
 * @stack: double pointer to the head of stack.
 * @n: value to store in the new node.
 *
 * Return: void.
 */
void push_opstack(stack_t **stack, int n)
{
	stack_t *pop_node;

	pop_node = malloc(sizeof(stack_t));
	if (pop_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	pop_node->n = n;
	pop_node->prev = NULL;
	pop_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = pop_node;

	*stack = pop_node;
}
