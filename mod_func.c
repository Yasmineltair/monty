#include "monty.h"

/**
  * mod_func - computes the rest of the
  division of the second top element of the stack
  * by the top element of the stack.
  * @head: header node
  * @line_number: line_number
  */

void mod_func(stack_t **head, unsigned int line_number)
{
	int length = 0;
	stack_t *temp;
	int aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(info.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(info.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = temp->next->n % temp->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}
