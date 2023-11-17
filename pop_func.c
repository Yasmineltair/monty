#include "monty.h"

/**
  * pop_func - removes the top element of the stack.
  * @head: header
  * @line_number: line_number
  */

void pop_func(stack_t **head, unsigned int line_number)
{
stack_t *temp;
(void)line_number;

if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
free_stack(*head);
exit(EXIT_FAILURE);
}
temp = *head;
*head = temp->next;
free(temp);
}
