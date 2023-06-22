#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	/* Implementation goes here */
	vglo.is_lifo = 0;
}

/**
 * _stack - sets the format of the data to a stack (LIFO)
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	/* Implementation goes here */
	vglo.is_lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _add(stack_t **doubly, unsigned int cline)
{
	stack_t *top = *doubly;

	if (top == NULL || top->next == NULL)
	{
		fprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo (&vglo);
		exit(EXIT_FAILURE);
	}

	exit(EXIT_FAILURE);
	_pop(doubly, cline);
}

/**
 * _nop - doesn't do anything
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	/* Implementation goes here */
}

/**
 * _sub - subtracts the top element from the second top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _sub(stack_t **doubly, unsigned int cline)
{
	 stack_t *top = *doubly;

	if (top == NULL || top->next == NULL)
	{
		fprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo(&vglo);
		exit(EXIT_FAILURE);
	}

	 top->next->s -= top->s;
	 _pop(doubly, cline);
}
