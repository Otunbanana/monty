#include "monty.h"

/**
* error - Handles errors with codes 1-5 and prints
* error messages to stderr, frees allocated memory using
* free_nodes() and exit program with EXIT_FAILURE.
* @error_code: The error codes are numbered 1 - 11.
* For
* more_error - Handles errors with codes 6-9 when
* the stack it empty for pint, the stack it empty for pop,
* When stack is too short for operation and Division by zero.
* For
* string_error - Handles errors specifically related
* to string operations (codes 10-11). when the number inside
* a node is outside ASCII bounds and when the stack is empty.
*/
void error(int error_code, ...)
{
va_list ag;
char *op;
int line_num;

va_start(ag, error_code);
switch (error_code)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
break;
case 3:
line_num = va_arg(ag, int);
op = va_arg(ag, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

void more_error(int error_code, ...)
{
va_list ag;
char *op;
int line_num;

va_start(ag, error_code);
switch (error_code)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
break;
case 8:
line_num = va_arg(ag, unsigned int);
op = va_arg(ag, char *);
fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
break;
case 9:
fprintf(stderr, "L%d: division by zero\n", va_arg(ag, unsigned int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

void string_error(int error_code, ...)
{
va_list ag;
int line_num;

va_start(ag, error_code);
line_num = va_arg(ag, int);
switch (error_code)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}
