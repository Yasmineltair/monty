#include "monty.h"

/**
  * pint_func - function that print the top of stack
  * @head: the head of the stack
  * @count: line_number.
  */

void pint_func(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf("stderr, L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
