#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

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


/**
 * struct info_s - code file , line content and array pointer to arguments.
 * @file: code file pointer.
 * @argv: array pointer to arguments.
 * @monty_op: line content.
 *
 * Description: information about operations code file-line content-arguments.
 */
typedef struct info_s
{
	FILE *file;
	char *monty_op;
	char *argv;
} info_t;

extern info_t info;
void _push(stack_t **stack, unsigned int line_number);
int _isdigit(int c);
void _pall(stack_t **stack, unsigned int line_number);
int exe_opcode(char *monty_op, stack_t **stack, unsigned int line, FILE *file);
void _finish(FILE *file, stack_t **stack, char *monty_op);
void _free(stack_t *pointer);

#endif
