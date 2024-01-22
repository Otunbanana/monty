#include "monty.h"

/**
* mul_top_nodes -  multiply the top two elements of the stack.
* @stack_head: Pointer to the top node of the stack.
* @line_number: the line number of the opcode.
*/
void mul_top_nodes(stack_t **stack_head, unsigned int line_number)
{
int multiply;

if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
more_error(8, line_number, "mul");

(*stack_head) = (*stack_head)->next;
multiply = (*stack_head)->n * (*stack_head)->prev->n;
(*stack_head)->n = multiply;
free((*stack_head)->prev);
(*stack_head)->prev = NULL;
}

/**
* mod_top_nodes - cal modulo of the top two elements of the stack.
* @stack_head: Pointer to the top node of the stack.
* @line_number: line number of the opcode.
*/
void mod_top_nodes(stack_t **stack_head, unsigned int line_number)
{
int modulo;

if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
more_error(8, line_number, "mod");

if ((*stack_head)->n == 0)
more_error(9, line_number);
(*stack_head) = (*stack_head)->next;
modulo = (*stack_head)->n % (*stack_head)->prev->n;
(*stack_head)->n = modulo;
free((*stack_head)->prev);
(*stack_head)->prev = NULL;
}
