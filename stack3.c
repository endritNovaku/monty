#include "monty.h"
/**
 * _sub - subtract the value of all nodes
 * @top: top node
 * @line: value
 */
void _sub(stack_t **top, unsigned int line)
{
        stack_t *tmp;
        if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	tmp = (*top)->next;
        tmp->n -= (*top)->n;
        _pop(top, line);
}
/**
 * _div - divide the value of all nodes
 * @top: top node
 * @line: value
 */
void _div(stack_t **top, unsigned int line)
{
	stack_t *tmp;

        if (*top == NULL || (*top)->next == NULL)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line);
                exit(EXIT_FAILURE);
        }
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

        tmp = (*top)->next;
        tmp->n /= (*top)->n;
        _pop(top, line);
}
/**
 * _mul - multiply the value of all nodes
 * @top: top node
 * @line: value
 */
void _mul(stack_t **top, unsigned int line)
{
	stack_t *tmp;
        if (*top == NULL || (*top)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n", line);
                exit(EXIT_FAILURE);
        }

        tmp = (*top)->next;
        tmp->n *= (*top)->n;
        _pop(top, line);
}
/**
 * _mod - find modulo the value of all nodes
 * @top: top node
 * @line: value
 */
void _mod(stack_t **top, unsigned int line)
{
        stack_t *tmp;

        if (*top == NULL || (*top)->next == NULL)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", line);
                exit(EXIT_FAILURE);
        }
        if ((*top)->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line);
                exit(EXIT_FAILURE);
        }

        tmp = (*top)->next;
        tmp->n %= (*top)->n;
        _pop(top, line);
}
