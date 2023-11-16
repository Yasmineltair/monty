#include "monty.h"

/**
  * main - main function
  * @argc: number of argumnet
  * @argv: values of argument
  * Return: 0 in success
  */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
  * open_file - function to open monty file
  * @file: file name
  */

void open_file(char *file)
{
	FILE *fd = fopen(file, "r");

	if (file == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	read_file(fd);
	fclose(fd);
}

/**
  * read_file - function read files
  * @fd: pointer to file descriptor
  */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *line = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&line, &length, fd) != -1; line_number++)
	{
		format = token_line(line, line_number, format);
	}
	free(line);
}

/**
  * token_line - function to separate line into tokens
  * @line: line
  * @line_number: line number
  * @format: storage format(0:stack, 1:queue)
  * Return:0 if stack and 1 if queue
  */

int line_token(char *line, int line_number, int format)
{
char *opcode, *value;
char *delim = "\n ";

if (line == NULL)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
opcode = strtok(line, delim);
if (opcode == NULL)
{
	return (format);
}
value = strtok(NULL, delim);

if (strcmp(opcode, "stack") == 0)
{
	return (0);
}
if (strcmp(opcode, "queue") == 0)
{
	return (1);
}
execute(opcode, value, line_number, format);
return (format);
}
