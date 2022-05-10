#include "monty.h"
#include "lists.h"


/**
 * push_op - pushes an element to the stack
 * @stack: pointer to pointer to first node in list
 * @line_number: number of line
 * Return: void
 */

void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t **new = malloc(sizeof(stack_t_));
	int num = atoi(opcode[1]);

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit (EXIT_FAILURE);
	}

	/* is this argv or opcode*/
	if (opcode[1] == NULL)
	{
		dprintf(STDERR_FILENO, "L<%u>: usage: push integer\n", line_number);
		/*do we need to free here? */
		free(new);
		exit (EXIT_FAILURE);
	}

	new = add_dnodeint(stack, num);
	/* we could add a flag mode to add node at the start or end depending if it's stack or queue*/
}
