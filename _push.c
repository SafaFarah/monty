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
	int n, i, nodigit;

	if (info.argv != NULL)
	{
		for (i = 0; info.argv[i] != '\0'; i++)
		{
			if (!(_isdigit(info.argv[i])))
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
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
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




/**
 * _isdigit - a function that checks for digit.
 * @c: character
 *
 * Return: 1 if is digit or 0 if is not digit.
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}


