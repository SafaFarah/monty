#include "monty.h"

/**
 * _add - adds the second top element  with the top element of stack.
 * @stack: pointer of doubly linked list.
 * @line_number: number of line.
*/
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int length = 0;
	int add;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		_finish(info.file, stack,  info.monty_op);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	add = temp->next->n + temp->n;
	temp->next->n = add;
	*stack = temp->next;
	free(temp);
}

/**
 * _sub - substracts the second top element  with the top element of stack.
 * @stack: pointer of doubly linked list.
 * @line_number: number of line.
*/
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int length = 0;
	int sub;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		_finish(info.file, stack,  info.monty_op);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*stack = temp->next;
	free(temp);
}

/**
 * _mul - multiplies the second top element  with the top element of stack.
 * @stack: pointer of doubly linked list.
 * @line_number: number of line.
*/
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int length = 0;
	int mul;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_finish(info.file, stack,  info.monty_op);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	mul = temp->next->n * temp->n;
	temp->next->n = mul;
	*stack = temp->next;
	free(temp);
}

/**
 * _div - divides the second top element  with the top element of stack.
 * @stack: pointer of doubly linked list.
 * @line_number: number of line.
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int length = 0;
	int div;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_finish(info.file, stack,  info.monty_op);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_finish(info.file, stack,  info.monty_op);
		exit(EXIT_FAILURE);
	}
	div = temp->next->n / temp->n;
	temp->next->n = div;
	*stack = temp->next;
	free(temp);
}

/**
 * _mod - finds reminder of the second  element  with the top element of stack.
 * @stack: pointer of doubly linked list.
 * @line_number: number of line.
*/
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int length = 0;
	int mod;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_finish(info.file, stack,  info.monty_op);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_finish(info.file, stack,  info.monty_op);
		exit(EXIT_FAILURE);
	}
	mod = temp->next->n % temp->n;
	temp->next->n = mod;
	*stack = temp->next;
	free(temp);
}
