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
		printf("bytecode line says: %s", montyLine);
		if (tokenise(montyLine) == -1)
			break;
		read = get_monty(&montyLine, &len, montyFile);
	}

	fclose(montyFile);
	free(montyLine);
	free_stack();
	return (0);
}

/**
 * get_monty - reads a line from a given file stream
 * @buffer: the buffer in  which to store the line
 * @read: a ptr to int to be updated with # of bytes read
 * @file: the file to be read
 * Return: -1 if read failed or EOF reached, 0 otherwise
 */
int get_monty(char **buffer, size_t *read, FILE *file)
{
	int read_check;
	char *changeBuff;

	printf("arrived in getline func\n");
	read_check = getline(buffer, read, file);
	printf("read_check is: %d\n", read_check);
	if (read_check == -1)
		return (-1);
	changeBuff = *buffer;
	printf("The buffer string is: %s", changeBuff);
	printf("The char to be checked is: %c\n", changeBuff[*read - 1]);
	if (changeBuff[*read - 1] == '\n')
		changeBuff[*read - 1] = '\0';

	return (0);
}
