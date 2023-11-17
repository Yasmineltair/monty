#include "monty.h"

/**
  * swap_func - swaps the top two elements of the stack
  * @head: header
  * @line_number: line number
  */

void swap_func(stack_t **head, unsigned int line_number)
{
stack_t *temp;
int length, aux;

temp = *head;
while (temp)
{
	temp = temp->next;
	length++;
}
if (length < 2)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
temp = *head;
aux = temp->n;
temp->n = temp->next->n;
temp->next->n = aux;
}


