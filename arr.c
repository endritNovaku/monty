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
		{NULL, NULL}
	};

	for (i = 0; operator[i].opcode != NULL; i++)
	{
		if (strcmp(token, operator[i].opcode) == 0)
		{
			return (operator[i].f);
		}
	}
	return(NULL);
}
