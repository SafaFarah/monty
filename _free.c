#include "monty.h"

/**
 * _free - frees the stack;
 * @pointer: pointer to the stack.
 */
void _free(stack_t *pointer)
{
	stack_t *temp;

	while (pointer != NULL)
	{
		temp = pointer->next;
		free(pointer);
		pointer = temp;
	}
}
