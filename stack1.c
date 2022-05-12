#include "monty.h"
int val;
/**
 * _pall - print all elements of list
 * @top: top of linked list
 * @line: value of the linked list
 */
void _pall(stack_t **top, __attribute__((unused))unsigned int line)
{
	stack_t *tmp = *top;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _pint - print the top element
 * @top: top node
 * @line: value
 */
void _pint(stack_t **top, unsigned int line)
{
	if (*top != NULL)
	{
		printf("%i\n", (*top)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pop - delete the top element
 * @top: top element
 * @line: top value
 */
void _pop(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *top;
	
	if (*top == NULL)
		printf("error\n");

	tmp = tmp->next;
	free(*top);
	*top = tmp;
}
/**
 * _push - add a element at the end of the list
 * @top: the top element
 * @line: value
 */

void _push(stack_t **top, __attribute__((unused))unsigned int line)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n");
	new_node->n = val;
	new_node->prev = NULL;
	if (*top == NULL)
	{
		new_node->next = NULL;
		*top = new_node;
	}
	else
	{
		new_node->next = *top;
		(*top)->prev = new_node;
		*top = new_node;
	}

}
/**
 * _free: free the linked list
 * @top: top node
 * @line: value
 */
void _free(stack_t *top)
{
	stack_t *tmp;

	if (top == NULL)
		return;
	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
	free(top);
}
