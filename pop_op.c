#include "monty.h"

/**
 * pop_op - remove the first node in a stack_t doubly linked list
 * @stack: a pointer to the head of the list
 * @line_number: file line number opcode received from
 * Return: Nothing
 */
void pop_op(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	if (*stack == NULL)
		error_handler(6, NULL);

	if ((*stack)->next == NULL)
	{
		free((*stack));
		*stack = NULL;
		return;
	}

	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
