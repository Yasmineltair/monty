#include "monty.h"

/**
  * free_stack - free linked list
  * @head: header
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
  * exec - execute opcode
  * @line: line content
  * @stack: stack linked list
  * @line_number: line_number
  * @file: pointer to monty file
  * Return: 0 / 1
  */

int exec(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t op_list[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"queue", queue_func},
		{"stack", stack_func},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcd;

	opcd = strtok(line, " \n\t");
	if (opcd && opcd[0] == '#')
		return (0);
	info.argument = strtok(NULL, " \n\t");
	while (op_list[i].opcode && opcd)
	{
		if (strcmp(opcd, op_list[i].opcode) == 0)
		{
			op_list[i].f(stack, line_number);
			return (0);
		}
		i++; }
	if (opcd && op_list[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcd);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
