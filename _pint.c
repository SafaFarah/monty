#include "monty.h"

/**
 * _pint - prints element in  the top of stack.
 * @stack: pointer to doubly linked list.
 * @line_number: number of line.
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		_finish(info.file, stack, info.monty_op);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
