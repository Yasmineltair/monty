#include "monty.h"
/**
  * execute - execute thr opcode
  * @opcode: opcode
  * @value: argument of opcode
  * @line_number: line number
  * @format: 0/1
  */
void execute(char *opcode, char *value, int line_number, int format)
{
	int i;
	int ffff;
instruction_t op_list[] = {
	{"push", push_func},
	{"pall", print_func},
	{"pint", pint_func},
	{"swap", swap_func},
	{NULL, NULL}
};
if (opcode[0] == '#')
return;
for (ffff = 1, i = 0; op_list[i].opcode != NULL; i++)
{
	if (strcmp(opcode, op_list[i].opcode) == 0)
	{
		bring_func(op_list[i].f, opcode, value, line_number, format)
			ffff = 0;
	}
}
if (ffff == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", opcode);
		exit(EXIT_FAILURE);
	}
}
