#include "monty.h"
/**
* main - entry point
* @argc: arguments count
* @argv: list of arguments
* Return: always 0
*/
int main(int argc, char *argv[])
{
stack_t *head = NULL;
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
* allocate_node - Creates a node.
* @n: Number to go inside the node.
* Return: pointer to the node if successful. Otherwise NULL.
*/
stack_t *allocate_node(int n)
{
stack_t *node = malloc(sizeof(stack_t));

if (node == NULL)
{
error(4);
return (NULL);
}

node->next = NULL;
node->prev = NULL;
node->n = n;

return (node);
}

/**
* free_nodes - Frees nodes.
*/
void free_nodes(void)
{
while (head != NULL)
{
stack_t *tmp = head;
head = head->next;
free(tmp);
}
}

/**
* append_to_queue - Adds a node to the queue.
* @new_node: Pointer to the new node.
* @ln: line number of the opcode.
*/
void append_to_queue(stack_t **new_node,
__attribute__((unused)) unsigned int ln)
{
stack_t *tail;

if (new_node == NULL || *new_node == NULL)
exit(EXIT_FAILURE);

if (head == NULL)
{
head = *new_node;
return;
}

tail = head;
while (tail->next != NULL)
tail = tail->next;

tail->next = *new_node;
(*new_node)->prev = tail;
}
