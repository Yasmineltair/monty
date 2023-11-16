#include "monty.h"
/**
  * execute - execute thr opcode
  * @stack: linked list
  * @line_number: line number
  * @line: line
  * @file: file monty
  * Return: 0
  */
int execute(char *line, stack_t **stack, unsigned int line_number, FILE *file)
{
instruction_t op_list[] = {
	{"push", push_to_stack},
	{"pall", print_stack},
	{"pint", pint_func},
	{"swap", swap_func};
	{NULL, NULL}
};
unsigned int i;
char *operation;
char *value;

operation = strtok(line, " \n\t");
if (operation && operation[0] == '#')
return (0);
value = strtok(NULL, " \n\t");
while (op_list[i].opcode && operation)
{
	if (strcmp(operation, op_list[i].opcode) == 0)
	{
		op_list[i].f(stack, line_number);
		return (0);
	}
	i++;
}
if (operation && op_list[i].opcode == NULL)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, operation);
fclose(file);
free(line);
free_stack(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
