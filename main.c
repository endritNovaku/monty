#include "monty.h"
int val;
int main(int argc, char **argv)
{
	ssize_t line;
	FILE *fp;
	char *buff = NULL, *token = NULL;
	size_t length = 0;
	unsigned int line_counter = 1;
	stack_t *top = NULL;

	if (argc != 2)
		perror("error\n");
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		perror("error\n");

	while ((line = getline(&buff, &length, fp)) != -1)
	{
		token = strtok(buff, "\n\t\r ");

		if (*token == '\0')
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			val = atoi(token);
			_push(&top, line_counter);
		}
		if (strcmp(token, "pall") == 0)
			_pall(&top, line_counter);
		if (strcmp(token, "pint") == 0)
			_pint(&top, line_counter);
		if (strcmp(token, "pop") == 0)
			_pop(&top, line_counter);
		if (strcmp(token, "swap") == 0)
			_swap(&top, line_counter);
		if (strcmp(token, "add") == 0)
			_add(&top, line_counter);
		if (strcmp(token, "nop") == 0)
			_nop(&top, line_counter);
		line_counter++;
	}
	fclose(fp);

	if (buff != NULL)
		free(buff);
	_free(top);
	return(0);
}
