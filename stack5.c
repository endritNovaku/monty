#include "monty.h"

int is_comm(char *token, unsigned int line)
{
	if (token[0] == '#' || token == NULL)
	{
		line++;
		return (1);
	}
	return (-1);
}
