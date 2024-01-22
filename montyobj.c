#include "monty.h"

/**
* open_file - opens a file
* @input_file_path: the file namepath
* Return: void
*/
void open_file(char *input_file_path)
{
FILE *file_stream = fopen(input_file_path, "r");

if (input_file_path == NULL || file_stream == NULL)
error(2, input_file_path);

read_file(file_stream);
fclose(file_stream);
}

/**
* read_file - Reads a Monty bytecode file and processes each line.
* @file_stream: The file stream to read from.
* Return: void
*/
void read_file(FILE *file_stream)
{
int line_index = 1;
int parsing_format = 0;
char *line_content = NULL;
size_t line_length = 0;

while (getline(&line_content, &line_length, file_stream) != -1)
{
parsing_format = parse_line(line_content, line_index, parsing_format);
line_index++;
}
free(line_content);
}

/**
* parse_line - Parses a line of Monty bytecode and
* determines the appropriate action.
* @line_content: The line of bytecode to parse.
* @line_index: The line number of the bytecode line.
* @parsing_format:  The current storage format.
* (0 for stack, 1 for queue).
* Return: Returns 0 if the opcode is stack. 1 if queue.
*/
int parse_line(char *line_content, int line_index, int parsing_format)
{
char *opcode, *value;
const char *delim = "\n ";

if (line_content == NULL)
error(4);

opcode = strtok(line_content, delim);
if (opcode == NULL)
return (parsing_format);
value = strtok(NULL, delim);

if (strcmp(opcode, "stack") == 0)
return (0);
if (strcmp(opcode, "queue") == 0)
return (1);

find_func(opcode, value, line_index, parsing_format);
return (parsing_format);
}

/**
* find_func - find the appropriate function for the opcode
* @opcode: opcode
* @value: argument of opcode
* @parsing_format:  The current storage format
* (0 for stack, 1 for queue).
* @line_index: The line number where the instruction is located.
* Return: void
*/
void find_func(char *opcode, char *value, int line_index, int parsing_format)
{
int i;
int flag;

instruction_t func_list[] = {
{"push", push_to_stack},
{"pall", print_stack},
{"pint", print_top_node},
{"pop", pop_top_node},
{"nop", nop_op},
{"swap", swap_top_nodes},
{"add", add_top_nodes},
{"sub", sub_top_nodes},
{"div", div_top_nodes},
{"mul", mul_top_nodes},
{"mod", mod_top_nodes},
{"pchar", print_char},
{"pstr", print_strg},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}};

if (opcode[0] == '#')
return;
for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
{
if (strcmp(opcode, func_list[i].opcode) == 0)
{
call_fun(func_list[i].f, opcode, value, line_index, parsing_format);
flag = 0;
}
}
if (flag == 1)
error(3, line_index, opcode);
}
