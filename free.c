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
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(line, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	opcode = strtok(NULL, " \n\t");
	while (op_list[i].opcode && opcode)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
		{
			op_list[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (opcode && op_list[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
