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

void _pstr(stack_t **top, __attribute__((unused))unsigned int line)
{
	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	while (*top != NULL)
	{
		if ((*top)->n <= 0 || (*top)->n > 127)
			break;
		putchar((*top)->n);
		*top = (*top)->next;
	}
	putchar('\n');
}
