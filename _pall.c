#include "monty.h"

/**
 * _pall - prints all the values on the stack.
 * @stack: pointer to doubly linked list repesentation of stack.
 * @line_number: the line where instruction appears.
 *
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
