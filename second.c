#include "monty.h"

/**
* nop_op - No operation - Do not do anything.
* @stack: Pointer to the top node of the stack.
* @line_number: line number of the opcode.
*/
void nop_op(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

/**
* swap_top_nodes - Swaps the top two nodes.
* @stack_head: Pointer to the top node of the stack.
* @line_number: line number of the opcode.
*/
void swap_top_nodes(stack_t **stack_head, unsigned int line_number)
{
stack_t *tmp;

if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
more_error(8, line_number, "swap");
tmp = (*stack_head)->next;
(*stack_head)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *stack_head;
tmp->next = *stack_head;
(*stack_head)->prev = tmp;
tmp->prev = NULL;
*stack_head = tmp;
}

/**
* add_top_nodes - Adds the top two elements of the stack.
* @stack: Pointer to the top node of the stack.
* @line_number:  line number of the opcode.
*/
void add_top_nodes(stack_t **stack, unsigned int line_number)
{
int sum;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_error(8, line_number, "add");

(*stack) = (*stack)->next;
sum = (*stack)->n + (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
* sub_top_nodes - substract the top two elements of the stack.
* @stack_head: Pointer to the top node of the stack.
* @line_number: line number of of the opcode.
*/
void sub_top_nodes(stack_t **stack_head, unsigned int line_number)
{
int difference;

if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
more_error(8, line_number, "sub");

(*stack_head) = (*stack_head)->next;
difference = (*stack_head)->n - (*stack_head)->prev->n;
(*stack_head)->n = difference;
free((*stack_head)->prev);
(*stack_head)->prev = NULL;
}

/**
* div_top_nodes - divides the top two elements of the stack.
* @stack_head: Pointer to the top node of the stack.
* @line_number: line number of of the opcode.
*/
void div_top_nodes(stack_t **stack_head, unsigned int line_number)
{
int divide;

if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
more_error(8, line_number, "div");

if ((*stack_head)->n == 0)
more_error(9, line_number);
(*stack_head) = (*stack_head)->next;
divide = (*stack_head)->n / (*stack_head)->prev->n;
(*stack_head)->n = divide;
free((*stack_head)->prev);
(*stack_head)->prev = NULL;
}
