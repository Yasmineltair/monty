#include "monty.h"

/**
  * push_to_stack - function add node to stack
  * @head: head of the sack
  * @n: value
  *
  */

void push_to_stack(stack_t **head, int n)
{
	stack_t *temp, new_node;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
/**
  * print_stack - prints all the values on the stack
  * @head: head of the stack
  * @count: void parmeter
  */

void print_stack(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;
	if (temp == NULL)
		return;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
}
