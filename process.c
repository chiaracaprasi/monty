#include "monty.h"

/**
 * get_monty - reads a line from a given file stream
 * @buffer: the buffer in  which to store the line
 * @read: a ptr to int to be updated with # of bytes read
 * @file: the file to be read
 * Return: -1 if EOF reached, 0 otherwise
 */
int get_monty(char **buffer, size_t *read, FILE *file)
{
	int read_check;
	char *changeBuff;

	read_check = getline(buffer, read, file);

	if (read_check == -1 && feof(g_data.montyFile) == 0)
		error_handler(2, NULL);

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
 * Return: Nothing
 */
void tokenise(char *lineBuffer)
{
	char *token;

	token = strtok(lineBuffer, " \t\r");

	if (token_check(token) == 0)
		return;

	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \t\r");

		if (token == NULL)
			error_handler(4, NULL);

		if (atoi(token) == 0 && *token != '0')
			error_handler(4, NULL);

		stack_builder(atoi(token));
		return;
	}

	get_func(token);
}

/**
 * token_check - checks the string at token for a range of values
 * @token: the string to be checked
 * Return: 0 if match found, 1 if not
 */
int token_check(char *token)
{
	if (token == NULL || *token == '#')
		return (0);

	if (strcmp(token, "nop") == 0)
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

	return (1);
}

/**
 * get_func - an array of instructin_t's allowing opcode function call
 * @opCode: a string containing the opcode to be executed
 * Return: Nothing
 */
void get_func(char *opCode)
{
	int idx = 0;
	instruction_t selector[] = {
		{"pint", pint_op},
		{"pall", pall_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{NULL, NULL}
	};

	while (selector[idx].opcode != NULL)
	{
		if (strcmp(opCode, selector[idx].opcode) == 0)
		{
			selector[idx].f(g_data.head, g_data.lineNum);
			return;
		}
		idx++;
	}

	error_handler(3, opCode);
}
