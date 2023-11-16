#include "monty.h"

/**
  * swap_func - function swaps values
  * @head: stack head
  * @line_number: line_number
  */

void swap_func(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int length = 0;
	int value;

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
	value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = value;
}
