#include "monty.h"

global_t access = {NULL, 0, 0};

/**
 * main - a simple bytecode intepreter
 * @argc: the number of arguments passed in at command line
 * @argv: an array of arguments passed in
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	FILE *montyFile;
	char *montyLine = NULL;
	size_t len = 0;
	int read = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	montyFile = fopen(argv[1], "r");
	if (montyFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	access.head = &head;

	if (get_monty(&montyLine, &len, montyFile) == -1)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		free(montyLine);
		fclose(montyFile);
		exit(EXIT_FAILURE);
	}

	while (read != -1)
	{
		access.lineNum++;
		if (tokenise(montyLine) == -1)
			break;
		read = get_monty(&montyLine, &len, montyFile);
	}
	fclose(montyFile);
	free(montyLine);
	free_stack();
	return (0);
}
