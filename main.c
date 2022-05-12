#include "monty.h"
int val;
int main(int argc, char **argv)
{

	if (argc != 2)
		usage_error();
	open_and_read(argv);
	return(0);
}
