#include "monty.h"

/**
 * is_digit - checks if a string can be converted
 * @string: string to check
 *
 * Return: 0 if failed, 1 otherwise
 */
int is_digit(char *string)
{
	int i;

	if (string == NULL || string[0] == '\0')
		return (0);

	for (i = 0; string[i] != '\0'; i++)
	{
		if (i == 0 && (string[i] == '-' || string[i] == '+'))
			continue;
		if (string[i] < '0' || string[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * push_head - adds new node to the top
 * @head: pointer to the head of stack
 * @n: value to store new node
 *
 * Return: void
 */
void push_head(stack_t **head, int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = n;
	node->prev = NULL;
	node->next = *head;

	if (*head != NULL)
		(*head)->prev = node;

	*head = node;
}
