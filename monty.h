#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

typedef struct stack_s
{
	int data;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct global_s
{
        int is_lifo;
        unsigned int line_count;
        char *arg;
        stack_t *stack;
        FILE *file_descriptor;
        char *buffer;
} global_t;

typedef struct instruction_s
{
	char *opcode;
	void (*function)(stack_t **stack, unsigned int line_number)
} instruction_t;

extern global_t vglo;

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

void free_vglo(void);
void _mul(stack_t **stack, unsigned int line_number);
void _mol(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstrl(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotrl(stack_t **stack, unsigned int line_number);

void free_vlog(void);

#endif
