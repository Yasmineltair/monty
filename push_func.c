#include "monty.h"

/**
  * push_func - push node to stack
  * @head: header
  * @line_number: line number
  */

void push_func(stack_t **head, unsigned int line_number)
{
	int i;
	int j = 0;
	int ffff = 0;

	if (info.argument)
	{
		if (info.argument[0] == '-')
			j++;
		for (; info.argument[j] != '\0'; j++)
		{
			if (info.argument[j] > 57 || info.argument[j] < 48)
				ffff = 1;
		}
		if (ffff == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free(info.line);
					free_stack(*head);
					exit(EXIT_FAILURE);
					}
					}
	else
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free(info.line);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	i = atoi(info.argument);
	if (info.lifi == 0)
	add_node(head, i);
	else
	add_queue(head, i);
	}

