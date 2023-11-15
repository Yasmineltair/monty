#include "monty.h"

/**
  * error_printing - function that identify the error message
  * @error_code: the error codes
  * (1): if var is not an integer or if there is
  * no argument given to push 
  * (2): If the stack is empty during pint
  * (3): If the stack is empty during pop
  * (4): If the stack contains less than two elements.
  */

void error_printing(int error_code)
{
va_list ag;
char *operation;
int l_number;

va_start(ag, error_code);
switch (error_code)
{
	case 1:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
		break;
	case 2:
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
		break;
	case 3:
		fprintf(stderr, "L%d: can't pop an empty stack\n",va_arg(ag, int));
		break;
	case 4:
		l_number = va_arg(ag, unsigned int);
		operation = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", va_arg(l_number, operation));
		break;
	default:
		break;
}
free_nodes();
exit(EXIT_FAILURE);
}
		
