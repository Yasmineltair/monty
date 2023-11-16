#include "monty.h"

/**
  * main - main function
  * @argc: number of argumnet
  * @argv: values of argument
  * Return 0 in success
  */

int main(int argc, char *argv[])
{
	FILE *file;
	ssize_t read_line = 1;
	char *line;
	size_t line_len = 0;
	stack_t *stack = NULL;
	unsigned int line_number;

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
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &line_len, file);
		line_number++;
		if (read_line > 0)
			execute(line,&stack, line_number, file);
		free(line);
	}
	free_stack;
	fclose(file);
return (0);
}
