#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

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

/**
  * struct info_s - strucr containing file, line
  * argument variables
  * @file: pointer to monty file
  * @line: pointer to line content
  * @argument: argument value
  */

typedef struct info_s
{
	char *line;
	char *argument;
	int lifi;
} info_t;

extern info_t info;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>


void free_stack(stack_t *head);
int exec(char *line, stack_t **stack,unsigned int line_number, FILE *file);
void pall_func(stack_t **head, unsigned int line_number);
void push_func(stack_t **head, unsigned int line_number);
void pint_func(stack_t **head, unsigned int line_number);
void pop_func(stack_t **head, unsigned int line_number);
void add_func(stack_t **head, unsigned int line_number);
void swap_func(stack_t **head, unsigned int line_number);
void nop_func(stack_t **head, unsigned int line_number);
void add_queue(stack_t **h, int n);
void add_node(stack_t **head, int n);
void sub_func(stack_t **head, unsigned int line_number);

#endif
