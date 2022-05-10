#include "monty.h"

/**
 * process - breaks up the buffer into tokens and sends for processing
 * @lineBuffer: a buffer containing the line from bytecode file
 * Return: 0 for success, -1 for any error
 */
int tokenise(char *lineBuffer)
{
	char *token;

	token = strtok(lineBuffer, " ");

	if (strcmp(token, "#") == 0)
	{
		printf("found a comment\n");
		return (0);
	}

	if (strcmp(token, "stack") == 0)
		access.mode = 0;
	printf("mode int is %d\n");

	if (strcmp(token, "queue") == 0)
		access.mode = 1;
	printf("mode int is %d\n");

	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " ");

		if (token == NULL ||( atoi(token) == 0 && strcmp(token, "0") != 0))
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
int stack_builder(int n)
{
	stack_t *new;

	if (access.mode == 0)
		new = push_node();
	else
		new = enqueue_node();

	if (new == NULL)
		return (-1);

	new->n = n;

	return (0);
}

stack_t *push_node()
{
	stack_t **head = access.head;
	stack_t *new;

	new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		return (new);
	}

	if ((*head)->next == NULL)
	{
		new->prev = *head;
		new->next = *head;
		(*head)->prev = new;
		(*head) = new;
		return (new);
	}

	new->prev = (*head)->prev;
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return (new);
}

stack_t *enqueue_node()
{
	stack_t **head = access.head;
	stack_t *new;

	new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		return (new);
	}

	if ((*head)->next == NULL)
	{
		new->prev = *head;
		new->next = NULL;
		(*head)->prev = new;
		(*head)->next = new;
		return (new);
	}

	new->prev = (*head)->prev;
	new->next = NULL;
	new->prev->next = new;
	(*head)->prev = new;
	return (new);
}
