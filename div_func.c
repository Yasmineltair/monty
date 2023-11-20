#include"monty.h"

/**
  * div_func - divides the second top element
  * of the stack by the top element of the stack.
  * @head: head node
  * @line_number: line number
  */

void div_func(stack_t **head, unsigned int line_number)
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
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
aux = temp->next->n / temp->n;
temp->next->n = aux;
*head = temp->next;
free(temp);
}
