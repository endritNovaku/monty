#include "monty.h"
int val;
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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
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
/**
 * open_and_read - ppen and read the file
 * @argv: argv
 */
void open_and_read(char **argv)
{
	void (*p_func)(stack_t **, unsigned int);
	FILE *fp;
	char *buf = NULL, *token = NULL, command[1024];
	size_t len = 0;
	ssize_t line_size;
	unsigned int line_counter = 1;
	stack_t *top = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		file_error(argv);
	while((line_size = getline(&buf, &len, fp)) != -1)
	{
		token = strtok(buf, "\n\t\r ");
		if (*token == '\0')
			continue;
		strcpy(command, token);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			if (token == NULL)
				printf("error");
			val = atoi(token);
			p_func = get_op_code(command, line_counter);
			p_func(&top, line_counter);
		}
		else
		{
			p_func = get_op_code(token, line_counter);
			p_func(&top, line_counter);
		}
		line_counter++;
	}
	fclose(fp);
	if (buf != NULL)
		free(buf);
	_free(top);
}
