#include "monty.h"

/**
  * queue_func - sets the format of the data to a queue (FIFO).
  * @head: head
  * @line_number: linenumber
  */

void queue_func(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	info.lifi = 1;
}

/**
  * stack_func - sets the format of the data to a stack (LIFO)
  * @head: head
  * @line_number: line number
  */

void stack_func(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	info.lifi = 0;
}
