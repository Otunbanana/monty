#include "monty.h"

/**
* call_fun - Calls the required function.
* @func: The function to be called.
* @op: The name of the instruction being executed.
* @val: The argument for the instruction, if any.
* @line_index: line numeber for the instruction.
* @parsing_format: Format specifier.
* If 0 Nodes will be entered as a stack.
* if 1 nodes will be entered as a queue.
*/
void call_fun(op_func func, char *op, char *val,
int line_index, int parsing_format)
{
stack_t *node;
int flag;
int i;

flag = 1;
if (strcmp(op, "push") == 0)
{
if (val != NULL && val[0] == '-')
{
val = val + 1;
flag = -1;
}
if (val == NULL)
error(5, line_index);
for (i = 0; val[i] != '\0'; i++)
{
if (isdigit(val[i]) == 0)
error(5, line_index);
}
node = allocate_node(atoi(val) * flag);

if (parsing_format == 0)
func(&node, line_index);

if (parsing_format == 1)
append_to_queue(&node, line_index);
}
else
func(&head, line_index);
}
