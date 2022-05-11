#include "monty.h"

/**
 * pop_op - remove the first node in a stack_t doubly linked list
 * @stack: a pointer to the head of the list
 * @line_number: file line number opcode received from
 * Return: Nothing
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *hold;

	if (*stack == NULL)
		error_handler(6, NULL);

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
