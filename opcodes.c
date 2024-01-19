#include "monty.h"

/**
* push - Push an element the stack
* @stack: Pointer to the stack
* @line_number: Line number in the Monty bytecode file
*
* Return: None
*/
void push(stack_t **stack, unsigned int line_number)
{
char *token;
int value;

token = strtok(NULL, " \t\n");
if (!token || !isdigit(*token))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(token);

stack_t *new_node = malloc(sizeof(stack_t));
if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack)
{
(*stack)->prev = new_node;
}

*stack = new_node;
}

/**
* pull - Print all values on the stack
* @stack: Pointer to the stack
* @line_number: Line number in the Monty bytecode file
*
* Return: None
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
