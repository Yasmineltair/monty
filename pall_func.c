#include "monty.h"

/**
  * pall_func - print stack
  * @head: header
  * @line_number: line number
  */

void pall_func(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
