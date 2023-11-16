#include "monty.h"

/**
  * pint_func - function that print the top of stack
  * @head: the head of the stack
  * @line_number: line_number.
  */

void pint_func(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf("stderr, L%u: can't pint, stack empty\n", line_number);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
