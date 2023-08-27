#include "monty.h"
info_t info = {NULL, NULL, NULL};
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
	ssize_t readline = 1;
	char *monty_op;
	size_t size = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	info.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readline > 0)
	{
		monty_op = NULL;
		readline = getline(&monty_op, &size, file);
		info.monty_op = monty_op;
		line_number++;
		if (readline > 0)
			exe_opcode(monty_op, &stack, line_number, file);
		free(monty_op);
	}
	_free(stack);
	fclose(file);
	return (0);
}

