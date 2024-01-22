#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file(char *input_file_path);
int parse_line(char *line_content, int line_index, int parsing_format);
void read_file(FILE *file_stream);
int len_chars(FILE *file_stream);
void find_func(char *opcode, char *value, int line_index, int parsing_format);

/*Stack operations*/
stack_t *allocate_node(int n);
void free_nodes(void);
void print_stack(stack_t **stack_head, unsigned int line_number);
void push_to_stack(stack_t **new_node, unsigned int ln);
void append_to_queue(stack_t **new_node, unsigned int ln);

void call_fun(op_func func, char *op, char *val, int line_index, int parsing_format);

void print_top_node(stack_t **stack_head, unsigned int line_number);
void pop_top_node(stack_t **stack_head, unsigned int line_number);
void nop_op(stack_t **stack_head, unsigned int line_number);
void swap_top_nodes(stack_t **stack_head, unsigned int line_number);

/*Math operations with nodes*/
void add_top_nodes(stack_t **stack_head, unsigned int line_number);
void sub_top_nodes(stack_t **stack_head, unsigned int line_number);
void div_top_nodes(stack_t **stack_head, unsigned int line_number);
void mul_top_nodes(stack_t **stack_head, unsigned int line_number);
void mod_top_nodes(stack_t **stack_head, unsigned int line_number);

/*String operations*/
void print_char(stack_t **stack_head, unsigned int line_number);
void print_strg(stack_t **stack_head, unsigned int line_number);
void rotl(stack_t **stack_head, unsigned int line_number);
void rotr(stack_t **stack_head, unsigned int line_number);

/*Error handling*/
void error(int error_code, ...);
void more_error(int error_code, ...);
void string_error(int error_code, ...);

#endif
