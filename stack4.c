#include "monty.h"
void _pchar(stack_t **top, unsigned int line)
{
	int num;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n" , line);
		exit(EXIT_FAILURE);
	}
	num = (*top)->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n" , line);
		exit(EXIT_FAILURE);
	}

	putchar(num);
	putchar('\n');
}
