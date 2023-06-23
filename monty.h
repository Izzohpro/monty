#ifndef _MONTY_H_
#define _MONTY_H_

/* Macro */
#define _POSIX_C_SOURCE 200809L

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* Structs */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push_op(stack_t **head, unsigned int line_count);
void pall_op(stack_t **head, unsigned int line_count);
void pint_op(stack_t **head, unsigned int line_count);
void pop_op(stack_t **head, unsigned int line_count);
void swap_op(stack_t **head, unsigned int line_count);
void runfile(const char *docname);
void parse_command(char *opcode, stack_t **head, unsigned int line_count);
void nop(stack_t **head, unsigned int line_count);
void add(stack_t **head, unsigned int line_count);

/* assist prototype */
int is_digit(char *string);
void push_head(stack_t **head, int n);

#endif /* MONTY_H */
