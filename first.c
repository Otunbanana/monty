#include "monty.h"

/**
* push_to_stack - push a node to the stack.
* @new_node: Pointer to the new node.
* @line_num: line number of of the opcode.
*/
void push_to_stack(stack_t **new_node,
__attribute__((unused)) unsigned int line_num)
{
stack_t *tmp;

if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *new_node;
return;
}
tmp = head;
head = *new_node;
head->next = tmp;
tmp->prev = head;
}

/**
* print_stack - print a node to the stack.
* @stack_head: Pointer to the top node of the stack.
* @line_number: line number of  the opcode.
*/
void print_stack(stack_t **stack_head, unsigned int line_number)
{
stack_t *tmp;

(void)line_number;
if (stack_head == NULL)
exit(EXIT_FAILURE);
tmp = *stack_head;
while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}

/**
* pop_top_node - Adds a node to the stack.
* @stack_head: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void pop_top_node(stack_t **stack_head, unsigned int line_number)
{
stack_t *tmp;

if (stack_head == NULL || *stack_head == NULL)
more_error(7, line_number);

tmp = *stack_head;
*stack_head = tmp->next;
if (*stack_head != NULL)
(*stack_head)->prev = NULL;
free(tmp);
}

/**
* print_top_node - Prints the top node of the stack.
* @stack_head: Pointer to a pointer pointing to top node of the stack.
* @line_number: Interger representing the line number of of the opcode.
*/
void print_top_node(stack_t **stack_head, unsigned int line_number)
{
if (stack_head == NULL || *stack_head == NULL)
more_error(6, line_number);
printf("%d\n", (*stack_head)->n);
}
