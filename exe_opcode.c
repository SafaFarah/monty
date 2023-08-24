#include "monty.h"

/**
 * exec_opcode - executes the opcode instructions.
 * @stack: head of doubly linked list.
 * @line: number of line.
 * @file: pointer to monty byte code file.
 * @monty_op: line content
 *
 * Return: 0 on success or 1 on failure.
 */
int exe_opcode(char *monty_op, stack_t **stack, unsigned int line, FILE *file)
{
	instruction_t operations[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opc;

	opc = strtok(monty_op, "\n\t");
	if (opc != NULL && opc[0] == '#')
		return (0);
	info.argv = strtok(NULL, "\n\t");
	while (operations[i].opcode != NULL && opc != NULL)
	{
		if (strcmp(opc, operations[i].opcode) == 0)
		{
			operations[i].f(stack, line);
			return (0);
		}
		i++;
	}
	if (opc != NULL && operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opc);
		_finish(file, stack, monty_op);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * _finish  - frees stack  and close file.
 * @stack: head of doubly linked list.
 * @file: pointer to monty byte code file.
 * @monty_op: line content
 */
void _finish(FILE *file, stack_t **stack, char *monty_op)
{
	fclose(file);
	free(monty_op);
	_free(*stack);
}
