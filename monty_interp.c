#include "monty.h"

info_t info = { NULL, NULL, NULL};
/**
 * main - interpreter for Monty ByteCodes files.
 * @argc: number of arguments.
 * @argv: path to the file monty byte code.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	FILE *file;
	ssize_t readline;
	char *monty_op;
	size_t size = 32;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	info.file = file;
	monty_op = malloc(size * sizeof(char));
	if (monty_op == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (readline > 0)
	{
		monty_op = NULL;
		readline = getline(&monty_op, &size, file);
		line_number++;
		if (readline > 0)
			exe_opcode(monty_op, &stack, line_number, file);
		free(monty_op);
	}
	_free(stack);
	fclose(file);
		return (0);
}

