#include"monty.h"

/**
  * mul_func - multiplies the second top
  * element of the stack with the top element of the stack.
  * @head: head node
  * @line_number: line number
  */

void mul_func(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(info.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n * temp->next->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}

