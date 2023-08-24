#include "monty.h"

/**
 * _push - push data to the top of a stack
 * @head: the head of a stack double ll
 * @line_number: line number parsed
 */
void _push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (buf.arg)
	{
		if (buf.arg[0] == '-')
			j++;
		for (; buf.arg[j] != '\0'; j++)
		{
			if (buf.arg[j] > 57 || buf.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(buf.file);
			free(buf.command);
			free_dlist(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(buf.file);
		free(buf.command);
		free_dlist(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(buf.arg);
	if (buf.flag == 0)
		addnode(head, n);
	else
		addqueue(head, n);
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


