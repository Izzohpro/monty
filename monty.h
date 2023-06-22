#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list rep of a stack
 * @data: integer data of the node
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int data;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct global_s - global structure to store program state
 * @is_lifo: flag indicating whether the stack is LIFO (1) or FIFO (0)
 * @line_count: current line number being processed
 * @arg: argument parameter for the current instruction
 * @stack: pointer to the top of the stack
 * @file_descriptor: file descriptor for the input file
 * @buffer: buffer to store the input lines
 *
 * Desc: global structure to store program state and data
 */
typedef struct global_s
{
	int is_lifo;
	unsigned int line_count;
	char *arg;
	stack_t *stack;
	FILE *file_descriptor;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its corresponding function
 * @opcode: the opcode string
 * @function: function pointer to the opcode's implementation
 *
 * Desc: opcode and its corresponding pointer
 */
typedef struct instruction_s
{
	char *opcode;
	void (*function)(stack_t **stack, unsigned int line_number)
} instruction_t
;

extern global_t vglo;

/* Opcode functions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mol(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstrl(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotrl(stack_t **stack, unsigned int line_number);

/* utility functions */
void free_vlog(void);

#endif
