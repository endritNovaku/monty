#include "monty.h"
void (*get_op_code(char *token, __attribute__((unused))unsigned int line))(stack_t **, unsigned int)
{
	int i;
	instruction_t operator [] =
	{
		{"push", _push},
		{"pop", _pop},
		{"pall", _pall},
		{"pint",_pint},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"nop", _nop},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	for (i = 0; operator[i].opcode != NULL; i++)
	{
		if (strcmp(token, operator[i].opcode) == 0)
		{
			return (operator[i].f);
		}
	}
	invalid_instructions_error(token, line);
	return(NULL);
}

void invalid_instructions_error(char *token, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}

void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

void file_error(char **argv)
{
	char *name = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", name);
	exit(EXIT_FAILURE);
}
