#include "monty.h"
/**
 * _sub - subtract the value of all nodes
 * @top: top node
 * @line: value
 */
void _sub(stack_t **top, unsigned int line)
{
        int tmp = (*top)->n;
        if (*top == NULL || (*top)->next == NULL)
                printf("cant add");

        (*top)->next->n -= tmp;
        _pop(top, line);
}
/**
 * _div - divide the value of all nodes
 * @top: top node
 * @line: value
 */
void _div(stack_t **top, unsigned int line)
{
        int tmp = (*top)->n;
        if (*top == NULL || (*top)->next == NULL)
                printf("cant add");
	if ((*top)->n == 0)
		printf("error");

        (*top)->next->n = (*top)->next->n / tmp;
        _pop(top, line);
}
/**
 * _mul - multiply the value of all nodes
 * @top: top node
 * @line: value
 */
void _mul(stack_t **top, unsigned int line)
{
        int tmp = (*top)->n;
        if (*top == NULL || (*top)->next == NULL)
                printf("error");

        (*top)->next->n *= tmp;
        _pop(top, line);
}
/**
 * _mod - find modulo the value of all nodes
 * @top: top node
 * @line: value
 */
void _mod(stack_t **top, unsigned int line)
{
        int tmp = (*top)->n;
        if (*top == NULL || (*top)->next == NULL)
                printf("cant add");
	if ((*top)->n == 0)
		printf("error");

        (*top)->next->n = (*top)->next->n % tmp;
        _pop(top, line);
}
