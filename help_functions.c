#include "monty.h"

/**
  * free_nodes - function that free nodes
  */

void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
  * open_file - function to open files
  * @file_name: the name of the file
  */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		fprintf(stderr, " Can't open file %s\n", file_name);
	read_file(fd);
	fclose(fd);
}

/**
  *
  *
  *
  */


