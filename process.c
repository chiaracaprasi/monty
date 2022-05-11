#include "monty.h"

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

/**
 * process - breaks up the buffer into tokens and sends for processing
 * @lineBuffer: a buffer containing the line from bytecode file
 * Return: 0 for success, -1 for any error
 */
int tokenise(char *lineBuffer)
{
	char *token;

	token = strtok(lineBuffer, " ");

	if (*token == '#')
	{
		printf("found a comment\n");
		return (0);
	}

	if (strcmp(token, "stack") == 0)
	{
		access.mode = 0;
		printf("mode int is %d\n", access.mode);
	}
	if (strcmp(token, "queue") == 0)
	{
		access.mode = 1;
		printf("mode int is %d\n", access.mode);
	}
	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " ");

		if (token == NULL)
		{
			printf("print error re push arg\n");
			return (-1);
		}
		if (atoi(token) == 0 && *token != '0')
		{
			printf("print error re push arg\n");
			return (-1);
		}
		if (stack_builder(atoi(token)) == -1)
		{
			printf("printing malloc error here");
			return (-1);
		}
		return (0);
	}
	printf("calling get function here\n");
/*	return (get_func(token));*/
	return (0);
}
/*
int get_func(char *opCode)
{
	int idx = 0;
	instruction_t selector[] = {
		{"pall", pall_op},
		{"pint", pint_op},
		{NULL, NULL}
	};

	while (selector[idx].opcode != NULL)
	{
		if (opCode == selector[idx].opcode)
		{
			selector[idx].f(access.head, access.lineNum);
			return (0);
		}
		idx++;
	}
	printf("printing error for bad opcode");
	return (-1);
}
*/
