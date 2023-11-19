#include "monty.h"

info_t info = {NULL, NULL};

/**
  * main - entry point
  * @argc: number of args
  * @argv: value of args
  * Return: 0 on success
  */

int main(int argc, char *argv[])
{
	FILE *file;
	ssize_t r_line = 1;
	size_t length = 0;
	unsigned int line_number;
	stack_t *stack = NULL;
	char *line;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (r_line > 0)
	{
		r_line = getline(&line, &length, file);
		info.line = line;
		line_number++;
		if (r_line > 0)
			exec(line, &stack, line_number, file);
		free(line);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
