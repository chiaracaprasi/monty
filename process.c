#include "monty.h"

/**
 * process - breaks up the buffer into tokens and sends for processing
 * @lineBuffer: the buffer containing the line from the bytecode
 * Return: 0 for success, -1 for any error
 */
int process(char *lineBuffer)
{
	char *token;
	char *hold_opCode = NULL;

	token = strtok(lineBuffer, " ");
	printf("the first token is %s\n", token);

	if (strcmp(token, "push") == 0)
	{
		hold_opCode = token;
		token = strtok(NULL, " ");
		access.pushArg = atoi(token);
		if (access.pushArg == 0 && !strcmp(token, "0"))
		{
			printf("printing error here");
			return (-1);
		}
	}

	if (hold_opCode != NULL)
		get_func(hold_opCode);
	else
		get_func(token);

	return (0);
}

int get_func(char *opCode)
{
	int idx = 0;
	instruction_t selector[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op}
	};

	while (selector[idx] != NULL)
	{
		if (opCode == selector[idx].opcode)
		{
			selector[idx].f(access.head, access.lineNum);
			return (0);
		}
		idx++;
	}
	printf("error here");
	return (0);
}
