#include "monty.h"

/**
* print_char - Prints the Ascii value.
* @stack_head: Pointer to the top node of the stack.
* @line_number: the line number of the opcode.
*/
void print_char(stack_t **stack_head, unsigned int line_number)
{
int ascii;

if (stack_head == NULL || *stack_head == NULL)
string_error(11, line_number);

ascii = (*stack_head)->n;
if (ascii < 0 || ascii > 127)
string_error(10, line_number);

printf("%c\n", ascii);
}

/**
* print_strg - Prints a string.
* @stack_head: Pointer to the top node of the stack.
* @line_number: the line number of the opcode.
*/
void print_strg(stack_t **stack_head, __attribute__((unused))
unsigned int line_number)
{
int strg;
stack_t *tmp;

if (stack_head == NULL || *stack_head == NULL)
{
printf("\n");
return;
}

tmp = *stack_head;
while (tmp != NULL)
{
strg = tmp->n;
if (strg <= 0 || strg > 127)
break;
printf("%c", strg);
tmp = tmp->next;
}
printf("\n");
}

/**
* rotl - Rotates the first node of the stack to the bottom.
* @stack_head: Pointer to the top node of the stack.
* @line_number: the line number of of the opcode.
*/
void rotl(stack_t **stack_head, __attribute__((unused))
unsigned int line_number)
{
stack_t *tmp;

if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
return;

tmp = *stack_head;
while (tmp->next != NULL)
tmp = tmp->next;

tmp->next = *stack_head;
(*stack_head)->prev = tmp;
*stack_head = (*stack_head)->next;
(*stack_head)->prev->next = NULL;
(*stack_head)->prev = NULL;
}

/**
* rotr - Rotates the last node of the stack to the top.
* @stack_head: Pointer to the top node of the stack.
* @line_number: the line number of the opcode.
*/
void rotr(stack_t **stack_head, __attribute__((unused))
unsigned int line_number)
{
stack_t *tmp;

if (stack_head == NULL || *stack_head == NULL || (*stack_head)->next == NULL)
return;

tmp = *stack_head;
while (tmp->next != NULL)
tmp = tmp->next;

tmp->prev->next = NULL;
tmp->prev = NULL;
tmp->next = *stack_head;
(*stack_head)->prev = tmp;
*stack_head = tmp;
}
