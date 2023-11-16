#include "monty.h"

/**
  *
  *
  *
  *
  */

int execute(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
instruction_t op_list[] = {
	{"push", push_to_stack},
	{"pall", print_stack},
	{"pint", pint_func},
	{"pop", pop_func},
	{"swap", swap_func},
	{"add", add_func},
}
