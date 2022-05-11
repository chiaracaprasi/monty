#include "monty.h"

global_t g_data = {NULL, 0, 0, NULL, NULL};

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
	stack_t *head = NULL;

	if (argc != 2)
		error_handler(1, NULL);

	montyFile = fopen(argv[1], "r");

	if (montyFile == NULL)
	{
		dprintf(STDERR_FILENO, OPEN_ERR, argv[1]);
		exit(EXIT_FAILURE);
	}

	g_data.head = &head;
	g_data.montyFile = montyFile;
	g_data.buffer = &montyLine;

	while (get_monty(&montyLine, &len, montyFile) != -1)
	{
		g_data.lineNum++;
		tokenise(montyLine);
	}

	fclose(montyFile);
	free(montyLine);
	free_stack();
	return (0);
}
