#include "monty.h"

/**
* main - Entry point for the Monty interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
*
* Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

stack_t *stack = NULL;

execute_file(argv[1], &stack);

return (EXIT_SUCCESS);
}

/**
* execute_file - Execute Monty
* @filename: Name of the file
* @stack: Pointer to the stack
*
* Return: None
*/
void execute_file(char *filename, stack_t **stack)
{
FILE *file = fopen(filename, "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}

char *line = NULL;
size_t len = 0;
unsigned int line_number = 0;

while (getline(&line, &len, file) != -1)
{
line_number++;
}

fclose(file);
free(line);
}
