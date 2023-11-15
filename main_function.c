#include "monty.h"

/**
  * push_to_stack - function add node to stack
  * @new_node: pointer to the new node
  * @line: line number of opcode
  *
  */

void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (top == NULL)
	{
		top == *new_node;
		return;
	}
	else
	{
		temp = top;
		temp = *new_node;
		top->next = temp;
		temp->prev = top;
	}
}

/**
  * print_stack - prints all the values on the stack
  * @stack: pointer to the stack
  * @line: line number of the opcode
  */

void print_stack(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	else
	{
		temp = *stack;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}
