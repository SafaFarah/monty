#include "monty.h"

/**
 * _pop - delets  the top of stack.
 * @stack: pointer to doubly linked list.
 * @line_number: number of line.
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		_finish(info.file, stack, info.monty_op);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}
