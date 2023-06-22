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
