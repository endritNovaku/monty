#include "monty.h"
/**
 * _swap - swap two elements of stack
 * @top: top node
 * @line: value
 */
void _swap(stack_t **top, __attribute__((unused))unsigned int line)
{
	int tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		printf("can't swap");
	}

	tmp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = tmp;
}
/**
 * _add - add the value of all nodes
 * @top: top node
 * @line: value
 */
void _add(stack_t **top, unsigned int line)
{
	int tmp = (*top)->n;
	if (*top == NULL || (*top)->next == NULL)
		printf("cant add");

	(*top)->next->n += tmp;
	_pop(top, line);
}

/**
 * _nop - it does notthing
 * @top: top node
 * @line: value
 */
void _nop(stack_t **top, unsigned int line)
{
	(void) top;
	(void) line;
}
