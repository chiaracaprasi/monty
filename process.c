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

	read_check = getline(buffer, read, file);

	if (read_check == -1)
		return (-1);

	changeBuff = *buffer;

	if (changeBuff[read_check - 1] == '\n')
		changeBuff[read_check - 1] = '\0';

	return (0);
}

/**
 * tokenise - breaks up the buffer into tokens and sends for processing
 * @lineBuffer: a buffer containing the line from bytecode file
 * Return: 0 for success, -1 for any error
 */
int tokenise(char *lineBuffer)
{
	char *token;

	token = strtok(lineBuffer, " ");

	if (*token == '#')
		return (0);

	if (strcmp(token, "stack") == 0)
	{
		g_data.mode = 0;
		return (0);
	}
	if (strcmp(token, "queue") == 0)
	{
		g_data.mode = 1;
		return (0);
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
	return (get_func(token));
}

/**
 * get_func - an array of instructin_t's allowing opcode function call
 * @opCode: a string containing the opcode to be executed
 * Return: 0 for success, -1 for opcode not found
 */
int get_func(char *opCode)
{
	int idx = 0;
	instruction_t selector[] = {
		{"pint", pint_op},
		{"pall", pall_op},
		{NULL, NULL}
	};

	while (selector[idx].opcode != NULL)
	{
		if (strcmp(opCode, selector[idx].opcode) == 0)
		{
			selector[idx].f(g_data.head, g_data.lineNum);
			return (0);
		}
		idx++;
	}
	printf("printing error for bad opcode");
	return (-1);
}
