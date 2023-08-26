#include "monty.h"

/**
 * _push - pushes an element to the stack.
 * @stack: pointer to doubly linked list repesentation of stack.
 * @line_number: the line where instruction appears.
 *
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new;
	int n, i = 0, nodigit = 0;

	if (info.argv != NULL)
	{
		if (info.argv[0] == '-')
			i++;
		for (; info.argv[i] != '\0'; i++)
		{
			if (info.argv[i] > 57 || info.argv[i] < 48)
				nodigit = 1;
		}
	}
	if (info.argv == NULL || nodigit == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		_finish(info.file, stack, info.monty_op);
		exit(EXIT_FAILURE);
	}
	n = atoi(info.argv);
	temp = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	new->n = n;
	new->prev = NULL;
	if (temp == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	else
	{
		temp->prev = new;
		new->next = temp;
		*stack = new;
	}
}
