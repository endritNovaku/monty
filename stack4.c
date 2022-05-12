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

void _pstr(stack_t **top, __attribute__((unused)) unsigned int line)
{
	int s;
	stack_t *tmp;

	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *top;
	while (tmp != NULL)
	{
		s = tmp->n;
		if (s <= 0 || s > 127)
			break;
		putchar(s);
		tmp = tmp->next;
	}
	putchar('\n');
}

void _rotl(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp;
	stack_t *head;
	stack_t *new_head;

	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
			return;
	tmp = *top;
	head = *top;

	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	new_head = (*top)->next;
	head->next = NULL;
	head->prev = tmp;
	tmp->next = head;
	new_head->prev = NULL;
	*top = new_head;
}

void _rotr(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp;
	
	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
			return;
	tmp = *top;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *top;
	(*top)->prev = tmp;
	*top = tmp;
}
