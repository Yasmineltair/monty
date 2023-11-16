#include "monty.h"

/**
  * free_stack - function that free stack
  * @head: header of the stack
  */

void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
  *
  *
  *
  *
  */

void apply_func(op_list func, char *operation, char *value, int line_number, int ffff)
{
	stack_t *node;
	int ffff = 1;
	int i;

	if (strcmp(operation, "push" == 0))
			{
				if (value != NULL && value[0] == '-')
				{
					value++;
					ffff = -1;
				}
				if (value == NULL)
				{
					fprintf(stderr, "

