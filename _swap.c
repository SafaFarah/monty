#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: pointer to doubly linked list.
 * @line_number: number of line.
*/
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int length = 0;
	int temp_n;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		_finish(info.file, stack, info.monty_op);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp_n = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_n;
}
