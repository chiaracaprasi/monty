#include "monty.h"

/**
 * pop_op - remove the first node in a stack_t doubly linked list
 * @stack: a pointer to the head of the list
 * @line_number: file line number opcode received from
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *hold;

	if (*stack == NULL)
	{
		/* call error handler */
		printf("stack is empty, send %d\n", line_number);
		free_stack();
		free(g_data.buffer);
		fclose(g_data.montyFile);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}

	*stack = (*stack)->next;
	hold = (*stack)->prev;
	(*stack)->prev = hold->prev;
	free(hold);
}
